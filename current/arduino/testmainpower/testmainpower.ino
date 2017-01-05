#define BAUD 115200

#define MAIN_POWER_RELAY 30

String inputString = "";
boolean stringComplete = false;

void setup() 
{
     // put your setup code here, to run once:
     Serial.begin(BAUD);

     pinMode(MAIN_POWER_RELAY,OUTPUT);
     digitalWrite(MAIN_POWER_RELAY,LOW);
     
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
