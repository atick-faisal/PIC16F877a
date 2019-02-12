/*
 * File:   main.c
 * Stepper Motor Control
 * Author: Atick Faisal
 *
 * Created on February 12, 2019, 9:47 AM
 */

#include "pic16f877a.h"

#define _XTAL_FREQ 16000000

void _init() {
    TRISC = 0x00;
    PORTC = 0x00;
}

void rotate_motor() {
    PORTC = 0b00000001;
    __delay_ms(40);
    PORTC = 0b00000011;
    __delay_ms(40);
    PORTC = 0b00000010;
    __delay_ms(40);
    PORTC = 0b00000110;
    __delay_ms(40);
    PORTC = 0b00000100;
    __delay_ms(40);
    PORTC = 0b00001100;
    __delay_ms(40);
    PORTC = 0b00001000;
    __delay_ms(40);
}

void main(void) {
    _init();
    while(1) {
        rotate_motor();
    }
}
