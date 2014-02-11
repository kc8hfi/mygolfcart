#!/usr/bin/perl

use strict;
use warnings;

use Data::Dumper;
use Accelerometer;
use Compass;
use Gps;
use GpsRow;

my $accelerometer = Accelerometer->new(
     x_value => 12.5,
     y_value => 13.8,
     z_value => 9.34
);
# print $accelerometer->x_value;
# print $accelerometer->y_value;
# print $accelerometer->z_value;

my $compass = Compass->new(
     x_value => 12.5,
     y_value => 13.8,
     z_value => 9.34,
     heading => 188.09
);
# print $compass->x_value;
# print $compass->y_value;
# print $compass->z_value;
# print $compass->heading;


#open file for testing
open my $file, "<raw_coordinates.txt" or die "cannot open file, $!\n";
while(<$file>)
{
     my $line = $_;
     $line =~ s/[\r\n]+//;
     if ($line =~ /GGA/)
     {
          #print $line."\n";
          Gps::gga($line);
     }
     elsif ($line =~ /RMC/)
     {
          my @t = Gps::rmc($line);
          my $ref = \@t;
          my $r = GpsRow->new(
               row => $ref
          );
          #print Dumper($r->row);
          
#           foreach my $item (@{$r->row})
#           {
#                print $item,"\n";
#                #print $ { $r->row }[0];  #gets a single item
#           }
          #print $ { $r->row }[1],"\n";  #time
          print $ { $r->row }[3],"\n";  #latitude
          
          
          my $deg;
          my ($dm,$sec) = split(/\./, $ { $r->row }[3]);

          if (length($dm) == 4) {   #Lat (ddmm)
          $deg = substr($dm,0,2,'');
          } elsif (length($dm) == 5) { #Lon (dddmm)
          $deg = substr($dm,0,3,'');

          } else {
               print "Invalid coords\n";
          }
          #print "deg: $deg sec: $dm$sec\n";
          print "$deg.$dm$sec\n";
          #$deg = sprintf("%d",$deg);
          #print $ { $r->row }[5],"\n";  #longitude
     }
}
exit;