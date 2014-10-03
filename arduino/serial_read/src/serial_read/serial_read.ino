/*
 * this program is set up to be compiled from ino, and not
 * the arduino ide.
 * 
 * You can still compile it with the arduino ide, do this:
 * 
 * 1.  make a directory called serialread
 * 2.  put the serial_read.ino inside the serialread directory
 * 3.  rename the serial_read.ino to serialread.ino
 * 4.  open the serialread.ino file with the arduino and compile away!!
 */

/*
 * read from Serial, and write back to Serial and Serial1
 */

String inputString = "";
boolean stringComplete = false;

void setup()
{
     Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
     Serial1.begin(115200);
}

void loop() 
{
     //Serial.println("start arduino");
     //delay(1000);
     if (stringComplete)
     {
          Serial.println(inputString + " echoed");
          Serial1.println(inputString);
          inputString = "";
          stringComplete = false;
     }
}

void serialEvent()
{
     while(Serial.available())
     {
          char inChar = (char)Serial.read();
          if(inChar == '\n')
               stringComplete = true;
          else
               inputString += inChar;     
     }
}


