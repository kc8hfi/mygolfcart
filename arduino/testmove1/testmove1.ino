#include <SPI.h> 

#define SLAVE_SELECT 53
#define RELAY_POWER 32

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
     digitalWrite(RELAY_POWER,LOW);
     
     Serial.println("start now");
}//end setup

void loop()
{
     setAccel(1700);
     delay(200);
     setAccel(0);
     delay(200);
}//end loop


unsigned int formatDACommand(unsigned int value)
{
     value = value<<1;  //shifts to the right, basically multiplying by 2
     value = value & 8190;          //B0001111111111110  is binary for 8190,  
                              //gets anded to binary version of value
     return value;
}

void setAccel(unsigned int value)
{
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
