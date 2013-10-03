/******************************************************************
 * Robotics team Software Tutorial 2013 #1						  * 
 * Task 2: change state of LED(RED) when button(up) is triggered  *
 ******************************************************************/

#include "main.h"
 
#define BUT_UP  GPIO_Pin_7
#define LED_ON 0
#define LED_OFF 1
#define LED_RED GPIO_Pin_6
u8 temp = 0;
 
void button_init(void){
 
    GPIO_InitTypeDef GPIO_InitStructure;
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);    
 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;              
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Pin = BUT_UP; 
    GPIO_Init(GPIOF, &GPIO_InitStructure);
}
 
void led_init(void){
 
    GPIO_InitTypeDef LED_InitStructure;
   
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE); 
 
    LED_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;            
    LED_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    LED_InitStructure.GPIO_Pin = GPIO_Pin_6;                                
    GPIO_Init(GPIOG, &LED_InitStructure);
	
	  GPIO_SetBits(GPIOG, LED_RED);                   // Set Red LED off at default init state
}
 
int main(void){ 
    button_init();    
    led_init();
  /* Infinite loop */
    while(1){   
        if(!GPIO_ReadInputDataBit(GPIOF,BUT_UP)){
          while(!GPIO_ReadInputDataBit(GPIOF,BUT_UP));    // Waiting button release 
					
					/* Solution 1*/
					GPIO_ResetBits(GPIOG, LED_RED);                 // Red LED On
					_delay_ms(1000);                                // delay 1 seconds
					GPIO_SetBits(GPIOG, LED_RED);                   // Red LED Off
					
					/* Solution 2*/
					/*
					GPIO_WriteBit(GPIOG, LED_RED, 0);                // Red LED On
					_delay_ms(1000);  												 	  	 // delay 1 seconds
					GPIO_WriteBit(GPIOG, LED_RED, 1);                // Red LED off
					*/
					
        }
        
    }
    return 0;
}
