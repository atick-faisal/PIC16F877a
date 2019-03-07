/*
 * Code: PIC16F877A PWM control
 * Author: Atick Faisal
 * License: GPL-3.0
 * Created on March 6, 2019, 6:55 PM
 */


#include "pic16f877a.h"

#define _XTAL_FREQ 16000000
#define PRESCALAR 16

/*
         The following steps should be taken when configuring
       the CCP module for PWM operation:
       1. Set the PWM period by writing to the PR2 register.
       2. Set the PWM duty cycle by writing to the
       CCPR1L register and CCP1CON<5:4> bits.
       3. Make the CCP1 pin an output by clearing the
       TRISC<2> bit.
       4. Set the TMR2 pre scale value and enable Timer2
       by writing to T2CON.
       5. Configure the CCP1 module for PWM operation.
 */

float PWM_FREQ;
float PWM_PERIOD;
int counter;

void __set_pwm_freq(int f) {
    PWM_FREQ = f;
    PWM_PERIOD = 1 / PWM_FREQ;
    int PR2_value = ((PWM_PERIOD * _XTAL_FREQ) / (4 * PRESCALAR) - 1);
    PR2 = PR2_value;
    
}

/*
 * T2CON Register
 * +---------------------------------------------------------------+
 * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
 * +---------------------------------------------------------------+
 * |   -   |TOUTPS3|TOUTPS2|TOUTPS1|TOUTPS0|TMR2ON |T2CKPS1|T2CKPS0|
 * +---------------------------------------------------------------+
 */

void __init_pwm() {
    TRISCbits.TRISC2 = 0; // set RC2 as output
    T2CONbits.TMR2ON = 1; // set timer 2 on
    T2CONbits.T2CKPS = 0b10; // set pre scalar of 16
    CCP1CONbits.CCP1M = 0b1100; // set PWM mode of operation
}

/*
 * CCP1CON Register
 * +---------------------------------------------------------------+
 * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
 * +---------------------------------------------------------------+
 * |   -   |   -   | CCP1X | CCP1Y |CCP1M3 |CCP1M2 |CCP1M1 |CCP1M0 |
 * +---------------------------------------------------------------+
 */

void __set_duty_cycle(int duty_cycle) {
    float dc = (float) duty_cycle / 100;
    float dc_period = dc * PWM_PERIOD; 
    int reg_value = (int) ((dc_period * _XTAL_FREQ) / PRESCALAR);
    /*
     * PWM has 10 bit resolution
     * 8 bits of MSB is stored in CCPR1L
     * 2 bits of LSB is stored in CCP1CON(5:4)
     */
    CCPR1L = reg_value >> 2; 
    CCP1CONbits.CCP1X = (reg_value & 0b00000001);
    CCP1CONbits.CCP1Y = (reg_value & 0b00000010);
}

void main(void) {
    __set_pwm_freq(2000);
    __init_pwm();
    __set_duty_cycle(0);
    
    // continuously increase and decrease LED Brightness
    
    while(1) {
        for(counter = 0; counter < 100; counter++) {
            __set_duty_cycle(counter);
            __delay_ms(10);
        }
        for(counter = 100; counter > 0; counter--) {
            __set_duty_cycle(counter);
            __delay_ms(10);
        }
    }
}
