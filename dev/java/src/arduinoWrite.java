import jssc.SerialPort;
import jssc.SerialPortException;

public class arduinoWrite 
{
    SerialPort mySerialPort;
    debugLogger myLogger;
    
    public arduinoWrite(SerialPort temp, debugLogger templog)
    {
        mySerialPort = temp;
        myLogger=templog;
    }
    
    public void writeToSerial(String temp)
    {
        try
        {
        	if(mySerialPort != null)
        	{
        		mySerialPort.writeString(temp+'\n');
        		myLogger.writeLog("Serial Write:\t\t"+temp);
        	}
        	else
        	{
        		myLogger.writeLog("CRITICAL: Serial Port is not open!");
        	}
        }
        catch(SerialPortException e)
        {   
            myLogger.writeLog("CRITICAL: Failure to Write to serial port!");
            myLogger.writeLog("\n\n");
            e.printStackTrace();
            myLogger.writeLog("\n\n");
        }
    }
}
