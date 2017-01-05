#!/usr/bin/perl

use strict;
use warnings;

use IO::Async::Loop;
use IO::Async::Stream;
use IO::Async::Timer::Periodic;
use IO::Termios;
use Data::Dumper;

use Gps;
use GpsRow;
#use Accelerometer;
#use Compass;
use Helper;


#if you get 
#   'Can't locate object method "run" via package "IO::Async::Loop::Poll"'
#check versions:
#1.  perl-IO-Async,  should be at least 0.60
#2.  perl-Future 0.18

#add user to these groups
#1.  lock
#2.  dialout

#before this scripts gets run,  the terminal port needs to be configured first
#run this command:
#stty -F /dev/ttyACM0 -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke
#and then start this script.  



#file to write the gps coordinates
open my $thefile, ">>logs/raw_coordinates.txt" or die "cannot open logs/raw_coordinates.txt file! $!\n";
print $thefile "begin here\n\n";
$thefile->autoflush(1);

#file to write logging info
open my $logfile, ">>logs/thelog.txt" or die "cannot open logs/thelog.txt file! $!\n";
print $logfile "begin here\n\n";
$logfile->autoflush(1);

#holds the gps coordinates
my $gps_coords;

#holds the accelerometer data, not needed now that we got the heading
#my $accelerometer = Accelerometer->new();

#holds the compass data, not needed now that we got the heading
#my $compass = Compass->new();

#holds just he heading
my $heading = "";

my $loop = IO::Async::Loop->new;

#connect to the arduino board
#list of devices that i've seen the arduino on
my $device;
my @whichdevice = qw(/dev/ttyACM0 /dev/ttyACM1);
foreach my $d(@whichdevice)
{
     $device = IO::Termios->open( $d,"115200,8,n,1"); 
     if(defined($device))
     {
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
              #print $line;
               if($line =~ /Status/)
               {
                    $line =~ tr/[\r\n]//d;
                    my @fields = split(',',$line);
                    $heading = $fields[1];
               }
#                else
#                {
#                     print $line;
#                }
          }
          if( $eof ) 
          {
               print "EOF; last partial line from serial port is $$buffref\n";
          }
       return 0;
     }
     #on_flush => sub {}
);

$loop->add($stream);


#timer to ping the arduino every few seconds
my $timer = IO::Async::Timer::Periodic->new(
     interval => 5,      #how many seconds
     on_tick => sub 
     {
          if (defined($stream->write_handle))
          {         
               $stream->write("ping\n");
          }
     },
);
$timer->start;
$loop->add( $timer );

#timer to get the status of everything and write it to the log file
my $status_timer = IO::Async::Timer::Periodic->new(
     interval => 2,      #how many seconds
     on_tick => sub 
     {
          if (defined($stream->write_handle))
          {         
               $stream->write("status\n");
#                print $logfile Helper::log_time," ",Dumper($accelerometer);
#                print $logfile Helper::log_time," ",Dumper($compass);
               
               print $logfile Helper::log_time," ",Dumper($heading);
               
               #print $logfile Helper::log_time," ",Dumper($gps_coords);
               
               #this might be where we should do calculations with gps, compass, distance, etc
          }
     },
);
$status_timer->start;
$loop->add( $status_timer );


#connect to the gps here
my $gps_device;
@whichdevice = qw(/dev/ttyUSB0 /dev/ttyUSB1);
foreach my $d(@whichdevice)
{
     $gps_device = IO::Termios->open( $d,"57600,8,n,1"); 
     if(defined($gps_device))
     {
          last;
     }
}
#this stream reads from the gps
my $gps_stream = IO::Async::Stream->new( 
     read_handle => $gps_device,
     write_handle => $thefile,
          on_read => sub {
          my ( $self, $buffref, $eof ) = @_;

          while( $$buffref =~ s/^(.*\n)// ) 
          {
               #print "$1";
               #don't write the coordinates to a file right now
               #print $thefile $1;
               
               my $line = $1;
               if ($line =~ /RMC/)
               {
                    my @t = Gps::rmc( $line );
                    my $ref = \@t;
                    $gps_coords = GpsRow->new(
                         row => $ref
                    );  
                    #print Dumper($gps_coords);
                    #print "its an rmc\n";
               }
#                if ($line =~ /GGA/)
#                {
#                     my @t = Gps::gga($line);
#                     my $ref = \@t;
#                     $gps_coords = GpsRow->new(
#                          row => $ref
#                     );
#                }
          }
          if( $eof ) 
          {
               print "EOF; last partial line from gps is $$buffref\n";
          }
          return 0;
     }
);

$loop->add($gps_stream);

# keyboard commands
# c,C - print gps coords
# h,H - print heading


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
                    #c get gps coordinates
                    if ($cmd eq 'c' || $cmd eq 'C')
                    {
                         print "coords: \n";
                         print Dumper($gps_coords);
                         #print $ { $gps_coords->row }[3],"\n";  #latitude
                         #print $ { $gps_coords->row }[5],"\n";  #longitude
                         
                         #print Dumper($accelerometer);
                         #print Dumper($compass);
                    }
                    elsif($cmd eq 'h' || $cmd eq 'H')
                    {
                         print "heading: ";
                         print Dumper($heading);
                         #print $logfile Helper::log_time," ",Dumper($gps_coords);
#                          print $logfile Helper::log_time," ",Dumper($accelerometer);
#                          print $logfile Helper::log_time," ",Dumper($compass);
                         #print $logfile Helper::log_time," ",Dumper($heading);
                    }
                    else
                    {
                         $stream->write("$cmd\n");
                    }
               }
               #print "new command? ";
          }

          if( $eof ) 
          {
               print "EOF; last partial line from keyboard is $$buffref\n";
          }

          return 0;
     }
);
$loop->add($userstream);





$loop->run;


exit;
