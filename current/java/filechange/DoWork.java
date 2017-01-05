import java.util.*;
import java.io.*;

public class DoWork
{
     private File thefile;
     private BufferedWriter writer;
     private cartinfo status;
     
     private int whichdir = 0;     //turning left or right
     
     public DoWork (File f, BufferedWriter w, cartinfo s)
     {
          thefile = f;
          writer = w;
          status = s;
     }
     
     public void doit()
     {
          try 
          {
               // FileReader reads text files in the default encoding.
               FileReader fileReader = new FileReader(thefile);

               // Always wrap FileReader in BufferedReader.
               BufferedReader bufferedReader = new BufferedReader(fileReader);
               String line = null;
               while((line = bufferedReader.readLine()) != null) 
               {
                    System.out.println("the file contains:'" +line +"'");
                    if (line.equals("script"))
                    {
                         /*
                          * this is where we call another program to open and execute the script file
                          * you want to pass this program the cartinfo object, so that it'll have 
                          * access to the data.  status.getString() will return the info.
                          */
                    }
                    else
                    {
                         //this is where we just send the command to the arduino
                         String [] command = line.split(" ");
                         String writeme = "";          //this is what gets sent to the arduino
                         if (command[0].equals("up"))
                         {
                              writeme = "bvf";
                         }
                         else if(command[0].equals("stop"))
                         {
                              writeme = "evf";
                         }
                         else if (command[0].equals("fwd"))
                         {
                              writeme = "fwd";
                         }
                         else if (command[0].equals("rev"))
                         {
                              writeme = "rev";
                         }
                         else if (command[0].equals("left"))
                         {
                              whichdir = 1;
                              writeme = "bvl";
                         }
                         else if (command[0].equals("left"))
                         {
                              whichdir = 2;
                              writeme = "bvl";
                         }
                         else if (command[0].equals("svt"))
                         {
                              if(whichdir == 1) //turning left
                              {
                                   whichdir = 0;
                                   writeme = "evl";
                              }
                              else if(whichdir == 2) //turning right
                              {
                                   whichdir = 0;
                                   writeme = "evr";
                              }
                              else
                                   whichdir = 0;
                         }
                         else if(command[0].equals("speed"))
                         {
                              writeme = command[1];
                         }
                         else if (command[0].equals("refresh"))
                         {
                              //we have what the arduino is already doing, it is in status.getString()
                              //we just need to write that out to a file so that the web page can read it                              
                         }
                         
                         writer.write(writeme);
                         writer.newLine();
                         writer.flush();
                         
                         System.out.println("sent to arduino:'" +writeme +"'");
                         System.out.println("current status: '" + status.getString() + "'");
                    }
               }  
               // Always close files.
               bufferedReader.close();                    
          }
          catch(IOException e)
          {
          }
     }//end doit
}//end DoWork