/*
  keyestudio ESP32 Inventor Learning Kit 
  Project 21.2：Sound Controlled LED
  http://www.keyestudio.com
*/
int sound = 33;   //Define sound to IO33
int led = 25;      //Define led to IO25
void setup(){
  pinMode(led,OUTPUT);   //Set IO25 to output 
}

void loop(){
  int value = analogRead(sound);    //Read analog value of IO33 and assign it to value
  if(value > 100){                  //Judge whether value is greater than 100
    digitalWrite(led,HIGH);         //If IO25 pin outputs high level, LED lights up
    delay(2000);
  }
  else{
    digitalWrite(led,LOW);          //If IO25 pin outputs low level, LED lights off
  }
}