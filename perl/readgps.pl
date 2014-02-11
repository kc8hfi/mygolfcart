#!/usr/bin/perl

use strict;
use warnings;

use IO::Async::Loop;
use IO::Async::Stream;
use IO::Termios;

open my $thefile, ">>logs/readgps_coordinates.txt" or die "cannot open file! $!\n";
print $thefile "begin here\n\n";
$thefile->autoflush(1);

my $loop = IO::Async::Loop->new;
 
my $ttyS0 = IO::Termios->open( "/dev/ttyUSB0","57600,8,n,1"); 
my $stream = IO::Async::Stream->new( 
     read_handle => $ttyS0,
     write_handle => $thefile,
      on_read => sub {
       my ( $self, $buffref, $eof ) = @_;

       while( $$buffref =~ s/^(.*\n)// ) {
          print "$1";
          print $thefile $1;
       }

       if( $eof ) {
          print "EOF; last partial line is $$buffref\n";
       }

       return 0;
    }
 );

$loop->add($stream);


$loop->run;

exit;