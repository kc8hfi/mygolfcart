#define BAUD 115200
 
 /*
 * black - orange - ground
 * blue - brown - signal
 * red - yellow - +5vdc
 */


#define hall_effect_interrupt_num 0
//pin 2 is interrupt 0, so plug the sensor into pin 2

#define ledPin 13   //led pin

int hallState = 0;  //reading sensor status

int ticks = 0;

void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);

     //set the mode for the led
     pinMode(ledPin,OUTPUT);
     
     //enable the built in pullup resistor
     pinMode(2,INPUT_PULLUP);
     
     attachInterrupt(hall_effect_interrupt_num,tickhandler,FALLING);    //not sure of 3rd param
     Serial.println("start now");
}

void loop()
{
//      hallState = digitalRead(hallPin);
//      if(hallState == LOW)
//      {
//           //turn the light on
//           digitalWrite(ledPin,HIGH);
//      }
//      else
//      {
//           //turn the light off
//           digitalWrite(ledPin,LOW);
//      }
}


void tickhandler()
{
     ticks++;
     Serial.println(ticks);
     
     digitalWrite(ledPin, !digitalRead(ledPin) );
}
