#define BAUD 115200

#define MAIN_POWER_RELAY 32
#define FWD_REV_RELAY 34

String inputString = "";
boolean stringComplete = false;

void setup() 
{
     // put your setup code here, to run once:
     Serial.begin(BAUD);

     //set up the main power relay pin and set it to low
     pinMode(MAIN_POWER_RELAY,OUTPUT);
     digitalWrite(MAIN_POWER_RELAY,LOW);

     //set up the fwd/rev relay and set it to low
     pinMode(FWD_REV_RELAY,OUTPUT);
     digitalWrite(FWD_REV_RELAY,LOW);
     
     Serial.println("start now");
}

void loop()
{
     // put your main code here, to run repeatedly:
     if (stringComplete)
     {
          if (inputString == "on")
          {
               //turn on the relay
               Serial.println(inputString);
               digitalWrite(MAIN_POWER_RELAY, HIGH);
          }
          else if (inputString == "off")
          {
               //turn the relay off
               Serial.println(inputString);
               digitalWrite(MAIN_POWER_RELAY,LOW);
          }
          else if(inputString == "fwd" || inputString == "FWD")
          {
               Serial.println(inputString);
               digitalWrite(FWD_REV_RELAY,HIGH);
          }
          else if(inputString == "rev" || inputString == "REV")
          {
               Serial.println(inputString);
               digitalWrite(FWD_REV_RELAY,LOW);
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
