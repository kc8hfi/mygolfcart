import java.util.*;
import java.io.*;

public  class filewatcher extends TimerTask
{
     private File file;
     private long timestamp;
     private DoWork worker;

     public filewatcher(File f, DoWork w)
     {
          file = f;
          timestamp = file.lastModified();
          worker = w;
     }
     
     public void run()
     {
          long ts = file.lastModified();
          if(timestamp != ts)
          {
               timestamp = ts;
               //since the file has changed, go do something with it now!!
               worker.doit();
          }
     }//end run
}//end filewatcher