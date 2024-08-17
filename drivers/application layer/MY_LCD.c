#define F_CPU 16000000UL
#define _OPEN_SYS_ITOA_EXT

#include"MY_LCD.h"
#include<util/delay.h>
#include"DIO.h"
#include"int_to_arr.h"

void LCD_CLEAR() {

    LCD_CMD(CLR);
    _delay_ms(15);
}

void LCD_EN() {

    LCD_CONTROL |= (1 << EN);
    _delay_us(50);
    LCD_CONTROL &= ~(1 << EN);
}

void LCD_CMD(char cmd) {

    //set RS to 0
    LCD_CONTROL &= ~(1 << RS);
    LCD_DATA = cmd;

    LCD_EN();
    _delay_ms(15);

}

void init_LCD() {

    //DIO

    setPort_dir(A, OUT);
    setPort_dirVal(B, ((1 << RS) | (1 << RW) | (1 << EN)), OUT);

    //LCD setup
    setPIN(B, (1 << RW), LOW); //write mode
    //Return Home
    LCD_CMD(RET_HOME);
    //set mode
    LCD_CMD(_8Bits_Mode);
    //set cursor and display
    LCD_CMD(CUR_OFF_DISP_ON);
    //CLEAR
    LCD_CLEAR();
    //entry mode
    LCD_CMD(Entry_Mode);



}

void LCD_data(char data) {

    LCD_CONTROL |= (1 << RS);
    LCD_DATA = data;

    LCD_EN();
}

void LCD_WRITE(char* str) {

    for (int i = 0; str[i] != '\0'; i++) {
        LCD_data(str[i]);
    }

}

void LCD_WRITE_NUM(int num) {

    char str[11];
    itoa(num, str);
    LCD_WRITE(str);

}



