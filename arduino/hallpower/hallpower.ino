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

//main power pin
byte mainPower = 32; 

#define hall_effect_interrupt_num 0
byte hall_effect_pin = 3;
//pin 2 is interrupt 0, so plug the sensor into pin 2

#define ledPin 13   //led pin

int hallState = 0;  //reading sensor status

int ticks = 0;
int revolutions = 0;

String incoming = "";
boolean completeString = false;

void setup()
{
     // Open the serial connection,
     Serial.begin(BAUD);

     //set the mode for the led
     pinMode(ledPin,OUTPUT);
     
     //enable the built in pullup resistor
     pinMode(2,INPUT_PULLUP);
     
     attachInterrupt(digitalPinToInterrupt(hall_effect_pin),tickhandler,FALLING);    //not sure of 3rd param
     
     //make sure the main power is shut off
     pinMode(mainPower, OUTPUT);
     digitalWrite(mainPower, LOW);
     
     Serial.println("start now");
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
          completeString = false;
          incoming = "";
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
     
     digitalWrite(ledPin, !digitalRead(ledPin) );
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
