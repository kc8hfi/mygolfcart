 

import java.net.*;
import java.io.*;

public class KKMultiServerThread extends Thread {
    private Socket socket = null;
    
    private GolfCartStatus status;
    private BufferedWriter arduinoWriter;
    

    public KKMultiServerThread(Socket socket,BufferedWriter a, GolfCartStatus s) 
    {
        super("KKMultiServerThread");
        this.socket = socket;
        status = s;
        arduinoWriter = a;
    }
    
    public void run()
    {

          try (
               PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
               BufferedReader in = new BufferedReader(
               new InputStreamReader(
               socket.getInputStream()));
          )
          {
               //start the event timer
               mytimer t = new mytimer(out,in,status,1); //how many seconds

            String inputLine, outputLine;
//             KnockKnockProtocol kkp = new KnockKnockProtocol();
//             outputLine = kkp.processInput(null);
//             out.println(outputLine);
          //out.println("to the client:" + status.getStatus());

            while ((inputLine = in.readLine()) != null) {
            
               System.out.println("from server and sent to arduino: " + inputLine);
               

               //write the stuff out the serial port
               arduinoWriter.write(inputLine);
               //send a new line character
               arduinoWriter.newLine();
               //flush the buffer
               arduinoWriter.flush();
               

//                 outputLine = kkp.processInput(inputLine);
//                 out.println(outputLine);
//                 if (outputLine.equals("Bye"))
//                     break;
               //outputLine = "i got it";
               
            }
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
