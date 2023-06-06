# **Project 2: Breathing LED**

### **1. Description**

Arduino breathing led utilizes on-board programmable PWM to output analog waveform. After powering on, LED brightness can be adjusted through duty cycle of the waveform to eventually realize the effect of breathing led. 
In this way, ambient light can be simulated by changing LED brightness over time. Also, breathing led can form a colorful mini light to construct a tranquil and warm environment.

### **2. What is PWM?**

PWM controls analog output via digital means, which is able to adjust duty cycle of the wave (a signal circularly shifting between high level and low level).

For Arduino, digital ports of voltage output are LOW and HIGH, which respectively correspond to 0V and 5V. Generally, we define LOW as 0 and HIGH as 1. Arduino will output 500 signals of 0 or 1 within 1s. If they are "1", 5V will be output. Oppositely, if they are all 0, the output will be 0V. Or if they are 010101010101..., the average output will be 2.5V. 

In other words, output ratio of 0 and 1 affects the voltage value, the more 0 and 1 signals are output per unit time, the more accurate the control will be. 

The GPIO34, 35, 36, and 39 of ESP32 cannot use PWM.


![img-20230225090854](media/img-20230225090854.png)

### **3. Wiring Diagram**

![1](./media/1-1682208444748-2.jpg)

### **4. Test Code**

We adopt "for" statement to increase a variable from 0 to 255, and define the variable as PWM output (analogWrite(pin, value)). By the way, a delay time may reinforce the control of LED shining time. Next, we use another "for" statement to decrease it from 255 to 0 with a delay time to control LED dimming process. 

```C
/*
  keyestudio ESP32 Inventor Learning Kit 
  Project 2: Breathing LED
  http://www.keyestudio.com
*/
#define PIN_LED   5   //define the led pin
#define CHN       0   //define the pwm channel
#define FRQ       1000  //define the pwm frequency
#define PWM_BIT   8     //define the pwm precision
void setup() {
  ledcSetup(CHN, FRQ, PWM_BIT); //setup pwm channel
  ledcAttachPin(PIN_LED, CHN);  //attach the led pin to pwm channel
}

void loop() {
  for (int i = 0; i < 255; i++) { //make light fade in
    ledcWrite(CHN, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {  //make light fade out
    ledcWrite(CHN, i);
    delay(10);
  }
}

```

### **5. Test Result**

After uploading the code, we can see that the LED dims gradually rather than all of a sudden. It "breathes" evenly.

### **6. Code Explanation**

**#define**: It is used to define constants ( unchanged)

**ledcSetup()**: It is used to set the frequency and count bits corresponding to the LEDC channel (duty ratio resolution)

The first parameter chan represents the channel number, which ranges from 0 to 15, and can set 16 channels. The high-speed channel (0 ~ 7) is driven by 80MHz clock, and the low-speed channel (8~ 15) is driven by 1MHz clock. The second parameter freq is the desired frequency. The third parameter is the count number of duty ratio resolution, which ranges from 0 to 20. (This value determines the writable value of duty ratio in the ledcWrite method. For example, if the value is 10, the maximum value of duty ratio is 1023, that is, (1<<bit_num)-1.

```c
double ledcSetup(uint8_t chan, double freq, uint8_t bit_num)
```

**ledcAttachPin()**: Its function is to bind the specified LEDC channel to the specified IO port to achieve PWM output.

The pin represents the IO port we want to output, and the channel is the LEDC channel we specify.

```c
void ledcAttachPin(uint8_t pin, uint8_t channel);
```

**ledcWrite()**: Its function is the output duty cycle of the specified LEDC channel.

The chan is the LEDC channel we specify. The duty  means duty cycle,  whose range depends on the bit_num of the ledcSetup() function.

```c
void ledcWrite(uint8_t chan, uint32_t duty)
```

**for (int i = 0; i <= 255; i ++){ ... }**:  It indicates that variable i ranges from 0 to 255, i++ means i increments by 1 each time until the judgment expression i <= 255 is not satisfied. Otherwise, the code in braces is executed for 256 times in total. 

**for (int i = 255; i >= 0; i --){ ... }**, i-- indicates that i is reduced by 1 each time. If i>= 0 is not satisfied, the for() loop is jumped out, and 256 times are executed in total.

**i++** : The variable will add 1 per loop

For more details, please refer to the link:[https://www.arduino.cc/reference/en/]( https://www.arduino.cc/reference/en/)





