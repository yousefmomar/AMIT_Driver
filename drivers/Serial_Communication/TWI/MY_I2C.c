
#define F_CPU 16000000UL

#include<avr/io.h>
#include<util/delay.h>

#include"MY_I2C.h"

void init_I2C(char I2C_ADDRESS, char clk) {

    TWAR = I2C_ADDRESS;
    TWBR = clk;

}

char I2C_MT(char SLA, char data) {

    //start condition
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWSTA);
    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    if ((TWSR & 0xF8) != START_CONDITION) {

        return ERROR;
    } else {
        //Sending SLave Address
        TWDR = SLA;

    }

    TWCR = ACCESS_I2C_CONTROL_REG;

    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    if ((TWSR & 0xF8) != MT_SLA_ACK || (TWSR & 0xF8) == MT_SLA_NOT_ACK) {

        return ERROR;
    } else {
        //Sending SLave the data
        TWDR = data;

    }

    TWCR = ACCESS_I2C_CONTROL_REG;
    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    if ((TWSR & 0xF8) != MT_DATA_ACK || (TWSR & 0xF8) == MT_DATA_NOT_ACK) {

        return ERROR;
    }

    //Send Stop bit
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWSTO);
    while (TWCR & (1 << TWSTO)); // Wait until stop condition is executed


    return 1;
}

char I2C_MR(char SLA) {

    char data;

    //start condition
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWSTA);

    //wait for flag to be 1 (data bus is free after sending all data)
    while (!(TWCR & (1 << TWINT)));

    if ((TWSR & 0xF8) != START_CONDITION) {

        return ERROR;
    } else {
        //Sending SLave Address + R
        TWDR = SLA;

    }

    //En TWI
    TWCR = ACCESS_I2C_CONTROL_REG;

    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    //Check for SLA+R ACK
    if ((TWSR & 0xF8) != MR_SLA_ACK || (TWSR & 0xF8) == MR_SLA_NOT_ACK) {

        return ERROR;
    }

    //enable ACK (for next data byte) BEFORE reading data
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWEA);
    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    //Check for DATA ACK
    if ((TWSR & 0xF8) != MR_DATA_ACK || (TWSR & 0xF8) == MR_DATA_NOT_ACK) {

        return ERROR;
    }

    data = TWDR;

    //send stop condition
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWSTO);
    while (TWCR & (1 << TWSTO)); // Wait until stop condition is executed

    return data;

}

char I2C_SR() {
    //Ready to Receive my Address ACK
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWEA);

    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    if ((TWSR & 0xF8) == SR_SLA_ACK || (TWSR & 0xF8) == SR_GEN_ACK) {

        //Ready to Receive data ACK
        TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWEA);

        //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
        while (!(TWCR & (1 << TWINT)));

        if ((TWSR & 0xF8) != SR_DATA_ACK || (TWSR & 0xF8) != SR_GEN_DATA_ACK
                || (TWSR & 0xF8) == SR_DATA_NO_ACK || (TWSR & 0xF8) == SR_GEN_DATA_NO_ACK) {

            return ERROR;
        }
    }


    return TWDR;
}

char I2C_ST(char data) {

    //Ready to Receive my Address ACK
    TWCR = ACCESS_I2C_CONTROL_REG | (1 << TWEA);

    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));

    //Check if ACK is sent
    if ((TWSR & 0xF8) != ST_SLA_ACK) {
        return ERROR;
    }

    //sending data
    TWDR = data;

    //wait until acknowledge is sent from master that the data has been received
    TWCR = ACCESS_I2C_CONTROL_REG;
    //wait for flag to be 1 This bit is set by hardware when the TWI has finished its current job and expects application software response
    while (!(TWCR & (1 << TWINT)));
    
    //Check if ACK is sent from master
    if ((TWSR & 0xF8) != ST_DATA_ACK || (TWSR & 0xF8) != ST_DATA_NO_ACK ) {
        return ERROR;
    }
    
    return 1; //return 1 if the transmit process is a success

}

void I2C_INT_EN(){
    TWCR |= (1<<TWIE);
}

void I2C_SET_CLK(char clk){
    //reset them first
    TWSR &= ~( (1<<TWPS0) | (1<<TWPS1));
    
    switch (clk){
        case (I2C_CLK_1):
            TWSR |= clk;
            break;
        case(I2C_CLK_4):
            TWSR |= clk;
            break;
        case(I2C_CLK_16):
            TWSR |= clk;
            break;
        case(I2C_CLK_64):
            TWSR |= clk;
            break;
    }
}