import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

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
    		System.out.println("ERROR: Unable to create log file");
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
                        //Append time-stamp to the output
                        SimpleDateFormat sdf = new SimpleDateFormat("MMM dd,yyyy HH:mm:ss");
                        Date resultDate = new Date(System.currentTimeMillis());
                        temp = sdf.format(resultDate)+"\t"+temp;
                        
    			//Print to console
        		System.out.println(temp);
        		
        		//Write to file;
        		temp = temp+"\n";
        		writer.append(temp);
        		writer.flush();
    		}
    		catch(IOException e)
    		{
    			System.out.println("ERROR: Unable to write to log file!");
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
    		System.out.println("ERROR: Cant save log file!");
    	}
    }
}
