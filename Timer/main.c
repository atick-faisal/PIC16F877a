/*
 * File:   main.c
 * Blink LED at 1Hz using timer interrupt
 * Author: Atick Faisal
 *
 * Created on February 2, 2019, 9:47 AM
 */


#include "pic16f877a.h"

#define _XTAL_FREQ 8000000
#define LED_PIN 1

char state = 0;
int count = 0;

void __init_interrupt__() {
    // setup for INTCON register
    GIE = 1; // enable global interrupt
    PEIE = 1; // enable peripheral interrupt
    // setup PIE1 register
    TMR1IE = 1; // enable timer1 overflow interrupt
    // setup PIR1 register 
    TMR1IF = 0; // clear timer1 overflow interrupt flag
}

void __init_timer__() {
    // setup T1CON register
    // set pre scale of 8
    T1CKPS0 = 1;
    T1CKPS1 = 1;
    TMR1CS = 0; // select internal clock
    TMR1ON = 1; // enable timer1 
}

void  __interrupt() isr(void) {
    if(TMR1IF==1) {
        TMR1H=0x9E;     // Load the time value(0xBDC) for 100 milli delay
        TMR1L=0x58;
        TMR1IF=0; // reset overflow flag
        count++; // counter increments every 100 milli
    } 
    return;
}

void main(void) {
    TRISC &= ~(1 << LED_PIN);
    __init_interrupt__();
    __init_timer__();
    while(1) {
        if(count == 5) { // every 500 milli
            count = 0;
            PORTC ^= (1 << LED_PIN); // alter LED state
        }
    }
}
