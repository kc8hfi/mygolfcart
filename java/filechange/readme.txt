readwrite.java - the main program.  
starts up the console reading thread to read from the keyboard
starts the arduinoreadwrite threads
starts up the timer that looks to see if the file was changed or not

filewatcher.java - this is the thread that looks at the file and tells the DoWork 
object that the file was changed

DoWork.java - this class reads from the file once its changed and does all the work!

cartinfo.java - this is the object that holds the golf cart's status.  The arduino reader 
thread (from arduinoreadwrite object) updates this object when the arduino sends the 
status string

arduinoreadwrite.java - this object starts up 2 threads,  arduinoreaderthread and 
arduinowriterthread.  

arduinoreaderthread.java - thread that reads from the arduino

arduinowriterthread.java - thread that writes to the arduino
