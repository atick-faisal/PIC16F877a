/*
 * Code: Analog to Digital Conversion
 * Author: Atick Faisal
 * License: GPL-3.0
 * Created on March 18, 2019, 2:29 AM
 */


#include "pic16f877a.h"

#define _XTAL_FREQ 16000000
#define PRESCALAR 16
#define ADC_PIN 1

float PWM_FREQ;
float PWM_PERIOD;
int counter;

void __init_adc() {
    /*
     * ADCON0 Register
     * +---------------------------------------------------------------+
     * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
     * +---------------------------------------------------------------+
     * |      ADCS     |          CSH          |GO/DONE|   -   | ADON  |
     * +---------------------------------------------------------------+
     */

    ADCON0bits.ADCS = 0b00; // set A/D conversion clock = fosc/2
    ADCON0bits.CHS = 0b000; // set all adc channels off
    ADCON0bits.ADON = 0; // a/d module is powered off

    /*
     * ADCON1 Register
     * +---------------------------------------------------------------+
     * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
     * +---------------------------------------------------------------+
     * |  ADFM | ADCS2 |   -   |   -   |              PCFG             |
     * +---------------------------------------------------------------+
     */

    ADCON1bits.ADFM = 1; // set right justification for ADRESH
    ADCON1bits.ADCS2 = 0; // set A/D conversion clock = fosc/2
    ADCON1bits.PCFG = 0b0000; // set all pins as adc input    
}

int __adc_read(int adc_channel) {
    ADCON0bits.ADON = 1; // turn on a/d module
    ADCON0bits.CHS = (unsigned char) adc_channel; // turn on adc channel
    __delay_ms(10); // wait for capacitors to charge up
    ADCON0bits.GO = 1; // begin conversion
    while (ADCON0bits.GO_DONE == 1) {
        // wait for conversion to finish
    }
    int adc_value = (ADRESH << 8) + (ADRESL);
    return adc_value;
}

///////////////////////////// PWM Configuration ////////////////////////////////

void __set_pwm_freq(int f) {
    PWM_FREQ = f;
    PWM_PERIOD = 1 / PWM_FREQ;
    int PR2_value = (int) ((PWM_PERIOD * _XTAL_FREQ) / (4 * PRESCALAR) - 1);
    PR2 = (uint8_t) PR2_value;

}

void __init_pwm() {
    TRISCbits.TRISC2 = 0; // set RC2 as output
    T2CONbits.TMR2ON = 1; // set timer 2 on
    T2CONbits.T2CKPS = 0b10; // set pre scalar of 16
    CCP1CONbits.CCP1M = 0b1100; // set PWM mode of operation
}

void __set_duty_cycle(int duty_cycle) {
    float dc = (float) duty_cycle / 100;
    float dc_period = dc * PWM_PERIOD;
    uint8_t reg_value = (uint8_t) ((dc_period * _XTAL_FREQ) / PRESCALAR);
    /*
     * PWM has 10 bit resolution
     * 8 bits of MSB is stored in CCPR1L
     * 2 bits of LSB is stored in CCP1CON(5:4)
     */
    CCPR1L = reg_value >> 2;
    CCP1CONbits.CCP1X = (reg_value & 0b00000001);
    CCP1CONbits.CCP1Y = (reg_value & 0b00000010);
}
////////////////////////////////////////////////////////////////////////////////

void main(void) {
    __set_pwm_freq(2000);
    __init_pwm();
    __set_duty_cycle(0);

    __init_adc();

    while (1) {
        float adc_value = (float) __adc_read(ADC_PIN);
        int pwm_value = (int) (adc_value * 100) / 1023; // scale value between 0 to 100
        __set_duty_cycle(pwm_value);
    }
}
