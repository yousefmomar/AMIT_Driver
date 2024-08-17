#include<avr/interrupt.h>
#include<avr/io.h>
#include"My_Interrupt.h"

/**
 * 
 * @param INT_Mode
 * @return void
 */
void int0_mode(char INT_Mode) {

    switch (INT_Mode) {

        case INT_LOW_LEVEL:
            MCUCR &= ~((1 << ISC00) | (1 << ISC01));
            break;

        case INT_ANY_CHANGE:
            MCUCR &= ~(1 << ISC01);
            MCUCR |= (1 << ISC00);
            break;

        case INT_FALLING_EDGE:
            MCUCR &= ~(1 << ISC00);
            MCUCR |= (1 << ISC01);
            break;

        case INT_RISING_EDGE:
            MCUCR |= ((1 << ISC01) | (1 << ISC00));
            break;

        default:
            break;
    }

}
/**
 * 
 * @param INT_Mode
 * @return void
 */
void int1_mode(char INT_Mode) {

    switch (INT_Mode) {

        case INT_LOW_LEVEL:
            MCUCR &= ~((1 << ISC10) | (1 << ISC11));
            break;

        case INT_ANY_CHANGE:
            MCUCR &= ~(1 << ISC11);
            MCUCR |= (1 << ISC10);
            break;

        case INT_FALLING_EDGE:
            MCUCR &= ~(1 << ISC10);
            MCUCR |= (1 << ISC11);
            break;

        case INT_RISING_EDGE:
            MCUCR |= ((1 << ISC11) | (1 << ISC10));
            break;

        default:
            break;
    }

}

void int2_mode(char INT_Mode) {
    
    switch(INT_Mode){
        
        case INT2_FALLING_EDGE:
            MCUCSR &=  ~(1<<ISC2);
            break;
            
        case INT2_RISING_EDGE:
            MCUCSR |= (1<<ISC2);
            break;
            
        default:
            break;
               
    }
      
}

/**
 * 
 * @param INT_Mode
 * @return void
 */
void init_INT0(char INT_Mode) {

    int0_mode(INT_Mode); //Select Mode

    GICR |= (1 << INT0); //Enable INT0

}
/**
 * @return void
 */
void INT0_disable(void) {

    GICR &= ~(1 << INT0); //Disable INT0

}
/**
 * 
 * @param INT_Mode
 * @return void
 */
void INT0_ChangeMode(char INT_Mode) {

    INT0_disable(); //Disable INT0

    int0_mode(INT_Mode); //Select Mode

    GICR |= (1 << INT0); //Enable INT0

}
/**
 * 
 * @param INT_Mode
 * @return void
 */
void init_INT1(char INT_Mode) {

    int1_mode(INT_Mode); //Select Mode

    GICR |= (1 << INT1); //Enable INT1

}
/**
 * @return void
 */
void INT1_disable() {

    GICR &= ~(1 << INT1); //Disable INT1

}
/**
 * 
 * @param INT_Mode
 * @return void
 */
void INT1_ChangeMode(char INT_Mode) {

    INT1_disable(); //Disable INT1

    int1_mode(INT_Mode); //Select Mode

    GICR |= (1 << INT1); //Enable INT1

}

/**
 * 
 * @param INT_Mode
 * @return void
 */
void init_INT2(char INT_Mode) {

    int2_mode(INT_Mode); //Select Mode

    GICR |= (1 << INT2); //Enable INT2

}

/**
 * @return void
 */
void INT2_disable() {

    GICR &= ~(1 << INT2); //Disable INT2

}

/**
 * 
 * @param INT_Mode
 * @return void
 */
void INT2_ChangeMode(char INT_Mode) {

    INT2_disable(); //Disable INT2

    int2_mode(INT_Mode); //Select Mode
    
    GIFR |= (1<<INTF2);
    
    GICR |= (1 << INT2); //Enable INT2

}

/**
 * @return void
 */
void Global_INT_Enable(void){
    
    sei();
    
}

