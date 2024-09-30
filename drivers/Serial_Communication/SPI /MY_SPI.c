#define F_CPU 16000000UL

#include<util/delay.h>
#include<avr/io.h>

#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/DIO.h"
#include"MY_SPI.h"

void init_spi(char M_or_S, char clk, char clk_X2, char MSB_or_LSB) {

    switch (M_or_S) {

        case MASTER_SPI:
            SPCR |= (1 << MSTR);
            setPort_dirVal(B, ((1 << MOSI) | (1 << SCK) | (1 << SS)), OUT);
            SetClk_spi(clk, clk_X2);
            _delay_us(5);
            break;

        case SLAVE_SPI:
            SPCR &= ~(1 << MSTR);
            setPort_dirVal(B, ((1 << MISO)), OUT);
            break;

        default:
            break;

    }

    SetData_dir(MSB_or_LSB);
    _delay_us(5);
    
    SPCR |= (1 << SPE);

}

void SetClk_spi(char clk, char clk_X2) {

    SPCR |= (clk);

    if (clk_X2) {

        SPSR |= (clk_X2);

    }

}

void SetData_dir(char MSB_or_LSB) {

    switch (MSB_or_LSB) {

        case FROM_MSB:
            SPCR &= ~(1 << DORD);
            break;

        case FROM_LSB:
            SPCR |= (1 << DORD);
            break;

        default:
            break;

    }

}

void spi_INT_EN() {

    SPCR |= (1 << SPIE);

}

char spi_read() {

    while (!(SPSR & (1 << SPIF)));
    return SPDR;

}

void spi_send(char data) {

    SPDR = data;
    while (!(SPSR & (1 << SPIF)));

}