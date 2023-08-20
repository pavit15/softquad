**PWM: Pulse Width Modulation**

**Signals**
fluctuating quantity whose variation represents information
Two types: Analog and digital

**Analog signal**
change value at every instant
can have any values in the range
simple wave of any shape
since it takes in many values, power consumption is high

**Digital Signal** 
it is a square wave that takes only two values, the min or the max value

![](https://hackmd.io/_uploads/SJArz2kp3.png)

**PWM** 
a technique to get analog results by digital means
pulse width: duration of on time
the percentage of duty cycle is the percentage of the total time it is ON
eg: 25% duty cycle mean ON for 1/4th of the time
It is the ratio of ON time to Total time
duty cycle increases, voltage increases, thus brightness increases
![](https://hackmd.io/_uploads/ryAPS2kT3.png)


**Advantages of PWM:**
-prevents overheating and maintains the brightness. thus better than using resistors
-control & response time than analog signals since setting analog signal to a precise value is very hard due to noise fluctutaions thus PWM is more precise

 Function: Here it controls the speed of the motors to balance the bot
 
 **ESP32 MCPWM**
 Two mechanisms provided by expressif company, LEDC PWM for LEDs and MCPWM for motors
 LEDC is faster and has low resolution
 MCPWN is slower but has higher resolution
 resolution: number of levels between 0 and maximum voltage
 more resolution, more precision