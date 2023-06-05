# **Project 1: LED Blinking**

###  **1. Description**

LED blinking is a simple project designed for starters. You only need to install an LED on Arduino board and upload the code on Arduino IDE. This project reinforces the learning of Arduino conceptual framework and using methods for starters. 

###  **2. Working Principle**

![led](./media/led.png)

**LED:** The above is the circuit diagram of LED. Generally speaking, limited IO ports of output current may cause low brightness of LED, so a NPN triode (Q2) is applied in circuit as a switch. In this case, the LED will light up if the base(pin 1) of triode is at a high level. On the contrary, LED goes off when the base is at low. 

**Triode switch:** To have a clear idea of its principle, certain knowledge of electronic circuit is required. For details, please consult materials by yourself. 
Briefly, LED on and off rely on the high and low levels of triode base, which are decided by the pin on the development board. LED lights up when the base(pin 1) is at a high level, and it goes off when the base is at low.



### **3. Wiring Diagram**

![1](./media/1.jpg)

###  **4. Test Code**

According to previous principles, we can control LED via levels of ESP32 pins. 

1. Define an variable as pin IO5 used for pin number modification. 
2. Set pin IO5 to output mode in setup( ). 
3. Set pin IO5 to output  “HIGH” and  “LOW” and delay for 1s respectively.
4. As a result, LED will be on and off for 1s. 

```C
/*
  keyestudio ESP32 Inventor Learning Kit
  Project 1: LED Blinking
  http://www.keyestudio.com
*/
int ledPin = 5; //Define LED to connect with pin IO5
void setup() {
  pinMode(ledPin, OUTPUT);//Set the mode to output
}

void loop() {
  digitalWrite(ledPin, HIGH); //Output a high level, LED lights up
  delay(1000);//Delay 1000ms 
  digitalWrite(ledPin, LOW); //Output a low level, LED goes off
  delay(1000);

}

```

###  **5. Test Result**

After uploading the code and powering on, LED will light up for 1s and off for 1 s.



### **6. Code Explanation**

**setup()Function**: It is used to initialize variables and pin modes and to enable the library. It runs once only after each time the board powering on or being reset. 

**loop()Function**: Followed by setup(), loop()function perpetually executes its code, such as read the pin or output the pin. 

**int ledPin = 3**: “int” is a variable within range of -32768 ~ 32767. This example code means we define an variable **ledpin** with an assignment of 5. Therefore, we adopt **ledpin** rather than “5” in later steps, which largely simplifies experimental recordings when considerable sensors and pins are included. 

**pinMode(pin,mode)**:"pin" is the pin number of mode setting. And the “mode” is optional for INPUT, OUTPUT, and INPUT_PULLUP. Here we set pin 3 to output mode. 

**digitalWrite(pin, value)**: “pin” is the digital tube pin of MCU, and here we define as pin 5. “value” is the digital output level (HIGH/LOW). 
If we apply pinMode() to set pin to OUTPUT, its voltage should be modified correspondingly. For instance, 5V (it is 3.3V if on a 3.3V-board) corresponds to HIGH, while 0V (GND) is for LOW.

However, if LED links with the pin rather than setting pinMode() to OUTPUT, LED may become dim when recalling digitalWrite(HIGH). This is because digitalWrite() enables the inner pull-up resistor, whose function is similar to a great current-limiting resistor. 

**delay(ms)** :It is a delay function and “ms” is the delay time in micro seconds. 

For more Arduino grammar explanations, please refer to: [https://www.arduino.cc/reference/en/](https://www.arduino.cc/reference/en/)

