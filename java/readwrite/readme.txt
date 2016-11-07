 
readwrite.java - the main program.  
starts up the console reading thread to read from the keyboard
starts the arduinoreadwrite threads
starts up the timer that looks to see if the file was changed or not

filewatcher.java - this is the thread that looks at the file and tells the DoWork 
object that the file was changed

DoWork.java - this class reads from the file once its changed and does all the work!

cartinfo.java - this is the object that holds the golf cart's status.  The arduino reader 
thread (from arduinoreadwrite object) updates this object when the arduino sends the 
status string

arduinoreadwrite.java - this object starts up 2 threads,  arduinoreaderthread and 
arduinowriterthread.  

arduinoreaderthread.java - thread that reads from the arduino

arduinowriterthread.java - thread that writes to the arduino



/*
 * to compile:
 * javac -cp /usr/share/java/RXTXcomm.jar:. *.java
 * 
 * If your serial port isn't detected when you try to connect to it,  specify it as an 
 * execution parameter.  
 * for example, -Dgnu.io.rxtx.SerialPorts=/dev/ttyACM0:/dev/ttyS8:/dev/<your serial port name here>
 * 
 * to run:
 * java -cp /usr/share/java/RXTXcomm.jar:. -Dgnu.io.rxtx.SerialPorts=/dev/ttyACM0 readwrite
 * 
 * You'll need the RXTX library installed, and then specify
 * the path to the RXTXcomm.jar file.  Depending your linux distro, 
 * it may not be in /usr/share/java
 *
 * inside the arduino directory, there is a project called serial_read.  
 * the arduino reads in stuff on the serial port, then prints it right back
 * out to the serial port.  Use this arduino code to test this java program.
 */
