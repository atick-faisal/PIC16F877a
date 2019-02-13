/*
 * File:   main.c
 * Author: Atick Faisal
 * Project: LCD Display
 * Created on February 13, 2019, 4:36 PM
 */


#include <string.h>
#include "pic16f877a.h"

#define _XTAL_FREQ 16000000

#define DATA_PORT PORTC
#define SETUP_PORT PORTB
#define EN 7                //enable pin
#define RS 6                //register select pin
#define WRITING_DELAY 1

void setup() {
    TRISB = 0x00;
    TRISC = 0x00;
}

void __init_display() {
    SETUP_PORT &= ~(1 << RS);
    DATA_PORT = 0b00001111;
    SETUP_PORT |= (1 << EN);
    __delay_ms(WRITING_DELAY);
    SETUP_PORT &= ~(1 << EN);
    SETUP_PORT |= (1 << RS);
}

void clear_display() {
    SETUP_PORT &= ~(1 << RS);
    DATA_PORT = 0b00000001;
    SETUP_PORT |= (1 << EN);
    __delay_ms(WRITING_DELAY);
    SETUP_PORT &= ~(1 << EN);
    SETUP_PORT |= (1 << RS);
}

void lcd_write_char(char i) {
    DATA_PORT = i;
    SETUP_PORT |= (1 << EN);
    __delay_ms(WRITING_DELAY);
    SETUP_PORT &= ~(1 << EN);
}

void lcd_write(char data[]) {
    int i;
    for(i=0; i<(strlen(data)); i++) {
        lcd_write_char(data[i]);
    }
}

void home() {
    SETUP_PORT &= ~(1 << RS);
    DATA_PORT = 0b00000010;
    SETUP_PORT |= (1 << EN);
    __delay_ms(WRITING_DELAY);
    SETUP_PORT &= ~(1 << EN);
    SETUP_PORT |= (1 << RS);
}

void shift_cursor_right() {
    SETUP_PORT &= ~(1 << RS);
    DATA_PORT = 0b00010100;
    SETUP_PORT |= (1 << EN);
    __delay_ms(WRITING_DELAY);
    SETUP_PORT &= ~(1 << EN);
    SETUP_PORT |= (1 << RS);
}

void set_cursor(int horizontal_shift) {
    home();
    int count;
    for(count=0; count<horizontal_shift; count++) {
        shift_cursor_right();
    }
}

void main(void) {
    setup();
    __init_display();
    lcd_write("Hello World");
    set_cursor(8);
    while(1) {
    }
}
