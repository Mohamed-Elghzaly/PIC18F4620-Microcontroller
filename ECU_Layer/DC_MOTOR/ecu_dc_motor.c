/* 
 * File:   ecu_dc_motor.c
 * Author: Mohamed
 *
 * Created on September 6, 2023, 5:31 PM
 */

#include "ecu_dc_motor.h"

static pin_config_t pin1_motor;
static pin_config_t pin2_motor;

Std_ReturnType dc_motor_intialize(const dc_motor_pin_t *_motor){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _motor){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_intialize(&(_motor->dc_motor[0]));
        status = gpio_pin_intialize(&(_motor->dc_motor[1]));
    }
    return status;
}

Std_ReturnType dc_motor_move_right(const dc_motor_pin_t *_motor){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _motor){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_write_logic(&(_motor->dc_motor[0]), GPIO_HIGH);
        status = gpio_pin_write_logic(&(_motor->dc_motor[1]), GPIO_LOW);
    }
    return status;
}

Std_ReturnType dc_motor_move_left(const dc_motor_pin_t *_motor){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _motor){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_write_logic(&(_motor->dc_motor[0]), GPIO_LOW);
        status = gpio_pin_write_logic(&(_motor->dc_motor[1]), GPIO_HIGH);
    }
    return status;
}

Std_ReturnType dc_motor_stop(const dc_motor_pin_t *_motor){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == _motor){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_write_logic(&(_motor->dc_motor[0]), GPIO_LOW);
        status = gpio_pin_write_logic(&(_motor->dc_motor[1]), GPIO_LOW);
    }
    return status;
}
