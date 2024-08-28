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
#ifndef MY_TIMERCOUNTER_H
#define	MY_TIMERCOUNTER_H

#include <xc.h> // include processor files - each processor file is guarded. 

//mode MACROS
#define NORMAL_MODE   0
#define PWM_MODE      1
#define CTC_MODE      2
#define FAST_PWM_MODE 3

//Clock DIV for Timer 0  MACROS
#define TIMER0_NO_CLK             0
#define TIMER0_MC_CLK             1
#define TIMER0_MC_CLK_8           2
#define TIMER0_MC_CLK_64          3
#define TIMER0_MC_CLK_265         4
#define TIMER0_MC_CLK_1024        5
#define TIMER0_EXT_CLK_FALLING    6
#define TIMER0_EXT_CLK_RISING     7

//Clock DIV for Timer 2  MACROS
#define TIMER2_NO_CLK             0
#define TIMER2_MC_CLK             1
#define TIMER2_MC_CLK_8           2
#define TIMER2_MC_CLK_32          3
#define TIMER2_MC_CLK_64          4
#define TIMER2_MC_CLK_128         5
#define TIMER2_MC_CLK_265         6
#define TIMER2_MC_CLK_1024        7


//Define OC0,OC2 pin
#define OC0 PB3
#define OC2 PD7

//CTC MODES MACROS TIMER0,2
#define CTC_DISABLE 0
#define CTC_TOGGLE  1
#define CTC_CLEAR   2
#define CTC_SET     3 

//PHASE CORRECT WITH PWM MODES MACROS TIMER0,2
#define PWM_DISABLE       0
#define PWM_ClearUpCount  2
#define PWM_SetUpCount    3 

//FAST PWM TIMER0,2  MACROS
#define FPWM_DISABLE     0
#define FPWM_ClearOnComp 2
#define FPWM_SetOnComp   3

//Sync & Async modes in timer2 change
#define Sync_To_Async 0
#define ASync_To_sync 1

//functions Timer0
void init_Timer0_WithOCR0(char Mode, char clk, char OCR0_Val);
void Timer0_setClk(char clk);
void Timer0_setMode(char Mode);
void Timer0_INT_EN_OCM(void);
void Timer0_INT_EN_TOVF(void);
void Timer0_INT_DISABLE_OCM(void);
void Timer0_INT_DISABLE_TOVF(void);
void Timer0_COMP_MODE(char OC0_MODE);
void Timer0_init_OC0();
void Change_OCR0(char OCR0_TOP_VAL);
void initNormalMode_Timer_Counter0(char clk);

//functions Timer2
void init_Timer2_WithOCR2(char Mode, char clk, char OCR2_Val);
void Timer2_setClk(char clk);
void Timer2_setMode(char Mode);
void Timer2_INT_EN_OCM(void);
void Timer2_INT_EN_TOVF(void);
void Timer2_INT_DISABLE_OCM(void);
void Timer2_INT_DISABLE_TOVF(void);
void Timer2_COMP_MODE(char OC2_MODE);
void Timer2_init_OC2();
void Change_OCR2(char OCR2_TOP_VAL);
void initNormalMode_Timer_Counter2(char clk);
void CLear_Timer2_Flags();
void WAIT_UNTIL_LOAD_DATA_TIMER2();
void ChangeBet_SyncAsync(char SyncAsync)

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#endif	/* MY_TIMERCOUNTER_H */

