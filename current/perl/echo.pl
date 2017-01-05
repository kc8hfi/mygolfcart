#!/usr/bin/perl

use strict;
use warnings;

use IO::Async::Loop;
use IO::Async::Stream;
use IO::Async::Timer::Periodic;
use IO::Termios;
use Data::Dumper;


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
          #$device->flush;
          last;
     }
}
#this stream comes from the arduino
my $stream = IO::Async::Stream->new( 
     handle => $device,
     
      on_read => sub 
      {
          #print Dumper(@_);
          my ( $self, $buffref, $eof ) = @_;

          while( $$buffref =~ s/^(.*\n)// ) 
          {
               print "Receive: $1";
          }
          if( $eof ) 
          {
               print "EOF; last partial line is $$buffref\n";
          }
          #print "in buffref:$$buffref";
       return 0;
     },
     autoflush => 1,
     #on_flush => sub {}
);

$loop->add($stream);


# #timer to ping the arduino every few seconds
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

my $status_timer = IO::Async::Timer::Periodic->new(
     interval => 2,      #how many seconds
     on_tick => sub 
     {
          if (defined($stream->write_handle))
          {         
               #$stream->write("a\n");
               #$stream->write("b\n");
               
               $stream->write("status\n");
               #$stream->write("b\n");
               
               #$stream->write("something\n");

               #print $logfile Helper::log_time," ",Dumper($gps_coords);
               #print $logfile Helper::log_time," ",Dumper($accelerometer);
               #print $logfile Helper::log_time," ",Dumper($compass);
          }
     },
);
$status_timer->start;
$loop->add( $status_timer );



$loop->run;


exit;
