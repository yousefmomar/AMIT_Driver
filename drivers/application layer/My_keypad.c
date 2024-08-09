#include"DIO.h"
#include"My_keypad.h"
#include<util/delay.h>

void init_keypad() {
    Keypad_PORT_DIR = 0x0E;
    Keypad_PORT |= 0x0E;
}

char readKey() {

    if (readPort(D) & 0x10) {
        Keypad_PORT &= (0xF3); //1111 0011
        _delay_us(500);
        if (readPort(D) & 0xF0) {

            Keypad_PORT |= 0x0E;
            _delay_us(500);

            return 3;

        } else {
            Keypad_PORT |= 0x0E;

            Keypad_PORT &= (0xF5); //1111 0101
            _delay_us(500);

            if (readPort(D) & 0xF0) {

                Keypad_PORT |= 0x0E;
                _delay_us(500);

                return 2;

            } else {
                Keypad_PORT |= 0x0E;
                _delay_us(500);
                return 1;
            }
        }
        _delay_ms(20);

    } else if (readPort(D) & 0x20) {
        Keypad_PORT &= (0xF3); //1111 0011
        _delay_us(500);
        if (readPort(D) & 0xF0) {

            Keypad_PORT |= 0x0E;
            _delay_us(500);

            return 6;

        } else {
            Keypad_PORT |= 0x0E;

            Keypad_PORT &= (0xF5); //1111 0101
            _delay_us(500);

            if (readPort(D) & 0xF0) {

                Keypad_PORT |= 0x0E;
                _delay_us(500);

                return 5;

            } else {
                Keypad_PORT |= 0x0E;
                _delay_us(500);
                return 4;
            }
        }
        _delay_ms(20);
        

    } else if (readPort(D) & 0x40) {
        Keypad_PORT &= (0xF3); //1111 0011
        _delay_us(500);
        if (readPort(D) & 0xF0) {

            Keypad_PORT |= 0x0E;
            _delay_us(500);

            return 9;

        } else {
            Keypad_PORT |= 0x0E;

            Keypad_PORT &= (0xF5); //1111 0101
            _delay_us(500);

            if (readPort(D) & 0xF0) {

                Keypad_PORT |= 0x0E;
                _delay_us(500);

                return 8;

            } else {
                Keypad_PORT |= 0x0E;
                _delay_us(500);
                return 7;
            }
        }
        _delay_ms(20);
        
    } else if (readPort(D) & 0x80) {
        Keypad_PORT &= (0xF3); //1111 0011
        _delay_us(500);
        if (readPort(D) & 0xF0) {

            Keypad_PORT |= 0x0E;
            _delay_us(500);

            return 15;

        } else {
            Keypad_PORT |= 0x0E;

            Keypad_PORT &= (0xF5); //1111 0101
            _delay_us(500);

            if (readPort(D) & 0xF0) {

                Keypad_PORT |= 0x0E;
                _delay_us(500);

                return 14;

            } else {
                Keypad_PORT |= 0x0E;
                _delay_us(500);
                return 13;
            }
        }
        
        _delay_ms(20);

    }

    else {
        _delay_ms(20);
        return 0;
    }

}
