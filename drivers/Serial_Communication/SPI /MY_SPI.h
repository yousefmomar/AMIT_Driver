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
#ifndef MY_SPI_H
#define	MY_SPI_H

#include <xc.h> // include processor files - each processor file is guarded.  

//SPI PINS MACROS
#define MOSI PB5
#define MISO PB6
#define SS   PB4
#define SCK  PB7

#define MASTER_SPI 1
#define SLAVE_SPI  0

//CLK SPI MACROS
#define SPI_CLK_4   0
#define SPI_CLK_16  1
#define SPI_CLK_64  2
#define SPI_CLK_128 3

//CLK X2
#define SPI_CLK_X2_NEEDED     1
#define SPI_CLK_X2_NOT_NEEDED 0

//DATA DIRECTION SHIFT
#define FROM_MSB 0
#define FROM_LSB 1

void init_spi(char M_or_S,char clk,char clk_X2,char MSB_or_LSB);
void SetClk_spi(char clk,char clk_X2);
void SetData_dir(char MSB_or_LSB);
void spi_INT_EN();
char spi_read();
void spi_send(char data);

#endif	/* MY_SPI_H */

