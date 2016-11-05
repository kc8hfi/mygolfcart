#!/usr/bin/perl

#before this scripts gets run,  the terminal port needs to be configured first
#run this command:
#stty -F /dev/ttyACM0 -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke
#and then start this script.  

use strict;
use warnings;

use IO::Async::Listener;
use IO::Async::Loop;
use IO::Async::Stream;
use IO::Async::Timer::Periodic;
use IO::Termios;

#make stdout unbuffered
$| = 1; 

my $port = "4201";

sub log_time
{
     my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)=localtime(time);
     my $nice_timestamp = sprintf ( "%04d-%02d-%02d %02d:%02d:%02d",
                                   $year+1900,$mon+1,$mday,$hour,$min,$sec);
     return $nice_timestamp;
}

my $logfile = "logs/server.log";

sub write_log
{
     my ($want_timestamp,$string) = @_;
     open LOGFILE, ">>$logfile" or die "cannot create log file! $! \n";
     if ($want_timestamp == 1)
     {
          print log_time(),"\t",$string,"\n";
          print LOGFILE log_time(),"\t",$string,"\n";
     }
     else
     {
          print $string,"\n";
          print LOGFILE $string,"\n";
     }
     close LOGFILE;
}

my $loop = IO::Async::Loop->new;


#connect to the arduino board
#list of devices that i've seen the arduino on
my $device;
my @whichdevice = qw(/dev/ttyACM0 /dev/ttyACM1);
foreach my $d(@whichdevice)
{
     #$device->dtr_active(1);
     
     $device = IO::Termios->open( $d,); 
     if(defined($device))
     {
          $device->set_mode("115200,8,n,1");
          
          #$device->setflag_icanon(0);
          
          #$device->setflag_echo(0);
          
         
# [kc8hfi@bandit1 truck]$ stty -F /dev/ttyACM0
# speed 115200 baud; line = 0;
# -brkint -imaxbel
# [kc8hfi@bandit1 truck]$ stty -F /dev/ttyACM0
# speed 115200 baud; line = 0;
# min = 0; time = 0;
# -brkint -icrnl -imaxbel
# -opost -onlcr
# -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke
# [kc8hfi@bandit1 truck]$ 
          
          #print "device is ok,  use $d\n";
          #not sure if this is gonna fix the initial read
          $device->flush;
          last;
     }
}
#this stream comes from the arduino
my $stream = IO::Async::Stream->new( 
     handle => $device,
     
      on_read => sub 
      {
          my ( $self, $buffref, $eof ) = @_;

          while( $$buffref =~ s/^(.*\n)// ) 
          {
               print "Received from serial port: $1";
               my $line = $1;
          }
          if( $eof ) 
          {
               print "EOF; last partial line is $$buffref\n";
          }
       return 0;
     }
);

$loop->add($stream);

#timer to ping the arduino every few seconds
# my $timer = IO::Async::Timer::Periodic->new(
#      interval => 5,      #how many seconds
#      on_tick => sub 
#      {
#           if (defined($stream->write_handle))
#           {         
#                $stream->write("ping\n");
#           }
#      },
# );
# $timer->start;
# $loop->add( $timer );

#listen on the network for a connection to come in
my $listener = IO::Async::Listener->new
(
     on_stream => sub
     {
          my $self = shift;
          my ( $networkstream ) = @_;
          
          my $socket = $networkstream->read_handle;
          my $peeraddr = $socket->peerhost . ":" . $socket->peerport;
          
          write_log(1,"connection from $peeraddr");
          $networkstream->configure
          (
               on_read => sub
               {
                    my ($self,$buffref,$eof) = @_;
                    # s/^(.*\n)// 
                    # this means any number of characters and any number of \n's 
                    # at the beginning of the string
                    #basically, gets the first line of stuff
                    while( $$buffref =~ s/^(.*\n)// )
                    {
                         #eat a line from the stream input
                         $self->write($1);   #$1 is the captured part of that regex in the loop
                         my $cmd = $1;
                         $cmd =~ s/[\r\n]+//;
                         write_log(1,"cmd: $cmd");
                         if (defined($stream->write_handle))
                         {
                              $stream->write("$cmd\n");
                         }
                    }
                    return 0;
               },
               on_closed => sub
               {
                    write_log(1,"connection from $peeraddr closed");
               },
          );
          $loop->add($networkstream);
     },
);

$loop->add($listener);

$listener->listen
(
     addr => 
     { 
          #ip        =>   $host,
          port      =>   $port,
          family    =>   "inet",
          socktype  =>   "stream",
     },
     on_listen =>   sub
     {    
          write_log(0,"Server Ready");
          #write_log(0,"ip:\t$host");
          write_log(0,"port:\t$port");
          
     },
     on_resolve_error => sub { die "Cannot resolve - $_[0]\n"; },
     on_listen_error  => sub { die "Cannot listen\n"; }, 
);



#read keyboard input here, and then send it to the arduino board
my $userstream = IO::Async::Stream->new(
     read_handle => \*STDIN,
     on_read => sub
     {
          my ( $self, $buffref, $eof ) = @_;

          while( $$buffref =~ s/^(.*\n)// ) 
          {
               my $cmd = $1;
               print "Receive: $1";
               #send this command to the arduino
               if (defined($stream->write_handle))
               {
                    $cmd =~ s/[\r\n]+//;
#                     #c get gps coordinates
#                     if ($cmd eq 'c' || $cmd eq 'C')
#                     {
#                          print "coords: \n";
#                          print Dumper($gps_coords);
#                          #print $ { $gps_coords->row }[3],"\n";  #latitude
#                          #print $ { $gps_coords->row }[5],"\n";  #longitude
#                          
#                          #print Dumper($accelerometer);
#                          #print Dumper($compass);
#                     }
#                     elsif($cmd eq 's' || $cmd eq 'S')
#                     {
#                          print $logfile Helper::log_time," ",Dumper($gps_coords);
#                          print $logfile Helper::log_time," ",Dumper($accelerometer);
#                          print $logfile Helper::log_time," ",Dumper($compass);
#                     }
#                     else
#                     {
#                          $stream->write("$cmd\n");
#                     }
                    $stream->write("$cmd\n");
               }
               #print "new command? ";
          }

          if( $eof ) 
          {
               print "EOF; last partial line is $$buffref\n";
          }

          return 0;
     }
);
$loop->add($userstream);


$loop->run;

exit;
