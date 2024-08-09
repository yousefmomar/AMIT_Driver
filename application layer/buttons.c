#include"DIO.h"
#include"buttons.h"

void init_Buttons(void){
    
    setPIN_dir(B,BUTTON0,IN);
    setPIN_dir(D,BUTTON1,IN);
    setPIN_dir(D,BUTTON2,IN);

    
}
char isPressed(char B_NUM){
    
    char flag=0;
    
    if(B_NUM==BUTTON0)
    {
        if(readPIN(B,B_NUM)){
            
            flag=1;
            
        }
    }
    else if(B_NUM==BUTTON1 || B_NUM==BUTTON2){
        
        if(readPIN(D,B_NUM)){
            
            flag=1;
            
        }
        
    }
    
    return flag;
    
}
