/*
* Code: Seven Segment Display Control
* Author: Atick Faisal
* License: GPL-3.0
*/

#include "pic16f877a.h"

#define _XTAL_FREQ 16000000

void _init() {
    TRISC = 0x00;
    PORTC = 0x00;
}

void display() {
    int i;
    for(i=0; i<10; i++) {
        PORTC = i;
        __delay_ms(1000);
    }
}

void main(void) {
    _init();
    while(1) {
        display();
    }
}
