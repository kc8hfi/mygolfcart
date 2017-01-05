import java.io.OutputStream;
import java.io.IOException;

public class ArduinoWriterThread implements Runnable
{
     OutputStream out;
     public ArduinoWriterThread ( OutputStream out) 
     {
          this.out = out;
     }         
     public void run()
     {
          try
          {
               out.flush();
               System.out.println("serialwriter is running");
          }
          catch(IOException e)
          {
               e.printStackTrace();
          }
     }
}