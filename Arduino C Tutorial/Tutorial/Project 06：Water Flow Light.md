# **Project 6：Water Flow Light**
### **1. Description**
This simple water flow light project enables to help you learn electronic packaging. In this project, we will control LEDs to change the color in a specified speed via a Arduino board.

### **2. Wiring Diagram**

![6](./media/6.jpg)

### **3. Test Code**

A water flow light means that LED lights go from left to right and then from right to left.
In this experiment, we use continuous pins, so that "for" statement can be utilized not only to set output mode (replace pins with circular variable in code) but to output. 

```C
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

```

### **4.  Test Result**

After uploading code and powering on, the LEDs go from left to right and then from right to left

### **6. Code Explanation**

**for(int i = 12;i <= 15 ;i++){    pinMode(i,OUTPUT);    }**  : We can use "for" statement to define continuous pins. Yet it features a disadvantage of non-replacement ability of pins, which deteriorates the code portability. 

**for(int i = 12; i <= 15; i++){**
    		**digitalWrite(i,HIGH);**
    		**delay(200);**
    		**digitalWrite(i,LOW);**
  **}**     

In the first loop, LED on IO12 pin will light up and off after a 200ms delay. At the second time, LED on IO13 pin will turn on and off also after a 200ms delay. Until the IO15 pin is extinguished and the for loop is popped out, and the second for loop is the same except from IO15 pin to IO12 pin.

