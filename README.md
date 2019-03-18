# PIC16F877a
## pic16f877a mini projects using mplab x ide and xc8 compiler
[![Open Source Love](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/) [![GPL Licence](https://badges.frapsoft.com/os/gpl/gpl.svg?v=103)](https://opensource.org/licenses/GPL-3.0/) [![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity) 
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

### 5. PIC16F877A Pinout Diagram
PIC16F877a is a powerful (200 nanosecond instruction execution) yet easy-to-program (only 35 single word instructions) CMOS FLASH-based 8-bit microcontroller packs Microchip's powerful PIC® architecture into an 40- or 44-pin package and is upwards compatible with the PIC16C5X, PIC12CXXX and PIC16C7X devices. The PIC16F877A features 256 bytes of `EEPROM` data memory, self programming, an `ICD`, 2 `Comparators`, 8 channels of 10-bit `Analog-to-Digital (A/D) converter`, 2 `capture/compare/PWM` functions, the synchronous `serial port`, Asynchronous Receiver Transmitter `(USART)`. All of these features make it ideal for more advanced level A/D applications in automotive, industrial, appliances and consumer applications.

![](https://www.researchgate.net/profile/Paulo_Blikstein2/publication/288872085/figure/fig10/AS:614303967236126@1523472887787/A-very-popular-microcontroller-PIC-16F877A-and-its-pinout-diagram.png)

### 6. Pickit3 Connections
Microchip’s PICkit™ 3 In-Circuit Debugger/Programmer uses in-circuit debugging logic incorporated into each chip with Flash memory to provide a low-cost hardware debugger and programmer.

![](https://mvdlande.files.wordpress.com/2016/02/pickit3-pickit3-5-connection-diagram.png)

## License
[![licensebuttons by-nc-sa](https://licensebuttons.net/l/by-nc-sa/3.0/88x31.png)](https://creativecommons.org/licenses/by-nc-sa/4.0)

This work is licensed under [GNU General Public License v3.0](https://github.com/atick-faisal/PIC16F877a/blob/master/LICENSE). 
