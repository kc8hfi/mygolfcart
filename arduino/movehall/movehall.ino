#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>

#define BAUD 115200

/*
 * hall effect sensor on the front wheel
 * black - 14 orange - ground
 * blue - 13 brown - signal, pin 2
 * red - 15 yellow - +5vdc
 * 
 * diameter of the wheel - 16.5 inches
 * circumference - 51.83627 inches
 * 7 magnets, evenly spaced, 7.40518 inches apart
 */

 /*
 * black - orange - ground
 * blue - brown - signal
 * red - yellow - +5vdc
 */


#define hall_effect_interrupt_num 0
byte hall_effect_pin = 3;
//pin 2 is interrupt 0, so plug the sensor into pin 2

#define ledPin 13   //led pin


volatile int ticks = 0;
volatile int revolutions = 0;

//main power pin
byte mainPower = 30; 

byte throttlePin = 8;
Servo throttle;
 
String incoming = "";
boolean completeString = false;

void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);

     //set the mode for the led
     pinMode(ledPin,OUTPUT);
     
     //enable the built in pullup resistor
     pinMode(2,INPUT_PULLUP);
     
     //attachInterrupt(hall_effect_interrupt_num,tickhandler,FALLING);    //not sure of 3rd param
     attachInterrupt(digitalPinToInterrupt(hall_effect_pin),tickhandler,FALLING);    //not sure of 3rd param
     
     //make sure the main power is shut off
     pinMode(mainPower, OUTPUT);
     digitalWrite(mainPower, LOW);
     
     //attach the servo to the pin
     throttle.attach(throttlePin);

     //move the servo back to 0 degrees before you turn on the main power!!!
     throttle.write(180);
     
     //turn on the main power
     digitalWrite(mainPower,HIGH);
     
     Serial.println("start now");
}
void logger(String t)
{
     Serial.println(t);
     //Serial1.println(t);
}

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
          throttle.write(0);
          logger("to 0");
     }
     else if (s == "s")
     {
          throttle.write(180);
          logger("to 180");
     }
     else
     {
          logger(log);
          Serial.println("we are right here");
          throttle.write(s.toInt());
     }
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

void tickhandler()
{
     ticks++;
     if (ticks >7)
     {
          ticks = 0;
          revolutions++;
     }
     Serial.println(ticks);
     Serial.println(revolutions);
     
     digitalWrite(ledPin, !digitalRead(ledPin) );
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

