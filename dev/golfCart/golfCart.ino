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

  //Switch Pins
    int brakeActivatedSwitch = 32;
    int brakeDeActivatedSwitch = 35;
    int brakePin = 33;
    int brakeOnSwitch = 32;   //pin 2     Need to check pinout
    int brakeOffSwitch = 35;  //pin 3     Need to check pinout

//Objects
  Servo brake;

//Variables
  String dataFromSerial = "";
  bool dataFromSerialComplete = false;
  bool brakeStatus = false;

void setup()
{
     Serial.begin(baudRate);
     
     //make sure the main power is shut off
     pinMode(mainPowerRelay, OUTPUT);
     digitalWrite(mainPowerRelay, LOW);

     //create brake controller
     pinMode(brakeActivatedSwitch,INPUT_PULLUP);
     pinMode(brakeDeActivatedSwitch,INPUT_PULLUP);
     brake.attach(brakePin);
     
     Serial.flush();
     delay(100);
     Serial.println("arduino ready");
}

void loop()
{
     brakeCheck();
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
  else if (theCommand == "bb")
  {
    brake.writeMicroseconds(2000);
    brakeStatus = 1;
  }
  else if (theCommand == "eb")
  {
    brake.writeMicroseconds(1000);
    brakeStatus = 0;
  }
  else if (theCommand == "sm")
  {
    brake.writeMicroseconds(1000);
  } 
}

void brakeCheck()
{
     int brakeAppliedSwitch = digitalRead(brakeOnSwitch);
     int brakeReleasedSwitch = digitalRead(brakeOffSwitch);

     if(brakeAppliedSwitch == 0 && brakeStatus == 1)  // brake fully applied stop moving the motor
     {
          brake.writeMicroseconds(1500);
          brakeStatus = -1;
          serialWrite("Brake Applied");
     }
     if(brakeReleasedSwitch == 0  && brakeStatus == 0) // brake fully released stop moving the motor
     {
          brake.writeMicroseconds(1500);
          brakeStatus = -1; 
          serialWrite("Brake Released");
     }
}

