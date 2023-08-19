![[ESP32.jpg]]
# ESP32
ESP32 is a microcontoller module developed by Espressif Systems 
1. **Dual-Core Processor**: The ESP32 features two Xtensa 32-bit LX6 CPU cores, which allows parallel processing and improved performance in multitasking applications.
2. **Wireless Connectivity:** The ESP32 is a feature-rich MCU with integrated Wi-Fi and Bluetooth connectivityfor a wide range of applications.
3. **Memory**: It typically comes with a significant amount of flash memory for program storage and RAM for data manipulation. This allows for more complex applications and code to be executed.
4. **RTOS Support**: It supports FreeRTOS, an open-source real-time operating system, which assists in managing tasks and resources efficiently, making it easier to develop complex applications.
5. **Rich Set of Peripherals**: The ESP32 offers a plethora of peripherals, including GPIO pins, UART, SPI, I2C, PWM, ADC, DAC, and more, providing flexibility for various hardware interfacing needs.
## ESP32 pins:
- 34 Programmable GPIOs: GPIO is one of the most commonly used peripheral. It can carry out more than one function(only one at a time).The pins provided can be configured as GPIO or ADC or PWM, etc (There are 4 Input only GPIOs)
- 18 12-bit ADC Channels: It is a 12 bit Analog to Digital converter. Since it is 12 bit the Digital values returned are in range 0-4093
- 2 8-bit DAC Channels: It has 2 8 bit Digital to Analog Converter which converts Digital alue to analog voltage signals
- 16 PWM Channels:PWM channels are used to configure frequency and duty cycles. Hence There are used in driving Motors and LEDs
- 3 UART Interfaces: Universal Asynchronous Receiver/Transmitter Interface Provides asynchronous communication and IrDA Support.The ESP32 chip has three UART controllers, each featuring an identical set of registers to simplify programming and for more flexibility.
- 3 SPI Interfaces: The ESP32 Wi-Fi chip features three SPI(Serial Peripheral Interface) blocks (SPI, HSPI and VSPI) in both master and slave modes. SPI is used to interface with Flash Memory.
- 2 I2C Interfaces
- 2 I2S Interfaces
- 10 Capacitive Touch Sensing GPIOs
- 16 RTC GPIOs : These are the part of RTC Low-Power subsystem. These are used as wakeup call for ESP32
