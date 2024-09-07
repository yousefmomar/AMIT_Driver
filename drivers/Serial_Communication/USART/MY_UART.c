#define F_CPU 16000000UL 

#include<avr/io.h>
#include"MY_UART.h"
#include<util/delay.h>


//void BaudRate_X2_U();
//void BaudRate_X2_X1(char X2_X1);

char WAIT_UNTIL_UDRisNOT_EMPTY() {

    while (!(UCSRA & (1 << UDRE)));

}

char WAIT_UNTIL_RX_ALL_SHIFTED() {

    while (!(UCSRA & (1 << RXC)));

}

void UDREF_INT_EN() {

    UCSRB |= (1 << UDRIE);

}

void RXF_INT_EN() {

    UCSRB |= (1 << RXCIE);

}
//void Set_StopBitsNum_U(char StopBitsNum);

void SetBaudRate_U(int BaudRate) {

    short temp = (F_CPU / 16.0 / BaudRate) - 1;

    UBRRL = temp;
    UBRRH = (temp >> 8);


}
//void SetDataSize_U(char size);
//void SetClkMode_U(char clkMode);
//void SetParityMode_U(char Parity);

void RX_TX_MODE(char RX_TX) {

    UCSRB |= (RX_TX << 3);

}

void init_UART(int BaudRate, char RX_TX) {

    //    SetClkMode_U(clkMode);
    //    _delay_us(5);
    //
    //    Set_StopBitsNum_U(StopBitsNum);
    //    _delay_us(5);

    SetBaudRate_U(BaudRate);
    _delay_us(5);

    //    SetParityMode_U(Parity);
    //    _delay_us(5);

    //    SetDataSize_U(size);
    //    _delay_us(5);

    RX_TX_MODE(RX_TX);
    _delay_us(5);

    //    BaudRate_X2_X1(X2_X1);
    //    _delay_us(5);

    switch (RX_TX) {

        case FULL_DUPLEX_UART:
            UDREF_INT_EN();
            RXF_INT_EN();
            break;

        case TRANSMIT_ONLY_UART:
            UDREF_INT_EN();
            break;

        case RECIEVE_ONLY_UART:
            RXF_INT_EN();
            break;

        default:
            break;

    }

}

void UART_SEND(char data) {

    WAIT_UNTIL_UDRisNOT_EMPTY();

    UDR = data;

}

void UART_SEND_STR(char* str) {

    for (int i = 0; str[i] != '\0'; i++) {
        UART_SEND(str[i]);
        _delay_ms(50);
    }

}

char UART_RECEIVE() {

    WAIT_UNTIL_RX_ALL_SHIFTED();

    return UDR;

}

