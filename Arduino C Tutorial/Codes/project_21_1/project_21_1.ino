/*
  keyestudio ESP32 Inventor Learning Kit 
  Project 21.1：Sound Controlled LED
  http://www.keyestudio.com
*/
int sound = 33; //Define sound as IO33
void setup(){
  Serial.begin(9600);
  pinMode(sound,INPUT);
}

void loop(){
  int value = analogRead(sound);
  Serial.println(value);
}
