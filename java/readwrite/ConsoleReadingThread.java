import java.io.BufferedReader;
import java.io.BufferedWriter;

public class ConsoleReadingThread extends Thread
{

     private BufferedReader reader = null;
     private String readerId = "";
     private BufferedWriter mywriter;
     public ConsoleReadingThread(BufferedWriter sw,BufferedReader br,String readerId)
     {
          this.reader = br/* new BufferedReader(new InputStreamReader(System.in))*/;
          this.readerId = readerId;
          this.mywriter = sw;
     }

     public void run()
     {
          System.out.println(readerId + " is ready");
          GetHoldOfTheConsole();
          super.run();
     }

     public void GetHoldOfTheConsole()
     {
          while(true)
          {
               try
               {
                    String getData = reader.readLine();
                    //System.out.println(readerId + " reads:'" + getData+"'");
                    System.out.println("keyboard input:'" + getData + "'");
                    
                    //write the stuff out the serial port
                    mywriter.write(getData);
                    //send a new line character
                    mywriter.newLine();
                    //flush the buffer
                    mywriter.flush();
               }
               catch(Exception ex)
               {
                    System.out.println("Go away!");
               }
          }
     }
}
