import java.io.InputStream;
import java.io.OutputStream;
import gnu.io.CommPort;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;


public class ArduinoReadWrite
{
     public ArduinoReadWrite(GolfCartStatus s) 
     {
          super();
          status = s;
     }
     void connect (String portName) throws Exception 
     {
          System.out.println("port name coming in is " + portName);
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
                    serialPort.setSerialPortParams(115200,SerialPort.DATABITS_8,SerialPort.STOPBITS_1,SerialPort.FLOWCONTROL_NONE);

                    InputStream in = serialPort.getInputStream();
                    outputStream = serialPort.getOutputStream();
                    (new Thread(new ArduinoReaderThread(in,status))).start();
                    (new Thread(new ArduinoWriterThread(outputStream))).start();

               } 
               else
               {
                    System.out.println("Error: Only serial ports are handled by this example.");
               }
          }
     }
     
     public OutputStream getTheStream()
     {
          return outputStream;
     }

     private OutputStream outputStream;
     private GolfCartStatus status;
}
