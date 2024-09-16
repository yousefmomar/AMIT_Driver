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
#include "EEPROM_1k.h"

#include<util/delay.h>
#include <avr/io.h>

int main(void) {
    /* Replace with your application code */
    DDRC = 0xFF;
    DDRD = 0xFF;

    init_spi(MASTER_SPI, SPI_CLK_64, SPI_CLK_X2_NOT_NEEDED, FROM_MSB);
    _delay_ms(25);

    init_LCD4();
    _delay_ms(25);

    disable_W_protection();

    w_eeprom_1k(0x12, 'A');
    _delay_ms(10);

    w_eeprom_1k(0x13, 'B');
    _delay_ms(10);

    w_eeprom_1k(0x14, 'C');
    _delay_ms(10);
    

    char a = r_eeprom_1k(0x12);
    _delay_ms(10);

    char b = r_eeprom_1k(0x13);
    _delay_ms(10);

    char c = r_eeprom_1k(0x14);
    _delay_ms(10);


    while (1) {

        LCD4_WRITE(a);
        PORTC = a;
        _delay_ms(500);

        LCD4_WRITE(b);
        PORTD = b;
        _delay_ms(500);

        LCD4_WRITE(c);
        PORTC = c;
        _delay_ms(500);
        //        
        //        LCD4_WRITE('5');
        //        _delay_ms(500);

        char i = 0;
        i++;

        if (i == 1)
            break;
    }
}
