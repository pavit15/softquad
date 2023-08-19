**Steps to use ESP-IDF in command line:**

1. Set the environment 
2. Go into the folder 
3. Connect ESP to device by USB cable
4. To check which port is it connected to:
windows: Device manager>Ports>UART Brige
Linux: direct command 
5. idf.py set target esp32
tells the computer which chip are we targetting. 
it adds files to the build folder
6. idf.py build 
compiles the code 
it is like gcc in windows
7. idf.py -p/[port name] flash
uploads the code to ESP
even if we do flash monitor directly, build will happen
8. idf.py monitor 
tells us on the screen what the code is doing
prints output on the terminal and can be used for debugging purposes
9. Abort: Ctrl+]