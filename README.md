---
title: 'Soft Quad Readme'
disqus: hackmd
---

Soft Quad
===
## Table of Contents
- [About The Project](#about_the_project)
    - [Key elements of the project](#key_elements_of_the_project)
    - [Tech Stack](#tech_stack)
- [Getting Started](#getting_started)
    - [Prerequisites](#prerequisites)
    - [Installations](#installations)
- [Theory and Approach](#theory_and_approach) 
    - [Design of robot chassis](#design_of_robot_chasis)
    - [Selecting Flex Material for the bot](#selecting_material_for_the_bot)
- [Troit Gait Algorithm](#troit_gait_algorithm)
- [Challenges faced and solutions applied](#challenges_faced_and_solutions_applied)
- [Contributors](#contributors)
- [Acknowledgement and Resources](#acknowledgement_and_resources)
---

# <ins>About the Project
**To create a robot capable of overcoming obstacle using soft materials.**
Basically, in our project, we use flex material instead of rigid materials such as PLA. We used Ecoflex Dragon skin material for the body. A Flex PCB will enable our SoftQuad robot to become more flexible, improving its capacity to scale higher obstacles.
  
## <ins>Key elements of the project:
### 1. Mechanical design
The mechanical design and fabrication aspect of the project involve creating a design which is durable, flexible and lightweight to enable efficient movement. This design ensures both agility and robustness, allowing the robot to traverse challenging terrains while maintaining stability and precision.

### 2. Embedded design
In the core of the system, we use ESP32, a powerful microcontroller with built-in Wi-Fi and Bluetooth capabilities. It is programmed using the ESP-IDF (IoT Development Framework), which provides the tools and libraries necessary to develop applications for the microcontroller.

### 3. PCB design
The PCB (Printed Circuit Board) design involves creating a custom circuit board that has various electronic components such as microcontrollers, motor drivers, sensors, communication modules, and power management units. 

We used a Flex PCB, which is a type of electronic circuit board that is made from flexible and bendable materials instead of rigid materials like in traditional PCB’s. They offer a range of benefits due to their flexibility, allowing them to be shaped, folded, or bent to fit into various form factors and spaces that rigid PCBs cannot accommodate.
### 4. Soft robotics
Unlike traditional rigid robots, this project utilizes soft robotics principles to create a robot with a pliable and deformable structure. This inherent flexibility allows the robot to adapt its shape to various obstacles, enhancing its ability to traverse complex terrains.</ins>
</ins>

## <ins>Tech Stack
- Embedded C
- SolidWorks
- KiCAD
- Altium
- ESP-IDF
- Ultimaker Cura
    
# <ins>Getting Started
## <ins>Prerequisites
1. Used [ESP-IDFv4.4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started) for building and flashing the controller code.
2. Used [KiCad](https://www.kicad.org/) For designing the rigid PCB
3. Used [Altium](https://www.altium.com/) For designing the flex PCB   
4. Used [Solidworks](https://www.solidworks.com/) for designing the bot and mold for soft bot.
5. Used [Ultimaker Cura](https://ultimaker.com/software/ultimaker-cura/) for 3D printing the parts

## <ins>Installations
1. Installing ESP-IDF:
[For Windows](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html)
[For Linux or MacOS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)

    
# <ins>Theory and Approach
### Design of robot chasis
- We designed the chasis of the bot on Solidworks.
 
![](https://hackmd.io/_uploads/S1VOm8KMT.png)

### Selecting Flex Material for the bot
- For the bot material, we had to choose between Dragon Skin, Eco-Flex 00-30, Eco-Flex 00-50
- After taking into account factors such as flexibility, durability, elasticity and stability, we concluded that Dragon Skin is the material most comparable to PDMS in terms of its flexibility, translucency, and biocompatibility. It is often used as a substitute when PDMS like properties are required, making it a versatile and obvious choice for applications such as soft robotics. 


## <ins>Trot Gait Algorithm
We controlled the movement of the bot through our ESP-32 controller. The motion that the bot follows is that of the horse trot gait. 
Here is a flowchart explaining the code: 
![flowchart.png](https://hackmd.io/_uploads/H1CGo5E7p.png)

## <ins>PCB Design on KiCAD
Fornt side of PCB
![pcb front.png](https://hackmd.io/_uploads/SkxyNiEQp.png)
    
Backside
![pcb back.png](https://hackmd.io/_uploads/SylkEoNQp.png)
## <ins>Challenges faced and solutions applied  
At first, the weight of the body was bending the flex legs since they were unable to support the weight of the bot. In order to allow the legs to move, we altered the leg's measurements and added thickness.Managing the soft robotics part is taking some time.
The main hardware and circuit problem we encountered was voltage control, or the inability to supply the appropriate and sufficient voltage to the corresponding electrical equipment.
We had to move to Altium because Kicad would not allow us to define stack layers, or create a flexible PCB with stiffeners. It took some getting used to.

## <ins>Making the flex body
For testing purposes, we made the rigid body of the bot using 3D printing first. After finishing with testing, we made the molds for the bot and 3D printed them. Then we made the mold of the bot using Dragon Skin material. For this process, initially we mixed the material  in 1:1 ratio for around 1 minute. Then we put this mixture in the mold and left it for around 2 hours.
    
DragonSkin material in the mold:
![Flex material leg mould.jpg](https://hackmd.io/_uploads/S1PYEjVXa.jpg)

## <ins>Contributors
[Atharva Atre](https://github.com/AtharvaAtre)
[Pavit Kaur](https://github.com/pavit15)
[Varad Naik](https://github.com/VaradNaik921)
    
---

## <ins>Acknowledgement and Resources
Thanks to Our Mentors [Chinmay Mundane](https://github.com/ChinmayMundane), [Vaidic Gupta](https://github.com/Vaidicgupta) for Mentoring and Guiding us in our project.

Special Thanks to [SRA VJTI](https://sravjti.in/) for giving us the opportunity to do the project.

**Resources:**
- [**SoftBot Research Paper**](https://repository.bilkent.edu.tr/server/api/core/bitstreams/3dedb9bb-7897-4cc8-92b2-c85b78272922/content)
- [**ESP-IDF Resources**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)
- [**KiCad Playlist**](https://www.youtube.com/playlist?list=PLn6004q9oeqGl91KifK6xHGuqvXGb374G)
- [**Solidworks Playlist**](https://www.youtube.com/playlist?list=PLrOFa8sDv6jcp8E3ayUFZ4iNI8uuPjXHe)

---
