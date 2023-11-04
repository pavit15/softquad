# ESP IDF Commands
1. get_idf:  command used to set up the environment variables which activates the other esp idf commands (used in Linux/MacOS)
2. dmesg | grep tty: command used to check which port is connected to esp32
3. idf.py set-target esp32: command will add necessary files required for building code of specific device here esp32
4. idf.py menuconfig: Command opens up Configuration Menu which is needed to set parameters 
5. idf.py build: Command will build and compile all the files in folder
6. sudo chmod 777 PORT: Command to use to give permission to send info through the port
    (If this is used command 7 can be used as idf.py flash)
7. idf.py -p PORT [-b BAUD] flash: Command will Flash the compiled information to ESP32 *BAUD is used to define the BAUD rate that is the speed at which information has to be sent to ESP*. (idf.py -p PORT flash can be used to send info at default speed)
8. idf.py monitor: Command will show the output given by ESP32
9. idf.py flash monitor: Command covers the steps of 7th and 8th command in one command
10. To exit out of the output shown by monitor command use ctrl+]
11. idf.py flash erase: This command erases the flash memory of ESP32
