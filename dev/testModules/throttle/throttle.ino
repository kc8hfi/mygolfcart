#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>
#include "Timer.h"

//Serial Port Settings
long baudRate = 115200;

//Pins
  //Main Pins
    int mainPowerRelay = 30;

  //Throttle Pins
    int throttlePin = 8;

//Objects
  Servo throttle;

//Variables
  String dataFromSerial = "";
  bool dataFromSerialComplete = false;
  int throttleSpeed = 180;


void setup()
{
     Serial.begin(baudRate);
     
     //make sure the main power is shut off
     pinMode(mainPowerRelay, OUTPUT);
     digitalWrite(mainPowerRelay, LOW);

    //On start set the throttle to stop position
    throttle.attach(throttlePin);
    throttle.write(180);
  
     Serial.flush();
     delay(100);
     Serial.println("Arduino ready");
}

void loop()
{
     if(dataFromSerialComplete)
     {
          //doSomething(incoming);
          dataFromSerialComplete = false;
          dataFromSerial = "";
     }    
}

void serialWrite(String t)
{
     Serial.println(t);
     Serial.flush();
}

void serialEvent()
{
     while(Serial.available() > 0)
     {
          char tempChar = (char)Serial.read();
          //check to see if we get a newline, if so, the string is 
          //complete and its time for the loop() to do something
          //but don't add the \n to the string
          if (tempChar == '\n')
          {
               dataFromSerialComplete = true;
          }
          //otherwise, add the incoming character to the string
          else
          {
               dataFromSerial = dataFromSerial + tempChar;
          }
     }
}

void commands(String theCommand)
{
  theCommand.toLowerCase();

  serialWrite("Executing command:\t"+theCommand);
  
  if(theCommand == "on")
  {
    digitalWrite(mainPowerRelay, HIGH);
  }
  else if (theCommand == "off")
  {
    digitalWrite(mainPowerRelay,LOW);
  }
  else if (theCommand == "bvf")
  {
    throttle.write(throttleSpeed);
  }
  else if (theCommand == "evf")
  {
    throttle.write(180);
  }
}
