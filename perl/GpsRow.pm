#!/usr/bin/perl

package GpsRow;

use Moose;

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


has 'row' =>
(
     is   =>   'rw',
     isa  =>   'ArrayRef',
);


1;