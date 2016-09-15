#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>

#define BAUD 115200

//main power pin
#define MAIN_POWER 30

//throttle pin,  for the servo
#define THROTTLE 8

Servo throttle;
String incoming = "";
boolean completeString = false;

void setup()
{
     //make sure the main power is shut off
     pinMode(MAIN_POWER, OUTPUT);
     digitalWrite(MAIN_POWER, LOW);
     
     //attach the servo to the pin
     throttle.attach(THROTTLE);

     //move the servo back to 0 degrees before you turn on the main power!!!
     throttle.write(180);
     
     Serial.begin(BAUD);

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
 * f - makes the cart start moving  
 * s - makes the cart stop moving
 * <type a number> - makes hte servo move to the given angle, adjusts
 * the speed of the cart
 */

void doSomething(String s)
{
     String log = "receive: " + s;
     //logger(s);
     if (incoming == "on")
     {
          digitalWrite(MAIN_POWER, HIGH);
     }
     else if (incoming == "off")
     {
          digitalWrite(MAIN_POWER, LOW);
     }
     else if (s=="ping" || s == "PING")
     {
          logger("pong");
          //Serial.println("pong");
          //Serial.println(millis());
     }
     else if (s =="s")
     {
          //throttle.write();  //put the position here, this is the angle to move to
          throttle.write(180);
          logger("to 180");
     }
     else if (s == "f")
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
