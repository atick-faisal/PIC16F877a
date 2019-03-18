# PIC16F877a
## pic16f877a mini projects using mplab x ide and xc8 compiler
[![GitHub license](https://img.shields.io/badge/license-GPL-blue.svg)](https://github.com/me-shaon/GLWTPL/blob/master/NSFW_LICENSE) [![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/SaadAAkash/Web-Development/graphs/commit-activity) [![Open Source Love svg1](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/) ![made-with-love](https://img.shields.io/badge/Made%20with-Love-1f425f.svg)
### 1. Contents:
- **[Timer Interrupt](https://github.com/atick-faisal/PIC16F877a/tree/master/Timer)**
- **[Pulse Width Modulation](https://github.com/atick-faisal/PIC16F877a/tree/master/PWM)**
- **[Analog to Digital Conversion](https://github.com/atick-faisal/PIC16F877a/tree/master/Analog%20to%20Digital%20Conv)**
- **[Serial Communication](https://github.com/atick-faisal/PIC16F877a/tree/master/Serial%20Communication)**
- **[LCD Display Control](https://github.com/atick-faisal/PIC16F877a/tree/master/LCD%20Display)**
- **[Stepper Motor Control](https://github.com/atick-faisal/PIC16F877a/tree/master/Stepper%20Motor)**

### 2. Required Softwares
- **[Download](https://www.microchip.com/mplab/mplab-x-ide) and Install Mplab X IDE**
- **[Download](https://www.microchip.com/mplab/compilers) and Install XC8 compiler**
- **[Download](https://www.labcenter.com/downloads/) and Install Proteus Design Suite**

### 3. How to Use
- All the codes are written based on the pic16f877a **Datasheet**. The datasheeet provided [here](https://github.com/atick-faisal/PIC16F877a/blob/master/Datasheet/pic16f877a.pdf) contains all the necessary registers and bits descriptions. The `Datasheet` folder also contains user manual for Mplab X IDE and Pickit3. 
- **Source codes** are written in `main.c` file inside the `Project Directory`
- **Simulation Files** can be found inside `Proteus Simulation` directory under `Project Directory`
### 4. Running a project:
- Open the project in `MPLAB X` IDE
- Open `main.c` file inside `source`
- Click on the `build` icon on the top
- A `.hex` file is generated inside `Project Folder > dist > default > production > filename.hex`
- Open the Simulation file (with a `.pdsprj` extension) in `Proteus`
- Double Click on the mcu to bring out the configuration menu
- Browse and select the `.hex` file and click Ok
- Click on the run button at the bottom to simulate
