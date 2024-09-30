/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MY_I2C_H
#define	MY_I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include<avr/io.h>

#define ACCESS_I2C_CONTROL_REG (1<<TWINT)|(1<<TWEN)

#define ERROR -1

#define I2C_CLK_1       0
#define I2C_CLK_4       1
#define I2C_CLK_16      2
#define I2C_CLK_64      3

//MT STATUS CODES MACROS
#define START_CONDITION      0x08
#define REP_START_CONDITION  0x10
#define MT_SLA_ACK           0x18
#define MT_SLA_NOT_ACK       0x20
#define MT_DATA_ACK          0x28
#define MT_DATA_NOT_ACK      0x30
#define MT_ARBITIRATION_LOST 0x38

//MR STATUS CODES MACROS
#define MR_SLA_ACK           0x40
#define MR_SLA_NOT_ACK       0x48
#define MR_DATA_ACK          0x50
#define MR_DATA_NOT_ACK      0x58
#define MR_ARBITIRATION_LOST 0x38

//SR STATUS MACROS CODES
#define SR_SLA_ACK         0x60  // Own SLA+W received, ACK returned
#define SR_ACK_LOST_ARB    0x68  // Arbitration lost in SLA+W,ACK returned
#define SR_GEN_ACK         0x70  // General call received, ACK returned
#define SR_GEN_ARB_LOST    0x78  // Arbitration lost in general call
#define SR_DATA_ACK        0x80  // Data received, ACK returned
#define SR_DATA_NO_ACK     0x88  // Data received, NACK returned
#define SR_GEN_DATA_ACK    0x90  // General call data received, ACK returned
#define SR_GEN_DATA_NO_ACK 0x98 // General call data received, NACK returned
#define SR_STOP            0xA0  // Stop or repeated start condition received

// Slave Transmitter (ST) mode
#define ST_SLA_ACK          0xA8  // Own SLA+R received, ACK returned
#define ST_ACK_LOST_ARB     0xB0  // Arbitration lost in SLA+RW
#define ST_DATA_ACK         0xB8  // Data transmitted, ACK received
#define ST_DATA_NO_ACK      0xC0  // Data transmitted, NACK received
#define ST_LAST_DATA        0xC8  // Last data transmitted, ACK received

// Miscellaneous states
#define NO_INFO          0xF8  // No relevant state information
#define BUS_ERROR        0x00  // Bus error due to illegal start/stop condition

void init_I2C(char I2C_ADDRESS,char clk);
char I2C_MT(char SLA,char data);
char I2C_MR(char SLA);

char I2C_ST(char data);
char I2C_SR();

void I2C_INT_EN();

void I2C_SET_CLK(char clk);


#endif	/* MY_I2C_H */

