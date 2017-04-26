import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;


public class networkRead implements Runnable
{
	//Objects
	Scanner read;
	debugLogger myLogger;
	sharedData myData;
	arduinoWrite ardWriter;
	Socket pipe;
	
	//Variables
	String data;
	long startTime;
	long endTime;
	boolean dead = false;
	
	
	public networkRead(Socket tempSocket, sharedData tempData, debugLogger tempLog, arduinoWrite tempWriter) 
	{
		pipe = tempSocket;
		myData = tempData;
                myLogger = tempLog;
                ardWriter = tempWriter;
    	try 
    	{
			read = new Scanner(tempSocket.getInputStream());
        } 
    	catch (IOException e) 
    	{
            myLogger.writeLog("ERROR: Failure to write to network socket!");
            myLogger.writeLog("\n\n");
            e.printStackTrace();
            myLogger.writeLog("\n\n");
		}
}

	public void run() 
	{
		data = "myData";
		
		startTime = System.currentTimeMillis();
		endTime = startTime + 2000;
		
		while (myData.getAlive()) 
		{
			if(pipe.isConnected())
			{
				if(read.hasNextLine())
				{
					//Read data
					data = read.nextLine();
					data = data.trim();
					//Store Data in shared object
					myData.setReadNet(data);
					//Log the input
					myLogger.writeLog("Read From Server: \t" + data);

					//Pass input to arduino
					ardWriter.writeToSerial(data);
				}
			}
			if(data.equals("ping"))
			{
				startTime = System.currentTimeMillis();
				endTime = startTime + 2000;
			}
			
			keepAlive();
			
			data = "";
			
		}
		
		ardWriter.writeToSerial("BB");
		ardWriter.writeToSerial("EVF");
		ardWriter.writeToSerial("OFF");

		myLogger.writeLog("CRITICAL: CONNECTION LOST!");
		
    
	}
	
	public void keepAlive()
	{
		long temp = System.currentTimeMillis();
		if((temp >endTime))
		{
			myData.setAliveArd(false);
			myData.setAliveNet(false);
		}
	}
}
