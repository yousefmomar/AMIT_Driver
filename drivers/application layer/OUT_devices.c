#include<avr/io.h>
#include"DIO.h"
#include"OUT_devices.h"

void init_relay(){
    
    setPIN_dir(A,relay,OUT);
    
}
void relay_off(){
    
    setPIN(A,relay,OFF);
    
}
void relay_on(){
    
    setPIN(A,relay,ON);
    
}

void init_buzzer(){
    
    setPIN_dir(A,buzzer,OUT);
    
}
void buzzer_off(){
    
    setPIN(A,buzzer,OFF);
    
}
void buzzer_on(){
    
    setPIN(A,buzzer,ON);
    
}
