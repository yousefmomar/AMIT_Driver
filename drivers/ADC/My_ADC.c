#include<avr/io.h>

#include"My_ADC.h"

/**
 * 
 * @param freq
 * @return void
 */
void ADC_FreqSelect(char freq) {
    //ADCSRA
    ADCSRA &= ~((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2)); //Clear Freq Selectors

    ADCSRA |= freq;
}

/**
 * @return void
 * @param channel
 */
void ADC_ChannelSelect(char channel) {
    //ADMUX

    ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2)); //clear selection
    if (channel < 8) {

        ADMUX |= channel; //select channel

    }

}

/**
 * @return void
 * @param ref
 */
void ADC_RefSelect(char ref) {

    ADMUX &= ~((1 << REFS1) | (1 << REFS0)); //Clear Reference selectors

    ADMUX |= (ref << 6); //Select Reference


}

/**
 * @return void
 */
void ADC_SC() {

    //Start Conversion
    ADCSRA |= (1 << ADSC);

}

/**
 * @return void
 */
void ADC_EN() {

    //Enable ADC Peripheral
    ADCSRA |= (1 << ADEN);

}

//void ADC_AutoTrig(char Mode) {
//
// ADCSRA |=(1<<ADATE);
//
//
//}

void ADC_INT_EN() {

    //ADC INTERRUPT ENABLE
    ADCSRA |= (1 << ADIE);

}

/**
 * 
 * @param freq
 * @param channel
 * @param ref
 * @return void
 */
void init_ADC(char freq, char channel, char ref) {
    //Select Channel
    ADC_ChannelSelect(channel);

    //Select Ref
    ADC_RefSelect(ref);

    //Select Frequency
    ADC_FreqSelect(freq);

    //Enabling Interrupt for ADC
    ADC_INT_EN();

    //Enable ADC
    ADC_EN();

}

/**
 * @return void
 */
void WAIT_UNTIL_CONV() {

    while (!(ADCSRA & (1 << ADIF)));

}

/**
 * 
 * @param channel
 * @return char
 */
char isChannelSelected(char channel) {

    switch (channel) {

        case 0:

            if (MUX0 == 0 && MUX1 == 0 && MUX2 == 0) {
                return 1;
            } else {
                return 0;
            }

        case 1:

            if (ADMUX & CH1) {
                return 1;
            } else {
                return 0;
            }

        case 2:

            if (ADMUX & CH2) {
                return 1;
            } else {
                return 0;
            }

        case 3:

            if (ADMUX & CH3) {
                return 1;
            } else {
                return 0;
            }

        case 4:

            if (ADMUX & CH4) {
                return 1;
            } else {
                return 0;
            }

        case 5:

            if (ADMUX & CH5) {
                return 1;
            } else {
                return 0;
            }

        case 6:

            if (ADMUX & CH6) {
                return 1;
            } else {
                return 0;
            }

        case 7:

            if (ADMUX & CH7) {
                return 1;
            } else {
                return 0;
            }

        default:
            break;


    }

}


