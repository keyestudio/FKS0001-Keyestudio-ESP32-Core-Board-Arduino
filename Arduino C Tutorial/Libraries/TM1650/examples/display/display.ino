/***********************************************************
  Author: jieliang mo
  Date:   2 July, 2020
  github: https://github.com/mworkfun/TM1650.git
  IDE:	  Arduino-1.8.12
  Version: 1.0.0
  project: 4 digital tube
***************************************************************/

#include "TM1650.h"
#define CLK 22    //pins definitions for TM1650 and can be changed to other ports       
#define DIO 21
TM1650 DigitalTube(CLK,DIO);

void setup(){
  //DigitalTube.setBrightness();  //set brightness, 0---7, default : 2
  //DigitalTube.displayOnOFF();   //display on or off, 0=display off, 1=display on, default : 1
  for(char b=0;b<4;b++){
    DigitalTube.clearBit(b);      //DigitalTube.clearBit(0 to 3); Clear bit display.
  }
  // DigitalTube.displayDot(1,true); //Bit0 display dot. Use before displayBit().
  //DigitalTube.displayBit(2,5);    //DigitalTube.DisplayBit(bit,number); bit=0---3  number=0---9
}

void loop(){
  for(int num=0; num<10000; num++){
    DigitalTube.displayFloatNum(num);
    delay(100);
  }
}


