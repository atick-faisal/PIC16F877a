## ADC - Analog to Digital Conversion
The Analog-to-Digital (A/D) Converter module has five inputs for the 28-pin devices and eight for the 40/44-pin devices. The conversion of an analog input signal results in a corresponding 10-bit digital number. The A/D module has high and low-voltage reference input that is software selectable to some combination of VDD, VSS, RA2 or RA3. The A/D converter has a unique feature of being able to operate while the device is in Sleep mode. *To operate in Sleep, the A/D clock must be derived from the A/D’s internal RC oscillator.*

**The A/D module has four registers. These registers are:**
- A/D Result High Register `(ADRESH)`
- A/D Result Low Register `(ADRESL)`
- A/D Control Register 0 `(ADCON0)`
- A/D Control Register 1 `(ADCON1)`

**ADCON0 Register**
      
|   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
|-------|-------|-------|-------|-------|-------|-------|-------|
|ADCS1  |ADCS0  |CSH2   |CSH1   |CSH0   |GO/DONE|   -   | ADON  |


 
### Circuit Diagram
<img src="adc.PNG" width="800"/>
