import java.util.Timer;
import java.util.TimerTask;
import java.io.BufferedReader;
import java.io.BufferedWriter;

public class mytimer
{
     private Timer timer;
     private BufferedReader reader = null;
     private BufferedWriter mywriter;
     
     public mytimer(BufferedWriter sw,BufferedReader br,int seconds)
     {
          reader = br;
          mywriter = sw;
          
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
               System.out.println("timer fired");
               try
               {
                    //write the stuff out the serial port
                    mywriter.write("status");
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
}//end mytimer class