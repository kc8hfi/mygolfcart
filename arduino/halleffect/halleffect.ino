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
int revolutions = 0;

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
     
     digitalWrite(ledPin, !digitalRead(ledPin) );
}
