#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>


//main power pin
byte mainPower = 32; 

byte throttlePin = 10;
Servo throttle;
 
String incoming = "";
boolean completeString = false;


void setup()
{
     //make sure the main power is shut off
     pinMode(mainPower, OUTPUT);
     digitalWrite(mainPower, LOW);
     
     //attach the servo to the pin
     throttle.attach(throttlePin);

     //move the servo back to 0 degrees before you turn on the main power!!!
     throttle.write(0);
     
     Serial.begin(115200);

     
     Serial.println("arduino ready");
     
}

void loop()
{
     if(completeString)
     {
          doSomething(incoming);
          completeString = false;
          incoming = "";
     }
}

void serialEvent()
{
     while(Serial.available() > 0)
     {
          char inchar = (char)Serial.read();
          //check to see if we get a newline, if so, the string is 
          //complete and its time for the loop() to do something
          //but don't add the \n to the string
          if (inchar == '\n')
          {
               completeString = true;
          }
          //otherwise, add the incoming character to the string
          else
          {
               incoming = incoming + inchar;
          }
     }
}


void logger(String t)
{
     Serial.println(t);
     //Serial1.println(t);
}


/*
 * ping - keepalive 
 * on - turn on the main power
 * off - turn off the main power
 */

void doSomething(String s)
{
     String log = "receive: " + s;
     //logger(s);
     if (incoming == "on")
     {
          digitalWrite(mainPower, HIGH);
     }
     else if (incoming == "off")
     {
          digitalWrite(mainPower, LOW);
     }
     else if (s=="ping" || s == "PING")
     {
          logger("pong");
          //Serial.println("pong");
          //Serial.println(millis());
     }
     else if (s =="f")
     {
          //throttle.write();  //put the position here, this is the angle to move to
          throttle.write(180);
          logger("to 100");
     }
     else if (s == "s")
     {
          throttle.write(20);
          logger("to 20");
     }
     else
     {
          logger(log);
          Serial.println("we are right here");
          throttle.write(s.toInt());
     }
}
