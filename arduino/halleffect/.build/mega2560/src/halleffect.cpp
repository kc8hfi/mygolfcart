#include <Arduino.h>
void setup();
void loop();
void tickhandler();
#line 1 "src/halleffect.ino"
#define BAUD 115200


//#define hallPin 2   //hall effect sensor, the interrupt number.  
  
//for the mega2560, interrupt 2 is pin 2



#define ledPin 13   //led pin

int hallState = 0;  //reading sensor status

int ticks = 0;

void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);

     pinMode(ledPin,OUTPUT);
     
     attachInterrupt(0,tickhandler,HIGH);    //not sure if high or low here
     
}

void loop()
{
//      hallState = digitalRead(hallPin);
//      if(hallState == LOW)
//      {
//           //turn the light on
//           digitalWrite(ledPin,HIGH);
//      }
//      else
//      {
//           //turn the light off
//           digitalWrite(ledPin,LOW);
//      }
     
}


void tickhandler()
{
     ticks++;
     Serial.println(ticks);
     
     digitalWrite(ledPin, !digitalRead(ledPin) );
}