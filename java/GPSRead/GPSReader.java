import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;

import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;

import java.io.OutputStream;
import java.io.OutputStreamWriter;

/*
 * on a fedora box, and possibly any other linux distro,  you're going to need to make some 
 * symlinks to point to the actual serial port.
 * The mega2560 shows up as a /dev/ttyACM0 device, but the RXTX library doesn't pick up
 * ttyACM devices - it only deals with ttyS devices.
 * So, make a symlink to /dev/ttyACM0, or whatever number the computer assigned it.  
 * 
 * ln -s /dev/ttyACM0 /dev/ttyS10
 * 
 * of course, replace the ttyACM0 with whatever your arduino is,
 * and replace ttyS10 with whatever number is not already in /dev
 * 
 * 
 * to compile:
 * javac -cp /usr/share/java/RXTXcomm.jar:. *.java
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

public class GPSReader 
{

     //private OutputStream out;
     
//      public OutputStream getTheStream()
//      {
//           return out;
//      }
     
     public GPSReader() 
     {
          super();
     }

     void connect (String portName) throws Exception 
     {
          CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier(portName);
          if ( portIdentifier.isCurrentlyOwned() )
          {
               System.out.println("Error: Port is currently in use");
          } 
          else 
          {
               CommPort commPort = portIdentifier.open(this.getClass().getName(),2000);
               if ( commPort instanceof SerialPort ) 
               {
                    SerialPort serialPort = (SerialPort) commPort;
                    serialPort.setSerialPortParams(57600,SerialPort.DATABITS_8,SerialPort.STOPBITS_1,SerialPort.FLOWCONTROL_NONE);

                    InputStream in = serialPort.getInputStream();
                    //out = serialPort.getOutputStream();
                    (new Thread(new SerialReader(in))).start();
                    //(new Thread(new SerialWriter(out))).start();

               } 
               else
               {
                    System.out.println("Error: Only serial ports are handled by this example.");
               }
          }     
     }


/** */
public class SerialReader implements Runnable 
{
     InputStream in;
     BufferedReader reader; 

     public SerialReader ( InputStream in)
     {
          this.in = in;
          this.reader = new BufferedReader(new InputStreamReader(in));
     }

     public void run ()
     {
          String line = null;
          try
          {
               while ((line = reader.readLine()) != null) 
               {
                    String findme = "GPRMC";
                    if (line.toLowerCase().contains(findme.toLowerCase()))
                    {
                        System.out.println("Read line with " + line.length() + " characters: \"" + line + "\"");
                    }
               }
          }
          catch ( IOException e )
          {
               e.printStackTrace();
          }            
     }
}

// public class SerialWriter implements Runnable
// {
//      OutputStream out;
//      public SerialWriter ( OutputStream out) 
//      {
//           this.out = out;
//      }         
//      public void run()
//      {
//           try
//           {
//                out.write(42);
//                out.flush();
//                System.out.println("serialwriter run");
//           }
//           catch(IOException e)
//           {
//                e.printStackTrace();
//           }
//      }
// }

public static void main(String[] args)
{
     BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
     String input = "";
     try 
     {
          GPSReader mytester = new GPSReader();
          mytester.connect("/dev/ttyUSB0");
          //OutputStream mystream = mytester.getTheStream();
          
          //BufferedWriter mywriter = new BufferedWriter(new OutputStreamWriter(mystream));
          
          ConsoleReadingThread consoleReader1 = new ConsoleReadingThread(/*mywriter,*/reader,"Reader One:");
          consoleReader1.start();
          System.out.println("gps is ready");
     }
     catch ( Exception e )
     {
          e.printStackTrace();
     }
}

}

 
