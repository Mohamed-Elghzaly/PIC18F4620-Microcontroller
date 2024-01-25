/* 
 * File:   ecu_ultrasonic.c
 * Author: Mohamed
 *
 * Created on September 29, 2023, 10:07 AM
 */


#include "ecu_ultrasonic.h"


Std_ReturnType Ultrasonic_Initializaion(const ultrasonic_t *ultrasonic){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == ultrasonic){
        status = E_NOT_OK;
    }
    else{	
        status = gpio_pin_intialize(&(ultrasonic->trigger_pin));
        status = gpio_pin_direction_intialize(&(ultrasonic->eco_pin));
        TIMER1RW_REG_16BIT_MODE_ENABLE;	
        TMR1=0;
        //TIMER1_OFF();
        status = E_OK;
    }
    return status;
}

Std_ReturnType Ultrasonic_Send_Pulse(ultrasonic_t *ultrasonic){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == ultrasonic){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_write_logic(&(ultrasonic->trigger_pin), GPIO_HIGH);
        __delay_us(10);
        status = gpio_pin_write_logic(&(ultrasonic->trigger_pin), GPIO_LOW);
        status = E_OK;
    }
    return status;
}

Std_ReturnType Ultrasonic_Read_Pulse(const ultrasonic_t *ultrasonic, uint32 *Distance){
    Std_ReturnType status = E_NOT_OK;
    sint32 Time = 0;
    logic_t eco_logic = GPIO_LOW;
    if((NULL == ultrasonic) || (NULL == Distance)){
        status = E_NOT_OK;
    }
    else{
        while(eco_logic==0){
            status = gpio_pin_read_logic(&(ultrasonic->eco_pin), &eco_logic);
        }	          
    	TMR1=0;			      
        TIMER1_ON();
    	while(eco_logic==1){
            status = gpio_pin_read_logic(&(ultrasonic->eco_pin), &eco_logic);
        }   
    	Time = TMR1;		   
    	TIMER1_OFF();		
    	*Distance = (uint32)(((float32)Time/117.00));
    	__delay_ms(10);
        status = E_OK;
    }
    return status;
}