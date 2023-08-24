## Objectives:
- **Design and Fabrication:** The researchers designed and fabricated the SQuad, a miniature soft quadruped robot. The robot has a soft body made from PDMS (Polydimethylsiloxane) and flexible c-shaped legs for locomotion.
- **Locomotion Analysis:** The researchers conducted experiments to analyze the locomotion capabilities of the SQuad. They performed walking and obstacle climbing experiments to assess how the robot moves and overcomes obstacles.
- **Untethered Operations:** With the untethered capabilities the robot has flexibility to move freely, interact delicately with environment without exerting excess pressure, and overcome obstacles while ensuring its safety through its compliant structure.
![](https://hackmd.io/_uploads/BkkY0RNTn.png)

## Design:
![](https://hackmd.io/_uploads/Hkt5AR4an.png)

1. **Leg Design**:
	- SQuad has four c-shaped legs made of Polydimethylsiloxane (PDMS) and driven by miniature DC motors.
	- C-shaped legs were chosen for their softness and adaptability to different surfaces. They were inspired by RHex (Hexapod roobot) and known for obstacle scaling capabilities.
	- Autodesk Fusion 360 CAD software was used for stress analysis and dimension determination.
	- PDMS legs have a Young's Modulus of 1.54 MPa and PLA legs (chosen as hard legs for Hard Robot and Soft Body Hard Legs Hybrid) have a Young's Modulus of 3.5 GPa.
	- Legs were designed to distribute weight, with each PDMS leg supporting about 10.15 grams of mass.
	- Stiffness of PDMS leg is 36.17 N/m, while PLA leg stiffness is 81.234 kN/m.
	- Dimension for Legs in x and y direction are 36 mm and 40 mm respectively with thickness of 10mm
![](https://hackmd.io/_uploads/HyiiRREpn.png)

2. **Body Design**:
    - The middle section of the body is not fully rigid to save weight, using a 'union jack' design(Fig 5(a),5(b)).
    - The body dimensions are 100 mm length and 55 mm width.
	- The soft body weighs 36.25 grams (including standard PCB and excluding battery), while the hard body weighs 34.13 grams (including standard PCB and excluding battery).
	- Stiffness around Y axis: 0.4316 N/m (soft body) vs. 1047.12 N/m (hard body).
	- Stiffness around X axis: 4.62 N/m (soft body) vs. 10.6 kN/m (hard body).

3. **PCB Design**:
  - Flexible PCB designed for weight reduction and flexibility is, made from polyimide sheets laminated with copper used for soft body.
  - Main components include Arduino Pro Micro, L293DD H-Bridge motor drivers, capacitors for voltage stability, switch, and step-up regulator.
  - Standard FR4 PCB used for the hard body.
![](https://hackmd.io/_uploads/BJex1ySp3.png)

4. **Motor Connector Design**:
 - Used small DC motors: 136:1 gear ratio Pololu for hard body, 700:1 for soft body due to higher torque requirement.
 -  Linked motors to c-shaped legs using 3D printed PLA connectors.
 - Used infinite turn potentiometers as absolute encoders for precise control.
 - *Challenges and Solution:
    - Connecting soft legs to motors was challenging due to size differences b/n motor and sensor.
    - Rotary encoder has D shaped opening of 5mm and Pololu gear motor has shaft dia 2mm.
    - Designed two-piece motor connector:
        - First part glued to motor shaft.
        - Second part holds leg using set screw.
- Enables easy part replacement without damaging legs.
- Supports testing various leg types without changing motors.
![](https://hackmd.io/_uploads/H1jBJJBp2.png)

### Fabrication:
1. **Body Fabrication:** 
	 - PDMS Sylgard 184 mixed in a 10:1 ratio of pre-polymer and cross-linker, with thorough mixing.
	 - Vacuum oven used to eliminate air bubbles.
	 - PLA mold covered with Ease Release 205, and PDMS poured into mold.
	 - Mold placed in an oven at 70°C for 4 hours.
	 - Curing completed by leaving mold at room temperature for 18 hours.
2. **C-Shaped Leg Fabrication:**
	- Similar process to body fabrication with 5:1 ratio PDMS for added leg stiffness.
	- 3D printed motor connectors embedded into leg grooves.
	- 5:1 ratio PDMS requires 1 hour at 70°C for curing. 
### Controller Design:
- The controller uses a DC motor model with voltage source, resistance and back emf
- The inductance is not taken into account for convenience since we do not measure or control the current input to the system and the value of inductance is small enough to neglect for the utilized motors.
- System states: motor rotation angle (θ) and rotational rate (˙ θ).
- The control system is full state feedback control system based of LInear Quadratic Regulator
- Challenge: Only motor position is readable via rotary encoders; rotational rate (˙ θ) can't be directly measured this way. Solution: Estimate rotational rate using Linear Quadratic Estimator (LQE) which is an observer.
- LQE helps achieve full state feedback control even with incomplete state measurements.
- Combination of LQR and LQE results in Linear Quadratic Gaussian Controller (LQG).
- LQG used to control robot gait: trot gait with diagonal leg pairs out of phase by half period, but same frequency.
- In order to Test and Compare Soft Quad, 3 Other Robots(Pure Rigid Robot, Hard Body and Soft Legs Hybrid, Soft Body and Hard Leg Hybrid) were built and set for configurations.
# Locomotion Analysis

Motors are kept at 0.5Hz for all 4 robots and PLA legs are coated with PDMS to eliminate difference due to material friction properties.
![](https://hackmd.io/_uploads/SJXokyHpn.png)

### 1.Speed Analysis:
- Soft legs provided better traction, resulting in slightly higher speeds for both soft body and hard body configurations compared to hard legs.
- Soft legs conformed better to the ground due to their flexibility, increasing surface contact and friction.
- Soft body configurations showed slightly slower walking due to energy consumption in body undulation.
![](https://hackmd.io/_uploads/By2nkJHTn.png)

### 2.Pitch and Roll Angle Analysis:
- The soft-bodied robot with soft legs exhibits smoother pitch angles during walking than the hard-bodied counterpart.
- The soft-bodied robot's ability to pitch up and down contributes to a smoother walking behaviour.
- Soft legs and soft body combined help dampen impact forces, leading to a smoother roll angle profile.
- The compliant nature of both soft legs and soft body enhances the robot's ability to absorb shocks and maintain smoother locomotion overall.
![](https://hackmd.io/_uploads/Bk56kyrT3.png)

### 3.Body Centroid Position Analysis:
- Centroid analysis highlighted that the center of gravity of the robots constantly changed due to body undulations and leg rotations.
- Soft-bodied robots had a lower centroid position compared to hard-bodied robots, especially during motion, due to their compliant nature.
- A low centroid position is preferable for better obstacle climbing performance.
- The centroid position analysis reveal how drastic the robot’s dynamics change due to the body compliance. Even though the hard and soft bodies take steps with the same frequency, the oscillations in the centroid positions are slower in the soft body compared to the hard body.
![](https://hackmd.io/_uploads/Byf1eJran.png)

### 4.Obstacle Climbing Analysis:
![](https://hackmd.io/_uploads/BkJlekBp2.png)
![](https://hackmd.io/_uploads/rJlZlJHTh.png)

- Obstacle climbing tests assessed the robots' ability to scale obstacles.
- Soft-bodied and soft-legged robot (SQuad) outperformed other configurations, climbing an obstacle 1.44 times its body height.
- Soft body configurations generally had better obstacle climbing capabilities compared to hard body configurations.

# Conclusion:
The SQuad Proved to be better in comparison to the rigid twin and 2 hybrid robots; Since it had less tremble in pitch angle and centroid displacement giving better stability. Locomotion Analysis and the Stiffness Analysis done during Design and Fabrication Process major differences in all the 4 robots such as Flexibility.
The DC motor used to reduce weight and C shaped design for leg was also crucial in showing strong obstacle scaling capabilities

# Future Upgrades:

- Communication methods(WiFi or Bluetooth) can be used to provide real time update
-  Different gait can be tried to find the different manoeuvrability characteristics and obstacle climbing performances.
- Use of Contraction method to traverse through even smaller cross section than the cross section area of the SQuad
- Different Types of actuators (pneumatic,hydraulic) can be implemented to get wider range of motion and better control
