#include <Servo.h>
#include <SPI.h>

/*
 * program to test out the brakes
 */

#define BAUD 115200

#define MAIN_POWER_RELAY 30

#define BRAKE_ON_PIN  32   //pin 2
#define BRAKE_OFF_PIN 35  //pin 3
#define BRAKE_PIN   33

#define BRAKE_APPLY  1000
#define BRAKE_RELEASE 2000

volatile int brake_status = 0; // 0=release, 1=applying, 2=not moving
int is_brake;  //0=false, 1=true
int brake_on_state;
int brake_off_state;
volatile boolean brake_set = false;

Servo brake;

unsigned long time = 0;
int noResponse = 0;



String inputString = "";
boolean stringComplete = false;

void setup() 
{
     // put your setup code here, to run once:
     Serial.begin(BAUD);

     //set the main power pin and turn it off
     pinMode(MAIN_POWER_RELAY,OUTPUT);
     digitalWrite(MAIN_POWER_RELAY,LOW);
     
     //set up both switches and the brake motor
     pinMode(BRAKE_ON_PIN, INPUT_PULLUP);
     pinMode(BRAKE_OFF_PIN, INPUT_PULLUP);  
     brake.attach(BRAKE_PIN);
     
     //make sure the brake is off
     brake.writeMicroseconds(1500);
     Serial.println("ready");
}

/*
 * on - turn on the main power
 * off - turn off the main power
 * bb - apply brakes
 * eb - end braking
 * sm - stop motor, no matter where it is at!  
 */

void loop()
{
     brakePulse();
     // put your main code here, to run repeatedly:
     if (stringComplete)
     {
          logger(inputString);
          if (inputString == "on")
          {
               //turn on the relay
               digitalWrite(MAIN_POWER_RELAY, HIGH);
          }
          else if (inputString == "off")
          {
               //turn the relay off
               digitalWrite(MAIN_POWER_RELAY,LOW);
          }
          else if (inputString == "BB" || inputString == "bb")
          {
               brake.writeMicroseconds(2000);
               brake_status = 1; // 1 = the brake is being applied
               
               //2000 applies the brakes
               //1000 releases the brakes 
               //1500 stops moving the brakes
          }
          else if (inputString == "EB" || inputString == "eb")
          {
               brake.writeMicroseconds(1000);
               brake_status = 0;
          }
          else if (inputString == "SM" || inputString == "sm")
          {
               brake.writeMicroseconds(1000);
               logger("stop motor");
               //brake_status = 0;
          }
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

void logger(String t)
{
     Serial.println(t);
     //Serial1.println(t);
}

void brakePulse()
{
/*     
start now
1
0
0
receive: bb
1
0
1
receive: eb
0
1
0     
*/ 
//      Serial.println(brake_on_state);//switch underneath
//      Serial.println(brake_off_state);//switch on the brake pedal
     
     brake_on_state = digitalRead(BRAKE_ON_PIN);
     brake_off_state = digitalRead(BRAKE_OFF_PIN);
//      if (brake_status == 1)
//      {
//           Serial.println("begin braking");
//      }
//      else if (brake_status == 0);
//      {
//           Serial.println("end braking");
//      }
     if(brake_on_state == 0 && brake_status == 1)  //stop moving the motor
     {
          brake.writeMicroseconds(1500);
          brake_status = 2;
          is_brake = 1;
          logger("stopped the motor!");
     }
     if(brake_off_state == 0  && brake_status == 0)
     {
          brake.writeMicroseconds(1500);
          brake_status = 2;
          is_brake = 0;
          logger("stopped motor other way!");
     }
//      if (brake_on_state == 0)
//      {
//           brake.writeMicroseconds(2000);
//      }
//      else
//      {
//           brake.writeMicroseconds(1500);
//      }
     
     
//      if (brake_status == 1 && brake_on_state == 0)
//      {
//           brake.writeMicroseconds(2000);     //apply brakes
//      }
//      else if (brake_status == 0 && brake_off_state == 0)
//      {
//           brake.writeMicroseconds(1000);     //release brakes
//      }
//      else
//      {
//           brake.writeMicroseconds(1500);     //stop brake motor
//      }
     
     
//      if (brake_off_state == 0 && brake_status == 1)
//      {
//           //stop moving the brake motor!
//           brake.writeMicroseconds(1500);
//           brake_status = 2;
//      }
//      if (brake_on_state == 0 && brake_off_state == 0)
//      {
//           //stop moving the brake motor
//           brake.writeMicroseconds(1500);
//      }
     
     //return;
}//end brakePulse
