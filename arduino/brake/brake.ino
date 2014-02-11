#include <Servo.h>
#include <SPI.h>

#define BAUD 115200 

#define SLAVE_SELECT    53

#define BRAKE_ON_PIN    38 //pin 2
#define BRAKE_OFF_PIN   39 //pin 3
#define BRAKE_PIN   8

#define BRAKE_APPLY  1000
#define BRAKE_RELEASE 2000

//turn on the power for everything?
//not sure what pin 31 is for, 
//pin 32 kicks the relay that turns on power for everything it seems
#define RELAY_POWER     32

volatile int brake_status = 0; // 0=release, 1=applying, 2=not moving
int brake_on_state;
int brake_off_state;
volatile boolean brake_set = false;

Servo brake;

//stuff to read a string from the serial port
String inputString = "";
boolean stringComplete = false;

unsigned long time = 0;
int noResponse = 0;


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
     Serial.println(brake_on_state);//switch underneath
     Serial.println(brake_off_state);//switch on the brake pedal
     
     brake_on_state = digitalRead(BRAKE_ON_PIN);
     brake_off_state = digitalRead(BRAKE_OFF_PIN);
     if (brake_status == 1 && brake_on_state == 0)
     {
          brake.writeMicroseconds(2000);     //apply brakes
     }
     else if (brake_status == 0 && brake_off_state == 0)
     {
          brake.writeMicroseconds(1000);     //release brakes
     }
     else
     {
          brake.writeMicroseconds(1500);     //stop brake motor
     }
     
     
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
}

/*
BB  - apply brake
EB  - end brake

*/

void doSomething(String s)
{
     time = millis();
     String log = "receive: " + s;
     if (s == "BB" || s == "bb")
     {
          logger(log);
          //brake.writeMicroseconds(1000);
          brake_status = 1; // 1 = the brake is being applied
          
          //2000 applies the brakes
          //1000 releases the brakes 
          //1500 stops moving the brakes
     }
     else if (s == "EB" || s == "eb")
     {
          logger(log);
          brake.writeMicroseconds(1500);
          brake_status = 0;
     }
     else
     {
          Serial.println(brake_on_state);//switch underneath
          Serial.println(brake_off_state);//switch on the brake pedal
          Serial.println(brake_status);
     }

}//end doSomething

void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);
     Serial1.begin(BAUD);

     pinMode(BRAKE_ON_PIN, INPUT_PULLUP);
     pinMode(BRAKE_OFF_PIN, INPUT_PULLUP);  
     brake.attach(BRAKE_PIN);

     //get ready to turn on the power
     pinMode(RELAY_POWER,OUTPUT);     
     //turn on the power now
     digitalWrite(RELAY_POWER,LOW);
     
     
     //make sure the brake is off
     brake.writeMicroseconds(1500);
     
     Serial.println("start now");
}//end setup

void loop()
{
     brakePulse();
     if (stringComplete)
     {
          //get the string and do something with it
          doSomething(inputString);
          inputString = "";
          stringComplete = false;
     }
     else
     {
     }
}//end loop

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
 
