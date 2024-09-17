#define F_CPU 16000000UL

#include"EEPROM_1k.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/5/app5.X/MY_SPI.h"
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/DIO.h"

#include<util/delay.h>

//eeprom 1
void en_write() {
    setPIN(C,PC0, HIGH);
    _delay_ms(1);

    setPIN(C,PC0 , LOW);
    _delay_ms(1);

    spi_send(WRITE_EN);


    setPIN(C,PC0 , HIGH);
    _delay_ms(1);

}

void disable_write() {
    setPIN(C, PC0, HIGH);
    _delay_ms(1);

    setPIN(C, PC0, LOW);

    _delay_ms(1);

    spi_send(WRITE_DISABLE);


    setPIN(C, PC0, HIGH);
    _delay_ms(1);

}

void disable_W_protection() {
    setPIN(C, PC0, HIGH);

    setPIN(C, PC0, LOW);

    _delay_ms(1);

    spi_send(STATUS_REG_INSTRUCTION_W);

    spi_send(0);


    setPIN(C, PC0, HIGH);
    _delay_ms(1);

}

char r_eeprom_1k(char address) {
    setPIN(C, PC0, HIGH);
    
    setPIN(C, PC0, LOW);

    _delay_ms(1);

    spi_send(R_INSTRUCTION);

    spi_send(address);

    spi_send(DUMMY_DATA);

    char temp = spi_read();


    setPIN(C, PC0, HIGH);
    _delay_ms(1);

    return temp;

}

void w_eeprom_1k(char address, char data) {

    en_write();
    _delay_ms(5);

    setPIN(C, PC0, HIGH);

    setPIN(C, PC0, LOW);
    _delay_ms(1);

    spi_send(W_INSTRUCTION);

    spi_send(address);

    spi_send(data);

    setPIN(C, PC0, HIGH);
    _delay_ms(1);

    disable_write();

}

//eeprom 2
void en2_write() {
    setPIN(C,PC1, HIGH);

    setPIN(C,PC1 , LOW);
    _delay_ms(1);

    spi_send(WRITE_EN);


    setPIN(C,PC1 , HIGH);
    _delay_ms(1);

}

void disable2_write() {
    setPIN(C, PC1, HIGH);

    setPIN(C, PC1, LOW);

    _delay_ms(1);

    spi_send(WRITE_DISABLE);


    setPIN(C, PC1, HIGH);
    _delay_ms(1);

}

void disable2_W_protection() {
    setPIN(C, PC1, HIGH);

    setPIN(C, PC1, LOW);

    _delay_ms(1);

    spi_send(STATUS_REG_INSTRUCTION_W);

    spi_send(0);


    setPIN(C, PC1, HIGH);
    _delay_ms(1);

}

char r_eeprom2_1k(char address) {
    setPIN(C, PC1, HIGH);
    
    setPIN(C, PC1, LOW);

    _delay_ms(1);

    spi_send(R_INSTRUCTION);

    spi_send(address);

    spi_send(DUMMY_DATA);

    char temp = spi_read();


    setPIN(C, PC1, HIGH);
    _delay_ms(1);

    return temp;

}

void w_eeprom2_1k(char address, char data) {

    en2_write();
    _delay_ms(5);

    setPIN(C, PC1, HIGH);

    setPIN(C, PC1, LOW);
    _delay_ms(1);

    spi_send(W_INSTRUCTION);

    spi_send(address);

    spi_send(data);

    setPIN(C, PC1, HIGH);
    _delay_ms(1);

    disable2_write();

}

