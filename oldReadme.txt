mygolfcart
==========

my software to control the golf cart.


arduino - contains all the code that runs on the arduino
     brake - test out the brakes
     compass - read the accelerometer, magnetometer, and heading
     hallpower - reads the hall effect and turning the main power on/off
     libraries - includes the arduino libraries
     move - make the cart move forwards/backwards
     movehall - tests the hall effect sensor with moving the cart fwd/rev
     mygolfcart - main program that controls everything
     serial_echo - program to test reading and writing from the serial port
     serial_read - another test program to read/write from the serial port
     servo - test out the servo that controls the throttle
     steering - make the steering wheel move
     testfwdrev - test forward and reverse
     testmainpower - test turning on and off the main power relay
     
docs - documentation

java -
     server - New server code to interface between the client and the arduino. 

legacy java - 
     arduinoreadwrite - 
     filechange - 
     GPSRead - 
     readwrite - 
     
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
     server.pl - the server program, another main program that handles everything
     startprogram.pl - this is the main program!

qt - 
     remotecontrol - 
     
perl stuff
need to have installed
perl-Future
perl-IO-Termios
perl-IO-Async
perl-Moose
perl-Text-CSV
perl-Data-Dumper

