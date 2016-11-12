import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class debugLogger 
{
	File logFile;
	FileWriter fileOutputStream;
	BufferedWriter writer;
	int verbose = 0;
 
    public debugLogger(int temp)
    {
    	verbose = temp;
    	try
    	{
    		//Create the log file
    		logFile = new File("logFile.txt");
    		
    		if( !logFile.exists())
    		{
    			logFile.createNewFile();
    		}
    		
    		//Create output stream for the buffered reader and create the buffered reader
    		fileOutputStream = new FileWriter(logFile.getAbsoluteFile());
			writer= new BufferedWriter(fileOutputStream);
    	}
    	catch(IOException e)
    	{
    		System.out.println("FAILURE: Unable to create log file");
    	}
    	
    }
    
    public void writeLog(String temp) 
    {
    	//Verbose level 1 is console logging
    	if(verbose == 1)
    	{
    		System.out.println(temp);
    	}
    	//Verbose level 2 is console and file logging
    	else if(verbose == 2)
    	{
    		try
    		{
    			//Print to console
        		System.out.println(temp);
        		//Write to file;
        		writer.append(temp);
        		writer.flush();
    		}
    		catch(IOException e)
    		{
    			System.out.println("CRITICAL: Unable to write to log file!");
    		}
    	}
    }
    
    public void close()
    {   
    	try
    	{
    		writer.close();
    		fileOutputStream.close();
    	}
    	catch(IOException e)
    	{
    		System.out.println("CRITICAL: Cant save log file!");
    	}
    }
}
