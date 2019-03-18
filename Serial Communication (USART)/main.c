/*
 * Code: Serial Communication 
 * Author: Atick Faisal
 * License : GPL-3.0
 * Created on March 18, 2019, 4:28 AM
 */

#include <stdio.h>
#include <string.h>
#include "pic16f877a.h"

#define _XTAL_FREQ 16000000
#define BAUD_RATE 9600
#define ADC_PIN 1

char buffer[50];

void __init_usart() {
    /*
     * TXSTA Register
     * +---------------------------------------------------------------+
     * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
     * +---------------------------------------------------------------+
     * |  CSRC |  TX9  |  TXEN | SYNC  |   -   |  BRGH | TRMT  |  TX9D |
     * +---------------------------------------------------------------+
     */
    
    TXSTAbits.TX9 = 0; // set 8 bit transmission
    TXSTAbits.TXEN = 1; // enable data transmit
    TXSTAbits.SYNC = 0; // select asynchronous mode
    TXSTAbits.BRGH = 1; // set high baud rate
    
    /*
     * RCSTA Register
     * +---------------------------------------------------------------+
     * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
     * +---------------------------------------------------------------+
     * |  SPEN |  RX9  |  SREN | CREN  | ADDEN |  FERR | OERR  |  RX9D |
     * +---------------------------------------------------------------+
     */
    
    RCSTAbits.SPEN = 1; // enable serial ports
    RCSTAbits.RX9 = 0; // select 8 bit reception
    RCSTAbits.CREN = 1; // enable continuous receive
}

void __set_baud_rate(int baud_rate) {
    /*
     * Baud Rate = FOSC/(16 (SPBRG + 1))
     */
    SPBRG = ((_XTAL_FREQ / 16) / baud_rate) - 1;
}

void __write_char(char c) {
    while(!TXIF) {
        // wait until byte is sent
    } 
    TXREG = c; // transmit a bit
}

void __usart_write_ln(char data[]) {
    int i;
    for(i=0; i<(strlen(data)); i++) {
        __write_char(data[i]);
    }
    __write_char('\r');
}

void __init_adc() {
    ADCON0bits.ADCS = 0b00; // set A/D conversion clock = fosc/2
    ADCON0bits.CHS = 0b000; // set all adc channels off
    ADCON0bits.ADON = 0; // a/d module is powered off
    
    ADCON1bits.ADFM = 1; // set right justification for ADRESH
    ADCON1bits.ADCS2 = 0; // set A/D conversion clock = fosc/2
    ADCON1bits.PCFG = 0b0000; // set all pins as adc input    
}

int __adc_read(int adc_channel) {
    ADCON0bits.ADON = 1; // turn on a/d module
    ADCON0bits.CHS = adc_channel; // turn on adc channel
    __delay_ms(10); // wait for capacitors to charge up
    ADCON0bits.GO = 1; // begin conversion
    while(ADCON0bits.GO_DONE == 1) {
        // wait for conversion to finish
    }
    int adc_value = (ADRESH << 8) + (ADRESL);
    return adc_value;
}

void main(void) {
    __init_adc();
    __init_usart();
    __set_baud_rate(BAUD_RATE);
    
    while(1) {
        int adc_value = __adc_read(ADC_PIN);
        sprintf(buffer, "Sensor Value = %d", adc_value);
        __usart_write_ln(buffer);
        __delay_ms(1000);
    }
}
