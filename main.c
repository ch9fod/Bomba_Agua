/*
 * File:   main.c
 * Author: Ch9FOD
 *
 * Created on April 8, 2012, 12:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <htc.h>           /* Global Header File */
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <pic12f609.h>

__CONFIG(FOSC_INTOSCIO & WDTE_OFF & CP_OFF & MCLRE_OFF & PWRTE_OFF & IOSCFS_8MHZ);

#ifndef _XTAL_FREQ
 // Unless already defined assume 4MHz system frequency
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 8000000
#endif
unsigned char cnt=0;
bit in;
    /*GPIO =  (buff = ~buff); //All on
    __delay_ms(255);*/
void main(void) {
    nGPPU = 1;  //Global pullups enabled
    WPU2 = 1;   //Pullup on GPIO2 enabled
    TRISIO = 4; //GPIO2 input
    INTEDG = 0; //falling edge external interrupt on GPIO2
//    IOC2 = 1;   //Interrupt on change enabled GPIO2
    INTE = 1;   //External interrupt on GPIO2 enabled
//    ei();       //Global interrupts enabled
    SLEEP();
    NOP();
}

void interrupt ISR(){   // ISR
    if(T0IF == 1){      //If Timer0 Flag enabled
        T0IF = 0;       //Clear T0 Interrupt
        in = 1;         //Enable internal flag
        TMR0 = 55;     // for 0.1ms delay (more or less)
    }
}


