/*
 * hall effect sensor on the front wheel
 * black - orange - ground
 * blue - brown - signal, pin 2
 * red - yellow - +5vdc
 * 
 * diameter of the wheel - 16.5 inches
 * circumference - 51.83627 inches
 * 7 magnets, evenly spaced, 7.40518 inches apart
 */


/*
BM004_Arduino_compass_tilt_compensated:  This program reads the magnetometer and
accelermoter registers from ST Micro's LSM303DLHC.  The register values are used to generate 
a tilt compensated heading value.  NOTE:  placing the compass near metallic objects can impact
readings.

Schematics associated with the BM004 moudle may be used for hardware wiring information.
see www.solutions-cubed.com for additional information.

*/

/*
 * compass wiring
 * red - 5v power
 * black - ground
 * white - SDA, 20
 * green - SCL, 21
 * front faces away from the wires
 */

#include <Wire.h>
#include <math.h>
#include <stdlib.h>
#include <Servo.h>
#include <SPI.h>

#define BAUD 115200

//pin 2 is interrupt 0, so plug the sensor into pin 2
#define hall_effect_interrupt_num 0

#define ledPin 13   //led pin

//turn on the power for everything?
//not sure what pin 31 is for, 
//pin 32 kicks the relay that turns on power for everything it seems

#define RELAY_POWER     32

//full left: -1500
//full right: 1900
// #define HOW_FAR_LEFT  -900
// #define HOW_FAR_RIGHT 900

#define HOW_FAR_LEFT  -800
#define HOW_FAR_RIGHT 800

//motor pulse to make it go left and right
#define STEER_R_SPEED    1200 //orig 1000
#define STEER_L_SPEED    1800 //orig 2000
#define STEER_STOP      1500

//the pin numbers each signal is hooked to
#define STEER_PIN_1 19
#define STEER_PIN_2 18

#define STEER_UNIT      .25 // the model#  360/10000

#define STEER_PIN   9

//steering optical encoder has 2 interrupts
//the first interrupt is steer_interrupt_1,
//and the second one is steer_interrupt_2
#define STEER_INTERRUPT_1 4
//#define STEER_INTERRUPT_2 5


/* brake stuff */
#define SLAVE_SELECT    53

#define BRAKE_ON_PIN    38 //pin 2
#define BRAKE_OFF_PIN   39 //pin 3
#define BRAKE_PIN   8

#define BRAKE_APPLY  1000
#define BRAKE_RELEASE 2000

/* movement stuff */
#define RELAY_ACCEL 31
#define RELAY_DIRECTION 30

#define SPEED 1700


volatile int brake_status = 0; // 0=release, 1=applying, 2=not moving
int is_brake;  //0=false, 1=true
int brake_on_state;
int brake_off_state;
volatile boolean brake_set = false;

Servo brake;


/*
 * reading hall effect sensor status
 */
int hallState = 0;  

/*
 * keep track of the number of times the magnet passed the hall effect sensor
 */
int ticks = 0;
int revolutions = 0;

/*
 * bunch of variables for the compass
 */
float Heading;
float Pitch;
float Roll;

float Accx;
float Accy;
float Accz;

float Magx;
float Magy;
float Magz;
float Mag_minx;
float Mag_miny;
float Mag_minz;
float Mag_maxx;
float Mag_maxy;
float Mag_maxz;


//string to hold the incoming command
String inputString = "";
boolean stringComplete = false;

//start the time,
unsigned long thetime = 0;

//keep track if we got a response or not
int noResponse = 0;


//0 - steering wheel will not go back to center
//1 - seering wheel will go back to center
int auto_center = 1;

volatile double steeringAngle;
volatile boolean inter_1_state;
volatile boolean inter_2_state;

volatile double testing = 123.45;

int going_right = 0;
int going_left = 0;

Servo steer;

unsigned int formatDACommand(unsigned int value)
{
  value = value<<1;
  value = value & 8190;          //B0001111111111110
  return value;
}

void setAccel(unsigned int value)
{
  //currentForwardSpeed += value;
  
  value = formatDACommand(value);
  digitalWrite(SLAVE_SELECT,LOW);
  SPI.transfer(value>>8);
  SPI.transfer(value);
  digitalWrite(SLAVE_SELECT,HIGH); 
}

/*  
 * Send register address and the byte value you want to write the accelerometer and 
 * loads the destination register with the value you send
*/
void WriteAccRegister(byte data, byte regaddress)
{
    Wire.beginTransmission(0x19);   // Use accelerometer address for regs >=0x20
    Wire.write(regaddress);
    Wire.write(data);  
    Wire.endTransmission();     
}

/* 
 * Send register address to this function and it returns byte value
 * for the accelerometer register's contents 
*/
byte ReadAccRegister(byte regaddress)
{
     //0x29
    byte data;
    
    
    Wire.beginTransmission(0x19);   // Use accelerometer address for regs >=0x20  
    Wire.write(regaddress);
    Wire.endTransmission();
  
    //delayMicroseconds(100);

    Wire.requestFrom(0x19,1);   // Use accelerometer address for regs >=0x20
    data = Wire.read();
    Wire.endTransmission();   

    //delayMicroseconds(100);

    return data;  
}  

/*  Send register address and the byte value you want to write the magnetometer and 
 * loads the destination register with the value you send
*/
void WriteMagRegister(byte data, byte regaddress)
{
    Wire.beginTransmission(0x1E);   // Else use magnetometer address
    Wire.write(regaddress);
    Wire.write(data);  
    Wire.endTransmission();     

    //delayMicroseconds(100);
}

/* Send register address to this function and it returns byte value
 * for the magnetometer register's contents 
*/
byte ReadMagRegister(byte regaddress)
{
    byte data;
    Wire.beginTransmission(0x1E);   // Else use magnetometer address  
    Wire.write(regaddress);
    Wire.endTransmission();
  
    //delayMicroseconds(100);
    
    Wire.requestFrom(0x1E,1);   // Else use magnetometer address
    data = Wire.read();
    Wire.endTransmission();   

    //delayMicroseconds(100);

    return data;  
}  

void init_Compass(void)
{
    WriteAccRegister(0x67,0x20);  // Enable accelerometer, 200Hz data output

    WriteMagRegister(0x9c,0x00);  // Enable temperature sensor, 220Hz data output
    WriteMagRegister(0x20,0x01);  // set gain to +/-1.3Gauss
    WriteMagRegister(0x00,0x02);  // Enable magnetometer constant conversions
}

/*
 * Readsthe X,Y,Z axis values from the accelerometer and sends the values to the 
 * serial monitor.
*/
void get_Accelerometer(void)
{
     // accelerometer values
     byte xh = ReadAccRegister(0x29);
     byte xl = ReadAccRegister(0x28);
     byte yh = ReadAccRegister(0x2B);
     byte yl = ReadAccRegister(0x2A);
     byte zh = ReadAccRegister(0x2D);
     byte zl = ReadAccRegister(0x2C);

     // need to convert the register contents into a righ-justified 16 bit value
     Accx = (xh<<8|xl); 
     Accy = (yh<<8|yl); 
     Accz = (zh<<8|zl); 
}  

/*
 * Reads the X,Y,Z axis values from the magnetometer sends the values to the 
 * serial monitor.
*/
void get_Magnetometer(void)
{  
     // magnetometer values
     byte xh = ReadMagRegister(0x03);
     byte xl = ReadMagRegister(0x04);
     byte yh = ReadMagRegister(0x07);
     byte yl = ReadMagRegister(0x08);
     byte zh = ReadMagRegister(0x05);
     byte zl = ReadMagRegister(0x06);

     // convert registers to ints
     Magx = (xh<<8|xl); 
     Magy = (yh<<8|yl); 
     Magz = (zh<<8|zl); 
}  

/*
 * Converts values to a tilt compensated heading in degrees (0 to 360)
*/
void get_TiltHeading(void)
{
// You can use BM004_Arduino_calibrate to measure max/min magnetometer values and plug them in here.  The values
// below are for a specific sensor and will not match yours
//   Mag_minx = -621;
//   Mag_miny = -901;
//   Mag_minz = -537;
//   Mag_maxx = 362;
//   Mag_maxy = 269;
//   Mag_maxz = 465;
     
     //recalibrated and using these values now
     Mag_minx = -637;
     Mag_miny = -599;
     Mag_minz = -432;
     Mag_maxx = 567;
     Mag_maxy = 442;
     Mag_maxz = 574;
     
  
     // use calibration values to shift and scale magnetometer measurements
     Magx = (Magx-Mag_minx)/(Mag_maxx-Mag_minx)*2-1;  
     Magy = (Magy-Mag_miny)/(Mag_maxy-Mag_miny)*2-1;  
     Magz = (Magz-Mag_minz)/(Mag_maxz-Mag_minz)*2-1;  

     // Normalize acceleration measurements so they range from 0 to 1
     float accxnorm = Accx/sqrt(Accx*Accx+Accy*Accy+Accz*Accz);
     float accynorm = Accy/sqrt(Accx*Accx+Accy*Accy+Accz*Accz);

     // calculate pitch and roll
     Pitch = asin(-accxnorm);
     Roll = asin(accynorm/cos(Pitch));

     // tilt compensated magnetic sensor measurements
     float magxcomp = Magx*cos(Pitch)+Magz*sin(Pitch);
     float magycomp = Magx*sin(Roll)*sin(Pitch)+Magy*cos(Roll)-Magz*sin(Roll)*cos(Pitch);

     // arctangent of y/x converted to degrees
     Heading = 180*atan2(magycomp,magxcomp)/PI;

     if (Heading < 0)
          Heading +=360;

    //Serial.print("Heading=");
    //Serial.println(Heading);    
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



/*
 * turn a float into a string
 */
String fixFloat(float d)
{
     char convert[20];
     //dtostrf(floatvar, minStringWidthIncludingDecimalPoint, numVarsAfterDecimal, charBuffer)
     dtostrf(d,1,2,convert);
     String s = convert;
     return s;
}


/*
 * handler, called every time a magnet passes by that sensor
 */
void hallEffect()
{
     ticks++;
     if (ticks > 7)
     {
          ticks = 0;
          revolutions++;
     }
     Serial.println(ticks);
     Serial.println(revolutions);
     
     //activate the led, (turn it on if its off, turn it off if its on?)
     digitalWrite(ledPin, !digitalRead(ledPin) );
}

void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);
     Serial1.begin(BAUD);

     //set the mode for the led
     pinMode(ledPin,OUTPUT);
     
     //enable the built in pullup resistor, for the hall effect sensor plugged into pin 2
     pinMode(2,INPUT_PULLUP);
     
     attachInterrupt(hall_effect_interrupt_num,hallEffect,FALLING);    //not sure of 3rd param
     
     //attach interrupts for the steering encoder motor
     attachInterrupt(STEER_INTERRUPT_1, steer_inter_1, CHANGE); 

     //attach the pin to the steering
     steer.attach(STEER_PIN);
     steeringAngle = 0.0;
     
     //get ready to turn on the power
     pinMode(RELAY_POWER,OUTPUT);     
     
     //turn on the power now
     digitalWrite(RELAY_POWER,LOW);
     
     //make sure steer motor ain't moving
     steer.writeMicroseconds(STEER_STOP);

     pinMode(BRAKE_ON_PIN, INPUT_PULLUP);
     pinMode(BRAKE_OFF_PIN, INPUT_PULLUP);  
     brake.attach(BRAKE_PIN);

     //make sure the brake motor is NOT running
     brake.writeMicroseconds(1500);

     //Inits the Accerator stuff to change speed or resistance on the 
     // maxim chip
     pinMode(SLAVE_SELECT, OUTPUT);
     SPI.setDataMode(SPI_MODE0);
     SPI.setClockDivider(SPI_CLOCK_DIV2);
     SPI.setBitOrder(MSBFIRST);
     SPI.begin();     

     //not sure what this is
     pinMode(RELAY_ACCEL,OUTPUT);
     digitalWrite(RELAY_ACCEL,LOW);

     
     //log ready message
     Serial.println("arduino ready");

     Wire.begin();
     init_Compass();
}//end setup

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


/*
 * logger function to write stuff back out the serial port
 */
void logger(String t)
{
     Serial.println(t);
     //Serial1.println(t);
}//end logger


/*
 * BVL,bvl - begin vehicle left
 * BVR,bvr - begin vehicle right
 * EVL,evl - end vehicle left
 * EVR,evr - end vehicle right
 * BB,bb  - apply brake
 * EB,eb  - end brake
 * SBM,sbm - stop brake motor!!!
 * BVF,bvf - begin vehicle forward
 * EVF,evf - end vehicle forward
 * status - prints out the heading from the compass
 * ping - heartbeat from the server, replies with pong
 */

/*
 * this function does it all.
 * ping - keepalive 
 * status - accelerometer x,y,z and compass x,y,z,heading 
 */
void doSomething(String s)
{
     thetime = millis();
     String log = "receive: " + s + " - ";
     log = "";
     if (s == "status")
     {
          log = log + "Status,";
          Heading = round(Heading);
          char convert[20];
          //dtostrf(floatvar, minStringWidthIncludingDecimalPoint, numVarsAfterDecimal, charBuffer)
          dtostrf(Heading,1,0,convert);
          log += convert;
          logger(log);
     }
     else if (s=="ping")
     {
          logger("pong");
          //Serial.println("pong");
          //Serial.println(millis());
     }
     else if(s == "BVL" || s == "bvl")
     {
          log = log + s;
          logger(log);
          steer.write(STEER_L_SPEED);
          if (going_left)
              going_left = 0;

     }
     else if(s == "EVL" || s == "evl")
     {
          log += s;
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
          log += s;
          logger(log);
          steer.write(STEER_R_SPEED);
          if (going_right)
               going_right = 0;
     }
     else if(s == "EVR" || s == "evr")
     {
          log += s;
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
     else if (s == "BB" || s == "bb")
     {
          log += s;
          logger(log);
          brake.writeMicroseconds(2000);
          brake_status = 1; // 1 = the brake is being applied
          
          //2000 applies the brakes
          //1000 releases the brakes 
          //1500 stops moving the brakes
     }
     else if (s == "EB" || s == "eb")
     {
          log += s;
          logger(log);
          brake.writeMicroseconds(1000);
          brake_status = 0;
     }
     else if (s == "SBM" || s == "sbm")
     {
          log += s;
          logger(log);
          brake.writeMicroseconds(1500);
          logger("stop motor");
          //brake_status = 0;
     }
     else if (s == "BVF" || s == "bvf")
     {
          log += s;
          logger(log);
          //this code works
          //unsigned int val = 1400;
          //setAccel(abs(val));
          
          setAccel(abs(SPEED));
     }
     else if (s == "EVF" || s == "evf")
     {
          log += s;
          logger(log);
          setAccel(0);
     }

     else
     {
          log += " at: ";
          char t[10];
          log += "gl: ";
          log += dtostrf(going_left,1,0,t);
          log += " hf: " ;
          log += dtostrf(HOW_FAR_LEFT,1,3,t);
          log += " strange: ";
          log += dtostrf(steeringAngle,1,3,t);
          
          log += "nomatch:" + s;
          logger(log);
     }
}//end doSomething

void loop()
{
     brakePulse();
     get_Accelerometer();
     get_Magnetometer();
     get_TiltHeading();

     //delay(100);
    
     if (stringComplete)
     {
          //Serial.println(inputString);
          //Serial1.println(inputString);
          doSomething(inputString);
          inputString = "";
          stringComplete = false;
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
     if ( (millis() - thetime) > 6000)
     {
          //Serial.println("stop everything!");
          //delay(1000);
     }
}//end loop

/*
 * after a loop(), if there is serial data in the buffer
 */
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
}//end serialEvent

