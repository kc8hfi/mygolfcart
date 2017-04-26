
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;


public class networkWrite 
{    
	private PrintWriter send;
	private debugLogger myLogger;
	
    public networkWrite(Socket temp,debugLogger tempLog)
    {
    	myLogger = tempLog;
    	try 
    	{
			send = new PrintWriter(temp.getOutputStream(),true);
		} 
    	catch (IOException e) 
    	{
            myLogger.writeLog("ERROR: Failure to write to network socket!");
            myLogger.writeLog("\n\n");
            e.printStackTrace();
            myLogger.writeLog("\n\n");
		}
    }
    
    public void writeToSocket(String temp)
    {
    		temp = temp.trim();
            send.println(temp);
            myLogger.writeLog("Network Send: \t\t"+temp);
    }
}
