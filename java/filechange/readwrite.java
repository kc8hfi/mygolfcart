import java.util.*;
import java.io.*;

/*
 * to compile:
 * javac -cp /usr/share/java/RXTXcomm.jar:. *.java
 * 
 * If your serial port isn't detected when you try to connect to it,  specify it as an 
 * execution parameter.  
 * for example, -Dgnu.io.rxtx.SerialPorts=/dev/ttyACM0:/dev/ttyS8:/dev/<your serial port name here>
 * 
 * to run:
 * java -cp /usr/share/java/RXTXcomm.jar:. -Dgnu.io.rxtx.SerialPorts=/dev/ttyACM0    readwrite
 * 
 * You'll need the RXTX library installed, and then specify
 * the path to the RXTXcomm.jar file.  Depending your linux distro, 
 * it may not be in /usr/share/java
 *
 * inside the arduino directory, there is a project called serial_read.  
 * the arduino reads in stuff on the serial port, then prints it right back
 * out to the serial port.  Use this arduino code to test this java program.
 */

public class readwrite 
{
     public static void main(String[] args)
     {
          BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
          
          String port = "/dev/ttyACM0";
          //port = "/dev/tty.usbmodem1411";
          String consoleReaderName = "Reader";
          
          /* change this and put the full path to the file!!
           * /var/www/mainsite/data/comFile.txt  i believe is the name of the file
           * 
           * that the web page writes what command to execute.  
           * the web page backend should be changed so that the remote and script radio
           * buttons writes to this same file.  This program can handle both remote and script
           * now.
           */
          
          String comfile = "testfile.txt";
          File thefile = new File(comfile);
          
          cartinfo info = new cartinfo();
          
          try 
          {
               ArduinoReadWrite arduino = new ArduinoReadWrite(info);
               arduino.connect(port);
               OutputStream arduinoStream = arduino.getTheStream();
               
               BufferedWriter mywriter = new BufferedWriter(new OutputStreamWriter(arduinoStream));
               
               ConsoleReadingThread consoleReader1 = new ConsoleReadingThread(mywriter,reader,consoleReaderName);
               consoleReader1.start();
               System.out.println("port: " + port + " ready");
               
               //create an object that actually reads the file and then does the work
               DoWork processcommands = new DoWork(thefile, mywriter, info);

               //monitor the file
          
               TimerTask t = new filewatcher(thefile,processcommands);

               Timer thetimer = new Timer();
               thetimer.schedule(t,new Date(),1000);
          }
          catch ( Exception e )
          {
               e.printStackTrace();
          }
     }//end main
}//end readwrite