import jssc.SerialPort;
import jssc.SerialPortException;

public class arduinoRead implements Runnable
{	

	//Objects
	SerialPort mySerialPort;
	debugLogger myLogger;
	sharedData myData;
	networkWrite netWriter;
	
	//Variables
	char myChar;
	String data;
	
	public arduinoRead(SerialPort tempPort, sharedData tempData, debugLogger templog, networkWrite tempNet)
	{
		myData = tempData;
		mySerialPort = tempPort;
		myLogger = templog;
		netWriter = tempNet;
	}

	public void run() 
	{
		data = null;
        try
        {
             while (myData.getAlive()) 
             {
            	 myChar = (char)mySerialPort.readBytes(1)[0];
            	 data += myChar;
            	 if(data.endsWith("\n"))
            	 {
            		 data = data.trim();
            		 myLogger.writeLog("Read From Arduino: \t" + data);
            		 myData.setReadArd(data);
            		 netWriter.writeToSocket(data);
            		 data = "";
            	 }
             }
        }
        catch ( SerialPortException e )
        {
             e.printStackTrace();
             myData.setAliveArd(false);
             myData.setAliveNet(false);
        }      
	}
}
