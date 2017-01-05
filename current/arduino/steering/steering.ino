#include <Servo.h>

#define BAUD 115200

//main power relay pin
byte mainPower = 30; 
 
String incoming = "";
boolean completeString = false;

#define STEER_INTERRUPT_1 4
//#define STEER_INTERRUPT_2 5

//the pin numbers each signal is hooked to
#define STEER_PIN_1 19
#define STEER_PIN_2 18

#define STEER_UNIT      .25 // the model#  360/10000

#define STEER_PIN   37

//motor pulse to make it go left and right
#define STEER_R_SPEED    1200 //orig 1000
#define STEER_L_SPEED    1800 //orig 2000
#define STEER_STOP      1500

//full left: -1500
//full right: 1900
// #define HOW_FAR_LEFT  -900
// #define HOW_FAR_RIGHT 900

#define HOW_FAR_LEFT  -800
#define HOW_FAR_RIGHT 800

volatile double steeringAngle;
volatile boolean inter_1_state;
volatile boolean inter_2_state;

volatile double testing = 123.45;

int going_right = 0;
int going_left = 0;

Servo steer;

//0 - steering wheel will not go back to center
//1 - seering wheel will go back to center
int auto_center = 1;

unsigned long time = 0;
int noResponse = 0;

void steer_inter_1()
{
     //Serial.println("interrupt 1");
     inter_1_state = digitalRead(STEER_PIN_1);
     inter_2_state = digitalRead(STEER_PIN_2);
     if (inter_2_state)
     {
          if(inter_1_state)
               steeringAngle = steeringAngle + STEER_UNIT;
          else
               steeringAngle = steeringAngle - STEER_UNIT;
     }
     else
     {
          if(inter_1_state)
               steeringAngle = steeringAngle - STEER_UNIT;
          else
               steeringAngle = steeringAngle + STEER_UNIT;
     }
     
     //make sure the number is withing the range
     if (steeringAngle < HOW_FAR_LEFT)  //left is negative number
          steer.write(STEER_STOP);
     else if (steeringAngle > HOW_FAR_RIGHT)
          steer.write(STEER_STOP);
     //Serial.println(steeringAngle);     
}

void logger(String t)
{
     Serial.println(t);
     //Serial1.println(t);
}


/*
 * on - turns on the main power relay
 * off - turns off the main power relay
 * bvl - begin vehicle left
 * bvr - begin vehicle right
 * evl - end vehicle left
 * evr - end vehicle right
*/

void doSomething(String s)
{
     time = millis();
     String log = "receive: " + s;
     if (incoming == "on")
     {
          digitalWrite(mainPower, HIGH);
     }
     else if (incoming == "off")
     {
          digitalWrite(mainPower, LOW);
     }

     else if(s == "BVL" || s == "bvl")
     {
          logger(log);
          steer.write(STEER_L_SPEED);
          if (going_left)
              going_left = 0;

     }
     else if(s == "EVL" || s == "evl")
     {
          log += " how far: ";
          char t[10];
          log += dtostrf(steeringAngle,1,3,t);
          //log += dtostrf(testing,1,3,t);
          logger(log);
          //stop
          steer.write(STEER_STOP);
          
          if (auto_center)
          {
               logger("now go back to 0");
               steer.write(STEER_R_SPEED);
               going_right = 1;
          }
     }
     else if(s == "BVR" || s == "bvr")
     {
          logger(log);
          steer.write(STEER_R_SPEED);
          if (going_right)
               going_right = 0;
     }
     else if(s == "EVR" || s == "evr")
     {
          log += " how far: ";
          char t[10];
          log += dtostrf(steeringAngle,1,3,t);
          logger(log);
          //stop
          steer.write(STEER_STOP);
          
          if (auto_center)
          {
               logger("now go back to 0");
               steer.write(STEER_L_SPEED);
               going_left = 1;
          }
     }
     else
     {
          log += " at: ";
          char t[10];
          log += "gl: ";
          log += dtostrf(going_left,1,0,t);
          log += " hf: " ;
          log += dtostrf(HOW_FAR_LEFT,1,3,t);
          log += " strang: ";
          log += dtostrf(steeringAngle,1,3,t);
          
          logger(log);

     }

}//end doSomething


void setup()
{
     //make sure the main power is shut off
     pinMode(mainPower, OUTPUT);
     digitalWrite(mainPower, LOW);

     Serial.begin(BAUD);
     
     //attach interrupts for the steering encoder motor
     attachInterrupt(STEER_INTERRUPT_1, steer_inter_1, CHANGE); 
     //attachInterrupt(STEER_INTERRUPT_2, steer_inter_2, CHANGE);

     steer.attach(STEER_PIN);
     steeringAngle = 0.0;

     //make sure steer motor ain't moving
     steer.writeMicroseconds(STEER_STOP);

     Serial.println("arduino ready");
     
     //kick on the main power
     digitalWrite(mainPower, HIGH);
}

void loop()
{
     if(completeString)
     {
          doSomething(incoming);
          incoming = "";
          completeString = false;
     }
     else
     {
          if (going_right)
          {
               if (steeringAngle < 0.0 )
               {
                    going_right = 1;
                    steer.write(STEER_R_SPEED);
               }
               else
               {
                    steer.write(STEER_STOP);
                    going_right = 0;
               }
          }
          if (going_left)
          {
               if (steeringAngle > 0.0 )
               {
                    going_left = 1;
                    steer.write(STEER_L_SPEED);
               }
               else
               {
                    steer.write(STEER_STOP);
                    going_left = 0;
               }
               
          }               
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
