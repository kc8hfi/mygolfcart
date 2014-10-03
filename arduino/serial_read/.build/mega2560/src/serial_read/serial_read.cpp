#include <Arduino.h>

void setup();
void loop();
void serialEvent();
#line 1 "src/serial_read/serial_read.ino"
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


