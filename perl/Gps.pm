#!/usr/bin/perl

package Gps;

use Moose;
use Text::CSV;
use Data::Dumper;

my $csv = Text::CSV->new({always_quote=>1,binary=>1});

#GGA - global positioning system fixed data
# Name Example   Units     Descrption
# Message ID     $GPGGA         GGA protocol header
# UTC Time  053740.000          hhmmss.sss
# Latitude  2503.6319      ddmm.mmmm
# N/S Indicator  N         N=north, or S=south
# Longitude 12136.0099          dddmm.mmmm
# E/W Indicator  Example        E=east, or W=west
# Position Fix Indicator   12136.0099          see position fix indicator table
# Satellites Used     08        Range 0 to 12
# HDOP 1.1       Horizontal Dilution of Precision
# MSL Altitude   63.8 mters     
# Units     M    mters     
# Geoid Separation    15.2 mters     
# Units     M    mters     
# Age of Diff. Corr.       second    Null fields when DGPS is not used
# Diff. Ref. Station ID    0000      
# Checksum  *64   

sub gga
{
     my $line = shift;
     $csv->parse($line);
     my @fields = $csv->fields();
     #print @fields;
}

#RMC - recommended minimum specific GNSS data
# Name Example   Units     Description
#0 Message Id     $GPRMC         RMC protocol header
#1 UTC Time  053740.000          hhmmss.sss
#2 Status    A         A=data valid, V=data not valid
#3 Latitude  2503.6319      ddmm.mmmm
#4 N/S Indicator  N         N=north or S=south
#5 Longitude 12136.0099          dddmm.mmmm
#6 E/W Indicator  Example        E=east, or W=west
#7 Speed over Ground   2.69 knots     true
#8 Course over Ground  79.65     degrees   
#9 Date 100106         ddmmyy
#10 Magnetic variation       degrees   
#11 Variation Sense               E=east, or W=west,(not shown)
#12 Mode A         A=autonomous, D=DGPS, E=DR
#13 Checksum  *53       
#14 <cr><lf>            end of message termination


sub rmc
{
     my $line = shift;
     $csv->parse($line);
     my @fields = $csv->fields();
     #print "before: $fields[3]\n";
     $fields[3] = latlong_todegree($fields[3]);
     $fields[5] = latlong_todegree($fields[5]);
     #print "after: $fields[3]\n";
     #print Dumper(@fields);
     return @fields;
}


sub latlong_todegree
{
     my $number = shift;
     my $deg;
     my ($dm,$sec) = split(/\./, $number);
     
     if (defined($dm))
     {
          if (length($dm) == 4) 
          {   #Lat (ddmm)
               $deg = substr($dm,0,2,'');
          } 
          elsif (length($dm) == 5) 
          { #Lon (dddmm)
               $deg = substr($dm,0,3,'');
          } 
          else
          {
               print "Invalid coords\n";
          }
          #print "original: $number\n";
          my $minute = "$dm.$sec";
          #print "degree: $deg\n";
          #print "minute: $minute\n";
          $deg = $deg + $minute/60;
          #print "convert: $deg\n";
     }
     return $deg;
}

1;