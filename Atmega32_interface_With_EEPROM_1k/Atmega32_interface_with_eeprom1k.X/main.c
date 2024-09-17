/*
 * File:   main.c
 * Author: yousefmahmoud
 *
 * Created on September 15, 2024, 2:30 PM
 */

#define F_CPU 16000000UL 

#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/5/app5.X/MY_SPI.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/DIO.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/MY_LCD4.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/My_Interrupt.h"

#include "EEPROM_1k.h"

#include<util/delay.h>
#include <avr/io.h>
#include<avr/interrupt.h>

ISR(INT0_vect) {

    static char indicator = 0;

    if (indicator == 0) {

        char a = r_eeprom_1k(0x12);
        _delay_ms(10);
        indicator++;


        LCD4_WRITE(a);
        _delay_ms(500);


    } else if (indicator == 1) {

        char b = r_eeprom2_1k(0x12);
        _delay_ms(10);
        indicator = 0;


        LCD4_WRITE(b);
        _delay_ms(500);

    }

}

int main(void) {
    /* Replace with your application code */

    setPIN_dir(C, PC0, OUT);
    setPIN_dir(C, PC1, OUT);

    init_spi(MASTER_SPI, SPI_CLK_64, SPI_CLK_X2_NOT_NEEDED, FROM_MSB);
    _delay_ms(25);

    init_LCD4();
    _delay_ms(25);

    init_INT0(INT_RISING_EDGE);
    _delay_ms(5);
    Global_INT_Enable();


    disable_W_protection();
    _delay_ms(25);
    
    disable2_W_protection();
    _delay_ms(25);
    

    w_eeprom_1k(0x12, 'A');
    _delay_ms(500);

    w_eeprom2_1k(0x12, 'B');
    _delay_ms(500);


    while (1) {

        _delay_ms(5);
    }
}
