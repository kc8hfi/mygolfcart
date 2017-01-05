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

  //Steering Pins
    int steerInterrupt = 4;
    int steerPin1 = 19;               //Need to check on these two pins. Think they may be signal emitters to detect whether the steering has reached maximum turn radias. 
    int steerPin2 = 18;               //Need to check on these two pins. Think they may be signal emitters to detect whether the steering has reached maximum turn radias. 

//Objects
  Servo steer;

//Variables
  String dataFromSerial = "";
  bool dataFromSerialComplete = false;

  //Steering
  int steerMotorUnits = .25 ;         // the model# of our unit is: 360/10000
  int steerSpeedRight = 1200;
  int steerSpeedLeft = 1800;
  int steerStop = 1500;
  int steerMaxDistRight = -800;
  int steerMaxDistLeft = 800;
  double steerCurrentAngle = 0;
  bool steeringRight = false;
  bool steeringLeft = false;
  bool autoCenter = true;
  

void setup()
{
     Serial.begin(baudRate);
     
     //make sure the main power is shut off
     pinMode(mainPowerRelay, OUTPUT);
     digitalWrite(mainPowerRelay, LOW);

     attachInterrupt(steerInterrupt,interruptSteering,CHANGE);
  
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
     steeringAutoCenter();
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
  else if (theCommand == "bvl")
  {
    steer.write(steerSpeedLeft);
    if(steeringLeft)
    {
      steeringLeft = false;
    }
  }
  else if (theCommand == "evl")
  {
    steer.write(steerStop);
    if(autoCenter)
    {
      steer.write(steerSpeedRight);
      steeringRight = true;
    }
  }
  else if (theCommand == "bvr")
  {
    steer.write(steerSpeedRight);
    if(steeringRight)
    {
      steeringRight = false;
    }
  }
  else if (theCommand == "evr")
  {
    steer.write(steerStop);
    if(autoCenter)
    {
      steer.write(steerSpeedLeft);
      steeringLeft = true;
    }
  }
}


void steeringAutoCenter()
{
     //Auto Center the steering back 
     if(steeringRight)
     {
        if(steerCurrentAngle < 0.0 )
        {
            steeringRight = true;
            steer.write(steerSpeedRight);
            
        }
        else
        {
            steer.write(steerStop);
            steeringRight = false;
        }
     }
     if(steeringLeft)
     {
        if(steerCurrentAngle > 0.0 )
        {
            steeringLeft = true;
            steer.write(steerSpeedLeft);
            
        }
        else
        {
            steer.write(steerStop);
            steeringLeft = false;
        }
     }
}


void interruptSteering()
{

     volatile boolean interuptState1 = digitalRead(steerPin1);
     volatile boolean interuptState2 = digitalRead(steerPin2);
     if (interuptState2)
     {
          if(interuptState1)
               steerCurrentAngle = steerCurrentAngle + steerMotorUnits;
          else
               steerCurrentAngle = steerCurrentAngle - steerMotorUnits;
     }
     else
     {
          if(interuptState1)
               steerCurrentAngle = steerCurrentAngle - steerMotorUnits;
          else
               steerCurrentAngle = steerCurrentAngle + steerMotorUnits;
     }
     
     //make sure we do not overSteer
     
     if (steerCurrentAngle < steerMaxDistLeft)  //left is negative number
     {
          steer.write(steerStop);
     }   
     else if (steerCurrentAngle > steerMaxDistRight)
     {
          steer.write(steerStop);
     }
}
