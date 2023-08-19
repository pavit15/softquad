**Hardware Aspects of Wall-E**
**1. ESP32 Microcontroller**
-It is a chip made up of silicon atoms, and the orintation of these atoms determines the logic of the code. 
-Has the controls of other components and works like the brain of the circuit
-Other examples: ESP8266, Arduino

ESP stands for Espressif Systems, which is the company that manufactures this microcontroller. It has features such as Wi-Fi, Bluetooth, Dual high performance cores, RAM, ROM and temperature, hall(for magnetic fields) and touch sensors. The cores distribute the load and thus makes the speed faster.

Advantage of ESP32: Cost effective and can be used for various applications

**2. ESP-IDF**
-IDF means IoT development framework
-it is the authentic official toolchain to work, compile and buid on ESP
-it is better than other 3rd party IDEs because it receives the updates first, since it is recommended by the manufacturers. Programmers have the freedom to modify it upto the smallest level. It has a proper and simple file structure. 
-it gives the code to the microcontroller and connects it to the computer

**3. GPIO: General Purpose Input Output Pins**
-these are used to connect sensors to microcontrollers
-almost all pins can be configured to be used either as input or output, therefore is bidirectional

**4. PCB**
-instead of having a huge amount of copper wires, which makes it messy and difficult to use, we use PCB with copper traces
-it is like a line of copper embedded in a plane
-advantage: saves a lot of space
-some lines are thick, some thin, depending on amount of current required

**Main parts of SRA board:**

**1. ESP32**

**2. LSA (Line Sensor Array)**
-is a collection of LEDs
-indication circuit
-gives output of smaller tasks, for debugging
-used for line following

**3. MPU (Motion Processing Unit)**
-used for self balancing

**4. Indicator Circuits (gives input to ESP32, which gives output to motor drivers)**

**5. Motor drivers**
-12V input is also used for driving the motors
-they require higher voltage and current
-ESP manages the speed and amount of power given to motors
-motor driver is an IC used to control the amount of current given to motors
-we have 2 motor drivers for 2 motors
-1 IC can drive 2 motors: normal mode (here we use this)
-parallel mode: outputs get shorted, this net current is added and 1 IC is used for 1 motor
-we have a switch to convert between normal and parallel modes

**6. Power connections**
-Protection circuit: to prevent power fluctuations
-USBA cable in the computer to micro USB cable of ESP gives power to the ESP
-USBA cable has voltage 5V, therfore input voltage is 5V
-adapter converts 220V AC to 12V DC
-volatge regulator: takes in input volage range (2-20V) and converts it to output 5V. This is known as LM2596 Buck Convertor
-normally the 7V is dissipated as heat, but this dissipates less heat and thus has higher efficieny. Also, it gives high output 3A current.
-has capacitors and inductors to filter out the noise(stabilisers volatage)
-LSA and MPU input voltage is 3.3V, so ESP output voltage is decreased to 3.3V again by voltage regulator known as AMS1117
-connected at 2 places since total current flowing in the pcb is 50-60mA output current goes to motor drives and they require more current to get around 120mA
-two ways to power, cable or 12V adapter
-standard voltages on the board to get direct supply to those particular voltages

**7. Fuse**
-used in series
-prevents overflow of current
-to metal conductors connected by a thin wire, wire melts if excess current flows
-it is put before the ESP to protect it









