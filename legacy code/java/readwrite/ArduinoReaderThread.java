import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;


public class ArduinoReaderThread implements Runnable 
{
     private InputStream in;
     private BufferedReader reader; 
     private GolfCartStatus status;

     public ArduinoReaderThread ( InputStream in, GolfCartStatus s)
     {
          status = s;
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
                    System.out.println("incoming " + line.length() + " characters: \"" + line + "\"");
                    status.setIncoming(line);
               }
          }
          catch ( IOException e )
          {
               e.printStackTrace();
          }            
     }
}