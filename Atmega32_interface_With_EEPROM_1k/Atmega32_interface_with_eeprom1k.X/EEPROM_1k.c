#define F_CPU 16000000UL

#include"EEPROM_1k.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/5/app5.X/MY_SPI.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/DIO.h"

#include<util/delay.h>

void en_write() {
    setPIN(B, SS, HIGH);

    setPIN(B, SS, LOW);
    _delay_ms(1);

    spi_send(WRITE_EN);


    setPIN(B, SS, HIGH);
    _delay_ms(1);

}

void disable_write() {
    setPIN(B, SS, HIGH);

    setPIN(B, SS, LOW);

    _delay_ms(1);

    spi_send(WRITE_DISABLE);


    setPIN(B, SS, HIGH);
    _delay_ms(1);

}

void disable_W_protection() {
    setPIN(B, SS, HIGH);

    setPIN(B, SS, LOW);

    _delay_ms(1);

    spi_send(STATUS_REG_INSTRUCTION_W);

    spi_send(0);


    setPIN(B, SS, HIGH);
    _delay_ms(1);

}

char r_eeprom_1k(char address) {
    setPIN(B, SS, HIGH);

    setPIN(B, SS, LOW);

    _delay_ms(1);

    spi_send(R_INSTRUCTION);

    spi_send(address);

    spi_send(DUMMY_DATA);

    char temp = spi_read();


    setPIN(B, SS, HIGH);
    _delay_ms(1);

    return temp;

}

void w_eeprom_1k(char address, char data) {
    
    en_write();
    _delay_ms(5);

    setPIN(B, SS, HIGH);

    setPIN(B, SS, LOW);
    _delay_ms(1);

    spi_send(W_INSTRUCTION);

    spi_send(address);

    spi_send(data);

    setPIN(B, SS, HIGH);
    _delay_ms(1);

    disable_write();

}