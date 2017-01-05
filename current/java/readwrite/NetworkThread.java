import java.net.*;
import java.io.*;

public class NetworkThread extends Thread
{
     private Socket socket = null;
     
    public NetworkThread(Socket socket) {
        //super("NetworkThread");
        this.socket = socket;
    }
    
    public void run()
    {
        try (
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(
                new InputStreamReader(
                    socket.getInputStream()));
        ) {
            String inputLine, outputLine;
            
          while ( (inputLine = in.readLine()) != null)
          {
               System.out.println("from network:" + inputLine);
          }
          socket.close();
            
//             KnockKnockProtocol kkp = new KnockKnockProtocol();
//             outputLine = kkp.processInput(null);
//             out.println(outputLine);
/*
            while ((inputLine = in.readLine()) != null) {
                outputLine = kkp.processInput(inputLine);
                out.println(outputLine);
                if (outputLine.equals("Bye"))
                    break;
            }*/
//             socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }     
}
