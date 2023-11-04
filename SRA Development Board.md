## Microcontroller:
- A microprocessor designed to perform Tasks 
- It is the brain of the The Dev Board
- It is necessary for controlling and coordinating between electronic and electrical devices
- eg. ESP32, Arduino, ESP8266

## ESP32 DevkitC V4
It has the following features;
1. RAM,ROM
2. WiFi(2.4 GHz) 
3. Bluetooth 4.2
4. Dual Core 160-240 MHz
5. Temp Sensor (To Measure Temperature)
6. Hall Sensor (To Measure Magnetic Field)
7. Capacitive Touch Sensor (To measure the sensation of Touch)
### ESP IDF
- IDF: IoT development Framework
- ESP's Toolchain to work and build, compile code on ESP based microcontronller
- It has better features as: 1. It gets updated and compatability first, 2. It can configure and modify microcontroller to smallest register level, 3. Has a simple file structure

## Sensors: LSA and MPU
**LSA**:
- Line Sensing Array
- Line Sensing is done by sensing intensity of reflected IR light
- Works on 3.3V Supply
**MPU**:
- Motion Processing Unit
- Detects Orientation of Bot
- Works on 3.3V Supply
### Voltage Regulator 
- Firstly the 220V AC Voltage is Converted to 12V DC
- Which is then converted by first voltage regulator LM2596 Buck Convertor(Converts 0-40V DC range to give 5V constant supply) which converts to 5V
- Since the ESP32 Microcontroller needs 5V supply and the output shoould be 3.3V
- AMS1117 Voltage regulator converts this 5V to 3.3V

## Motor Drive: TB6612FNG
Motor Driver is an IC used to control Motor (By adjusting the voltage applied) in autonomous robots and embedded circuits
Motor Driver listens to the low voltage processor and control motor which needs 12V . Motor Driver IC controls direction of motor based on the commands recieved
Motor Driver is basically used to boost the supply of current and voltage
