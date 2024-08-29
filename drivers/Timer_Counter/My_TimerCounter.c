#include<avr/io.h>
#include <util/delay.h>
#include"/Users/yousefmahmoud/Desktop/Studying/Embedded_Diploma_AMIT/EmbeddedC_codes/1/app1.X/My_TimerCounter.h"
#include "DIO.h"

/**
 * @return void
 * @param clk : division clock of MC by 1,8,64,265,1024, external clock or turn off timer 
 */
void Timer0_setClk(char clk) {

    TCCR0 &= ~((1 << CS00) | (1 << CS01) | (1 << CS02)); //clearing clk bits
    _delay_us(10);

    TCCR0 |= clk;

}

/**
 * @return void
 * @param Mode : normal,ctc,pwm,fast pwm
 */
void Timer0_setMode(char Mode) {

    TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
    _delay_us(10);

    switch (Mode) {

        case NORMAL_MODE:
            TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
            break;

        case PWM_MODE:
            TCCR0 |= (1 << WGM00);
            break;

        case CTC_MODE:
            TCCR0 |= (1 << WGM01);
            break;

        case FAST_PWM_MODE:
            TCCR0 |= ((1 << WGM00) | (1 << WGM01));
            break;

        default:
            break;

    }

}

/**
 * Function to Enable overflow interrupt timer0
 */
void Timer0_INT_EN_TOVF() {

    TIMSK |= (1 << TOIE0);

}

/**
 * Function to Enable O/P compare match interrupt timer0
 */
void Timer0_INT_EN_OCM() {

    TIMSK |= (1 << OCIE0);

}

/**
 * 
 * @param OC0_MODE
 * @return void
 */
void Timer0_COMP_MODE(char OC0_MODE) {

    TCCR0 &= ~((1 << COM00) | (1 << COM01));
    _delay_us(10);

    TCCR0 |= (OC0_MODE << 4);

}

/**
 * set direction of OC0 pin & select mode
 * @param MODE : mode of ctc
 * @return void
 */
void Timer0_init_OC0() {

    setPIN_dir(B, OC0, OUT);
    _delay_us(10);


}

/**
 * @return void
 * @param OCR0_TOP_VAL
 */
void Change_OCR0(char OCR0_TOP_VAL) {

    OCR0 = OCR0_TOP_VAL;

}

/**
 * @return void
 * @param Mode :PWM,FAST PWM,CTC modes
 * @param clk
 */
void init_Timer0_WithOCR0(char Mode, char clk, char OCR0_Val) {


    Timer0_setMode(Mode);

    _delay_ms(10);
    Change_OCR0(OCR0_Val);

    switch (Mode) {


        case FAST_PWM_MODE:
            Timer0_INT_EN_TOVF();
            Timer0_INT_EN_OCM();
            break;

        case PWM_MODE:
        case CTC_MODE:
            Timer0_INT_EN_OCM();
            break;

        default:
            break;
    }

    _delay_ms(5);
    Timer0_setClk(clk);


}

/**
 * @return void
 * @param clk
 */
void initNormalMode_Timer_Counter0(char clk) {


    Timer0_setMode(NORMAL_MODE);


    Timer0_INT_EN_TOVF();

    _delay_ms(10);

    Timer0_setClk(clk);


}

////////////////////////////////////////////////////TIMER2//////////////////////////////////////////////

/**
 * @return void
 * @param clk : division clock of MC by 1,8,32,64,128,265,1024 
 */
void Timer2_setClk(char clk) {

    TCCR2 &= ~((1 << CS20) | (1 << CS21) | (1 << CS22)); //clearing clk bits
    _delay_us(10);

    TCCR2 |= clk;

}

/**
 * @return void
 * @param Mode : normal,ctc,pwm,fast pwm
 */
void Timer2_setMode(char Mode) {

    TCCR2 &= ~((1 << WGM20) | (1 << WGM21));
    _delay_us(10);

    switch (Mode) {

        case NORMAL_MODE:
            TCCR2 &= ~((1 << WGM20) | (1 << WGM21));
            break;

        case PWM_MODE:
            TCCR2 |= (1 << WGM20);
            break;

        case CTC_MODE:
            TCCR2 |= (1 << WGM21);
            break;

        case FAST_PWM_MODE:
            TCCR2 |= ((1 << WGM20) | (1 << WGM21));
            break;

        default:
            break;

    }

}

/**
 * Function to Enable overflow interrupt timer2
 */
void Timer2_INT_EN_TOVF() {

    TIMSK |= (1 << TOIE2);

}

/**
 * Function to Enable O/P compare match interrupt timer2
 */
void Timer2_INT_EN_OCM() {

    TIMSK |= (1 << OCIE2);

}

/**
 * 
 * @param OC2_MODE
 * @return void
 */
void Timer2_COMP_MODE(char OC2_MODE) {

    TCCR2 &= ~((1 << COM20) | (1 << COM21));
    _delay_us(10);

    TCCR2 |= (OC2_MODE << 4);

}

/**
 * set direction of OC2 pin & select mode
 * @param MODE : mode of ctc
 * @return void
 */
void Timer2_init_OC2() {

    setPIN_dir(D, OC2, OUT);
    _delay_us(10);


}

/**
 * @return void
 * @param OCR2_TOP_VAL
 */
void Change_OCR2(char OCR2_TOP_VAL) {

    OCR2 = OCR2_TOP_VAL;

}

/**
 * @return void
 * @param Mode :PWM,FAST PWM,CTC modes
 * @param clk
 */
void init_Timer2_WithOCR2(char Mode, char clk, char OCR2_Val) {


    Timer2_setMode(Mode);

    _delay_ms(10);
    Change_OCR2(OCR2_Val);

    switch (Mode) {


        case FAST_PWM_MODE:
            Timer2_INT_EN_TOVF();
            Timer2_INT_EN_OCM();
            break;

        case PWM_MODE:
        case CTC_MODE:
            Timer2_INT_EN_OCM();
            break;

        default:
            break;
    }

    _delay_ms(5);
    Timer2_setClk(clk);


}

/**
 * @return void
 * @param clk
 */
void initNormalMode_Timer_Counter2(char clk) {


    Timer2_setMode(NORMAL_MODE);


    Timer2_INT_EN_TOVF();

    _delay_ms(10);

    Timer2_setClk(clk);


}

void Timer2_INT_DISABLE_OCM(void) {

    TIMSK &= ~(1 << OCIE2);

}

void Timer2_INT_DISABLE_TOVF(void) {

    TIMSK &= ~(1 << TOIE2);

}

void WAIT_UNTIL_LOAD_DATA_TIMER2() {

    while (!(ASSR & (1 << TCN2UB)));
    while (!(ASSR & (1 << TCR2UB)));
    while (!(ASSR & (1 << OCR2UB)));


}

void Clear_Timer2_Flags() {

    TIFR &= ~((1 << OCF2) | (1 << TOV2));

}

void ChangeBet_SyncAsync(char SyncAsync, char TCNT2_VAL, char Mode, char clk, char OCR2_Val, char OCR2_VAL) {

    Timer2_INT_DISABLE_OCM();
    Timer2_INT_DISABLE_TOVF();

    switch (SyncAsync) {

        case ASync_To_sync:
            ASSR &= ~(1 << AS2);

            TCNT2 = TCNT2_VAL;

            switch (Mode) {

                case NORMAL_MODE:
                    initNormalMode_Timer_Counter2(clk);
                    Change_OCR2(0);
                    break;

                case PWM_MODE:
                case FAST_PWM_MODE:
                case CTC_MODE:
                    init_Timer2_WithOCR2(Mode, clk, OCR2_VAL);
                    break;

                default:
                    break;


            }
            
            Clear_Timer2_Flags();

            break;

        case Sync_To_Async:
            ASSR |= (1 << AS2);
            TCNT2 = TCNT2_VAL;

            switch (Mode) {

                case NORMAL_MODE:
                    initNormalMode_Timer_Counter2(clk);
                    Change_OCR2(0);
                    break;

                case PWM_MODE:
                case FAST_PWM_MODE:
                case CTC_MODE:
                    init_Timer2_WithOCR2(Mode, clk, OCR2_VAL);
                    break;

                default:
                    break;


            }
            
            WAIT_UNTIL_LOAD_DATA_TIMER2();
            
            Clear_Timer2_Flags();
            break;

    }

}