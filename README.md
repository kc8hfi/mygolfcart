WVUIT golfCart Project
===================


This is the primary control software for the WVUIT golfCart Project. 

----------
###Change Log
- Restructured the repository
- Separated new code from working code
- Dev 
	- refactored brake code ( currently untested )
	
----------

Requirements 
:	Perl
		>perl-Future
		>perl-IO-Termios
		>perl-IO-Async
		>perl-Moose
		>perl-Text-CSV
		>perl-Data-Dumper
:	Arduino
		>Arduino v1.6.7
:	QT
		>QSerialPort


Documentation
----  

###Dev 
| Category	| Component	| Description						|
| --------------| --------------| ----------------------------------------------------- |
|golfCart	|		| 							|
|		| golfCart	| main program for the golfCart 			|
|testModules	| 		| 							|
|           	| brake 	| Tests the Brake system sub-component.			|
|java		|		|							|
|		| server	| Main java application for the server			|
|		| sharedData 	| Common data object					|
|		| networkWrite 	| Sends data via network socket to connected client	|
|		| networkRead 	| Reads Data via network socket from connected client	|
|		| arduinoWrite 	| Sends data via serial port to arduino			|
|		| arduinoRead 	| Reads data via serial port from arduino		|
|		| debugLogger 	| Loggs all server program activity			|
|		| jssc-2.8.0 	| JSSC serial port library for serial communication. 	|


###Current
| Category	| Component	| Description						|
| --------------| --------------| ----------------------------------------------------- |
|arduino	|		| 							|
|		| brake 	| brake module test					|
|		| compass 	| read the accelerometer, magnetometer, and heading	|
|		| hallpower 	| reads the hall effect and turning the main power on/off|
|		| libraries 	| includes the arduino libraries			|
|		| move 		| make the cart move forwards/backwards			|
|		|  movehall 	| tests the hall effect sensor with moving the cart fwd/rev|
|		| mygolfcart 	| main program that controls everything			|
|		| serial_echo 	| program to test reading and writing from the serial port|
|		| serial_read 	| another test program to read/write from the serial port|
|		| servo 	| test out the servo that controls the throttle		|
|		| steering 	| make the steering wheel move				|
|		| testfwdrev 	| test forward and reverse				|
|		| testmainpower | test turning on and off the main power relay		|
|java		|		|							|
|		| readwrite 	| Primary Communication program				|
|		| arduinoreadwrite | Arduino Communication				|
|		| GPSRead 	| GPS Communication					|
|		| networkRead 	| Networking communication				|
|		| filechange 	| No Description					|
|perl		|		|							|
|		| logs 		| where everything gets logged to			|
|		| Accelerometer.pm | object for the accelerometer x,y,z values		|
|		| Compass.pm 	| object for magnetometer x,y,z and heading values	|
|		| echo.pl 	| echos back what the arduino sends			|
|		|  Gps.pm 	| helper functions to parse the nmea strings		|
|		| GpsRow.pm 	| object for an nmea string				|
|		| Helper.pm 	| helper functions for the main program			|
|		| packagetest.pl | script to test the packages				|
|		| readgps.pl 	| read the coords from the gps				|
|		| server.pl 	| the server program, another main program that handles everything|
|		| startprogram.pl | this is the main program!				|
|docs		| 		| 							|
|           	| Documentation	| General Documentation and diagrams			|
|qt 		|		|							|
|		|remotecontrol 	| GUI client for remote-controlling golfCart		| 
     

