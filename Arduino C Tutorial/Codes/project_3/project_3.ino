/*
  keyestudio ESP32 Inventor Learning Kit 
  Project 3：SOS Distress Device
  http://www.keyestudio.com
*/
int ledPin = 5;  //Define pin as IO5
 
void setup() {
pinMode(ledPin, OUTPUT);
}
 
void loop() {
//Three quickly blinks mean “S”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up 
delay(150);                           //Delay 150ms 
digitalWrite(ledPin,LOW);             //Set LED to turn off 
delay(100);                           //Delay 100ms 
}
 
//delay 200ms to generate the space between letters
delay(200);
 
//Three slowly blinks mean “O”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(400);                           //Delay 400ms
digitalWrite(ledPin,LOW);             //Set LED to turn off
delay(200);                           //Delay 200ms
}
 
//Delay 100ms to generate the space between letters
delay(100);
 
// Three quickly blinks mean “S”
for(int x=0;x<3;x++){
digitalWrite(ledPin,HIGH);            //Set LED to light up
delay(150);                           //Delay 150ms
digitalWrite(ledPin,LOW);             //Set LED to turn off 
delay(100);                           //Delay 100ms
} 
// Wait 5s before repeating S.0.S
delay(5000);
}