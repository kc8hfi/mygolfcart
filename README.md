mygolfcart
==========

my software to control the golf cart.


arduino - contains all the code that runs on the arduino
     brake - test out the brakes
     compass - read the accelerometer, magnetometer, and heading
     halleffect - the wheel sensor for distance
     move - make the cart move forwards/backwards
     steering - make the steering wheel move
     
perl - all the perl scripts
     logs - where everything gets logged to
     Accelerometer.pm - object for the accelerometer x,y,z values
     Compass.pm - object for magnetometer x,y,z and heading values
     echo.pl - echos back what the arduino sends
     Gps.pm - helper functions to parse the nmea strings
     GpsRow.pm - object for an nmea string
     Helper.pm - helper functions for the main program
     packagetest.pl - script to test the packages
     readgps.pl - read the coords from the gps
     startprogram.pl - this is the main program!


perl stuff
need to have installed
perl-Future-0.33
perl-IO-Termios-0.05
perl-IO-Async-0.70
perl-Moose
perl-Text-CSV
perl-Data-Dumper

