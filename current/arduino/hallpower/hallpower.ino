#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>

/*
 *          Change-Log 12:34am April 28th 
 * Adam Cantrell
 *
 *
 * Cleaned up the code to make the code a bit easier to read
 *      especially the declarations for the pins and variables
 *
 * Noticed that the interrupt was attached to pin 2 however the
 *      hall_effect_pin was stil set to look at pin 3Hopefully 
 *      by fixing this so that the sensor and interrupt are on 
 *      the same pin again will correct the problem with not 
 *      getting any data from the sensor
 *
 *      
 */
 
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
 * Are these the color codes for the throttle wiring?
 *
 * black - orange - ground
 * blue - brown - signal
 * red - yellow - +5vdc
 */

 
/**************DEFINITIONS**************/
#define BAUD 115200                             //Set baud rate for the arduino serial port
#define mainPower   30                          //Pin for Main Power relay 
#define hall_effect_interrupt_num   0           //Pin for hall effect interrupt
#define hall_effect_pin   2                     //Pin the hall effect sensor wire is connected to 
#define ledPin   13                             //led pin


/**************VARIABLES**************/
volatile int ticks = 0;                         //Counts the number of ticks per revolution
volatile int revolutions = 0;                   //Counts the number of revolutions of the wheel
String incoming = "";                           //String used to hold input from the serial port
boolean completeString = false;                 //Boolean used in check to determine if command ends with /n
int hallState = 0;                              //reading sensor status

/**************OBJECTS**************/
Servo throttle;                                 //Create object for the throttle servo. 




void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);
     
     Serial.println("Beginning setup");
     Serial.println("Setting default states to low");
     
     // Set the default state of all pins on the arduino to low to prevent floating 
     // pins from causing problems with the interrupts firing when they shouldnt
//      for(int i=1;i<=53;i++)
//      {
//           pinMode(i,OUTPUT);
//           digitalWrite(i,LOW);
//      }
     

     //set the mode for the led
     pinMode(ledPin,OUTPUT);
     
     
     //enable the built in pullup resistor
     pinMode(hall_effect_pin,INPUT_PULLUP);
     digitalWrite(hall_effect_pin,HIGH);
     
     
     //3rd parameter defines what triggers the interrupt. Falling indicates that a voltage drop fires the interrupt
     attachInterrupt(digitalPinToInterrupt(hall_effect_pin),tickhandler,FALLING);    
     
     
     //make sure the main power is shut off
     pinMode(mainPower, OUTPUT);
     digitalWrite(mainPower, LOW);
     
     
     Serial.println("Arduino now ready!");
}

void loop()
{
     if(completeString)
     {
          String log = "receive: " + incoming;
          //logger(s);
          
          if (incoming == "on")
          {
               digitalWrite(mainPower, HIGH);
          }
          else if (incoming == "off")
          {
               digitalWrite(mainPower, LOW);
          }
          else
          {
               Serial.println("we are right here");
               Serial.println(log);
          }
          
          completeString = false;                           //Reset bool to false for to begin waiting for the new command.
          incoming = "";                                    //Reset the string that holds incoming commands to empty string.
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
     
     digitalWrite(ledPin, !digitalRead(ledPin) );                   //Visual inidcator that the tickhandler has fired
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
