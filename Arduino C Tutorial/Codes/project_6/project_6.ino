/*
  keyestudio ESP32 Inventor Learning Kit  
  Project 6 Water Flow Light
  http://www.keyestudio.com
*/
void setup() {
  for(int i = 12;i <= 15 ;i++){   //Use "for" loop statement to set IO12-IO15 pin to output mode
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for(int i = 12; i <= 15; i++){		//Use "for" loop statement to light up LED on IO12-IO15 pin in sequence 
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
  }
  for(int i = 15; i >= 12; i--){		//Use "for" loop statement to light up LED on IO15-IO12 pin in sequence   
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
  }
  
}
