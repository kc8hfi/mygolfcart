import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.IOException;


public class ArduinoReaderThread implements Runnable 
{
     private InputStream in;
     private BufferedReader reader;
     private cartinfo incoming;

     public ArduinoReaderThread ( InputStream in, cartinfo s)
     {
          this.in = in;
          this.reader = new BufferedReader(new InputStreamReader(in));
          incoming = s;
     }

     public void run ()
     {
          String line = null;
          try
          {
               while ((line = reader.readLine()) != null) 
               {
                    //System.out.println("incoming " + line.length() + " characters: \"" + line + "\"");
                    incoming.setData(line);
               }
          }
          catch ( IOException e )
          {
               e.printStackTrace();
          }            
     }
}