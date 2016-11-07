import java.util.Timer;
import java.util.TimerTask;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

public class mytimer
{
     private Timer timer;
     private BufferedReader reader = null;
     //private BufferedWriter mywriter;
     private PrintWriter mywriter;
     
     private GolfCartStatus status;
     
     public mytimer(PrintWriter sw,BufferedReader br,GolfCartStatus s, int seconds)
     {
          reader = br;
          mywriter = sw;
          
          status = s;
          
          timer = new Timer();

// public void schedule(TimerTask task,long delay,long period)
// task--This is the task to be scheduled.
// delay--This is the delay in milliseconds before task is to be executed.
// period--This is the time in milliseconds between successive task executions.

          timer.schedule(new mytask(), seconds*1000, seconds*1000);
     }

     public class mytask extends TimerTask
     {
          public void run()
          {
               //System.out.println("\t\ttimer fired");
               try
               {
                    //write the stuff out the serial port
                    //mywriter.write("status");
                    //send a new line character
                    //mywriter.newLine();
                    //flush the buffer
                    //mywriter.flush();
                    
                    
                    //send the stuff out the network
                    mywriter.write(status.getStatus());
                    mywriter.flush();
                    
               }
               catch(Exception ex)
               {
                    System.out.println("Go away!");
               }
          }
     }
}//end mytimer class
