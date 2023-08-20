SRA Board has 10 LEDs
First 2 are not for programs, they are status LEDs
Rest 8 can be represented as 8 bits
Leftmost as 8 and rightmost as 1
0 OFF, 1 ON

To blink all LEDs: 1111 1111
and then 0000 0000 to get blinking effect

**Hexadecimal:**
0 to 16 digits
0-9 and then 10,11,12,13,14,15 as A,B,C,D,E,F

**Hexadecimal to Decimal**
starting from right, each digit is multiplied by 16^n where n is the digit starting from 0

**Decimal to Hexadecimal**
number is divided by 16 and remainder is written. continue until quotient becomes 0
read remainder from bottom to top

**Decimal to Binary**
divide it by 2. and write the remainder as 0 or 1
write the final number, starting from bottom

**Binary to Decimal**
starting from right, each digit is multiplied by 2^n where n is the digit starting from 0

**Binary to Hexadecimal**
Starting from right, make groups of 4 digits 
and this table for conversion
![](https://hackmd.io/_uploads/HktSDd16n.png)
for the last no, add 0s before if required 

To blink all LEDs one by one, starting from the right hand side
0000 0001
0000 0010
0000 0100
We use left shift operator
Syntax:
var<< y
var: variable on which left shift is to be performed
<<: left shift operator
y: no of bits left shift is to be done (for us it is 1)

eg: 
var=0000 0010
var=var<<2
var becomes: 0000 1000
          
eg: 
var=1111 1111
var=var<<2
var becomes: 1111 1100
          
eg: [IMP]
var=1000 0000
var=var<<1
var becomes: 0000 0000
thus we also add an if condt and it converts var to 0000 0001 in that case
         
**Code**
Top line has header files
freertos: real time operating system
 ESP ERROR CHECK: checks if all GPIO pins are turned on properly
 0xFF= 1111 1111 for set bar graph function
 0x00= 0000 0000
 
task delay: pauses the task for the number of ticks
                                                