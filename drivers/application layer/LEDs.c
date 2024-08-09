#include"DIO.h"
#include"LEDs.h"

void initLEDs(void){
    
    setPIN_dir(C,LED0,OUT);
    setPIN_dir(C,LED1,OUT);
    setPIN_dir(D,LED2,OUT);
    
}

void LED_ON(char LED_NUM){
    
    if(LED_NUM==LED0 || LED_NUM==LED1){
        
        setPIN(C,LED_NUM,HIGH);
    }
    else if (LED_NUM==LED2)
    {
        setPIN(D,LED_NUM,HIGH);
    }
    
    
    
}

void LED_OFF(char LED_NUM){
    
    if(LED_NUM==LED0 || LED_NUM==LED1){
        
        setPIN(C,LED_NUM,LOW);
    }
    else
    {
        setPIN(D,LED_NUM,LOW);
    }
    
}
