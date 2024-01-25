/* 
 * File:   ecu_button.c
 * Author: Mohamed
 *
 * Created on September 5, 2023, 2:21 PM
 */
#include "ecu_button.h"

Std_ReturnType button_inialize(const button_t *btn){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == btn){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_direction_intialize(&(btn->button_pin));
    }
    return status;
}

Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state){
    Std_ReturnType status = E_NOT_OK;
    logic_t Pin_Logic_Status = GPIO_LOW;
    if((NULL == btn) || (NULL == btn_state)){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_read_logic(&(btn->button_pin), &Pin_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == btn->button_active){
            if(GPIO_HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_active){
            if(GPIO_LOW == Pin_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else{/* Nothing */}
        status = E_OK;
    }
    return status;
}
