/*
 * keep typing a,enter,s,enter and repeat this over and over and the wheels jerk along, but the
 * solenoid stays engaged
 */

#include <SPI.h>

#define SLAVE_SELECT 53
#define RELAY_POWER 32

//remove this line later?
#define RELAY_ACCEL 31

//remove this line later?
#define RELAY_DIRECTION 30

//stuff to read a string from the serial port
String inputString = "";
boolean stringComplete = false;

/*
 * a - starts moving forward
 * s - ends moving forward
 */
void setup()
{
     // Open the serial connection,
     Serial.begin(115200);


     //Inits the Accerator stuff to change speed or resistance on the 
     // maxim chip
     pinMode(SLAVE_SELECT, OUTPUT);
     SPI.setDataMode(SPI_MODE0);
     SPI.setClockDivider(SPI_CLOCK_DIV2);
     SPI.setBitOrder(MSBFIRST);
     SPI.begin();     

     //get ready to turn on the power
     pinMode(RELAY_POWER,OUTPUT);     
     //turn on the power now
     //i htink the power is already turned on....
     digitalWrite(RELAY_POWER,LOW);
     
     //remove these 2 lines later?
     pinMode(RELAY_ACCEL,OUTPUT);
     digitalWrite(RELAY_ACCEL,LOW);

     //remove these 2 lines later?
     pinMode(RELAY_DIRECTION,OUTPUT);
     digitalWrite(RELAY_DIRECTION,HIGH);

     
     Serial.println("start now");
}//end setup

void loop()
{
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


void doSomething(String s)
{
     
     if (s == "a")
     {
          setAccel(1700);
          Serial.println("start: " + String(1700));
     }
     else if(s == "s")
     {
          setAccel(0);
          Serial.println("stop: ");
     }
}

unsigned int formatDACommand(unsigned int value)
{
     value = value<<1;  //shifts to the right, basically multiplying by 2
     value = value & 8190;          //B0001111111111110  is binary for 8190,  
                              //gets anded to binary version of value
     return value;
}

void setAccel(unsigned int value)
{
     Serial.println("in here now");
     //currentForwardSpeed += value;
     value = formatDACommand(value);

     digitalWrite(SLAVE_SELECT,LOW);

     SPI.transfer(value>>8);  //transfer the upper 8 bits of the value
     SPI.transfer(value);  //transfer the lower 8 bits
     digitalWrite(SLAVE_SELECT,HIGH); 

     //this all depends on what SPI.transfer does, if it sends a single byte,
     //then the first transfer sends the upper 8 bits, and the second transfer
     //sends the lower 8 bits
}
