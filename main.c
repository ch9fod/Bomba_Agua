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

__CONFIG(FOSC_INTOSCIO & WDTE_OFF & CP_OFF  & PWRTE_OFF & IOSCFS_8MHZ);//MCLRE_OFF

#ifndef _XTAL_FREQ
 // Unless already defined assume 4MHz system frequency
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 8000000
#endif


unsigned char cnt=0,i,j;
bit in;

void delay_1s ()
{
    for (i=0; i<100; i++)
        for (j=0; j<10; j++)
            __delay_ms(1);
}

void main(void) {
    nGPPU = 0;  //Global pullups enabled
    WPU2 = 1;   //Pullup on GPIO2 enabled
    TRISIO = 4; //GPIO2 input
    INTEDG = 0; //falling edge external interrupt on GPIO2
    INTE = 1;   //External interrupt on GPIO2 enabled

    GP4 = 1;
    delay_1s();
    GP4 = 0;
    delay_1s();
    GP4 = 1;
    delay_1s();
    GP4 = 0;
    delay_1s();

    SLEEP();
    NOP();
    
    while(1){
        GP4 = 1;
        delay_1s();
        GP4 = 0;
        delay_1s();
        INTF = 0;   //Clear External interrupt flag
        INTE = 1;   // Enable external interrupt INT
        SLEEP();
        NOP();

    }
}


