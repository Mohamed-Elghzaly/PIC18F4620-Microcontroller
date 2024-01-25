/* 
 * File:   ecu_relay.c
 * Author: Mohamed
 *
 * Created on September 6, 2023, 12:59 PM
 */

#include "ecu_relay.h"

/**
 * 
 * @param _relay : pointer to relay module configuration
 * @return status of the function
 *          (E_OK)     : function done successfully
 *          (E_NOT_OK) : function has issue
 */
Std_ReturnType relay_intialize(const relay_t *_relay){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _relay){
        status = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {.port = _relay->port_name, 
                                .pin = _relay->pin, 
                                .direction = GPIO_OUTPUT,
                                .logic = _relay->relay_status};
        status = gpio_pin_intialize(&pin_obj);
    }
    return status;
}
/**
 * 
 * @param _relay : pointer to relay module configuration
 * @return status of the function
 *          (E_OK)     : function done successfully
 *          (E_NOT_OK) : function has issue
 */
Std_ReturnType relay_on(const relay_t *_relay){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _relay){
        status = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {.port = _relay->port_name, 
                                .pin = _relay->pin, 
                                .direction = GPIO_OUTPUT,
                                .logic = _relay->relay_status};
        status = gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return status;
}
/**
 * 
 * @param _relay : pointer to relay module configuration
 * @return status of the function
 *          (E_OK)     : function done successfully
 *          (E_NOT_OK) : function has issue
 */
Std_ReturnType relay_off(const relay_t *_relay){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _relay){
        status = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = {.port = _relay->port_name, 
                                .pin = _relay->pin, 
                                .direction = GPIO_OUTPUT,
                                .logic = _relay->relay_status};
        status = gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return status;
}


