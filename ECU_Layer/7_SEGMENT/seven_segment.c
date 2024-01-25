/* 
 * File:   seven_segment.c
 * Author: Mohamed
 *
 * Created on September 11, 2023, 1:23 PM
 */

#include "seven_segment.h"

Std_ReturnType seven_segment_inialize(const segment_t *seg){
    Std_ReturnType status = E_NOT_OK;
    if(NULL == seg){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_intialize(&(seg->seven_segment_pin[SEGMENT_PIN0]));
        status = gpio_pin_intialize(&(seg->seven_segment_pin[SEGMENT_PIN1]));
        status = gpio_pin_intialize(&(seg->seven_segment_pin[SEGMENT_PIN2]));
        status = gpio_pin_intialize(&(seg->seven_segment_pin[SEGMENT_PIN3]));
    }
    return status;
}

Std_ReturnType seven_segment_write_number(const segment_t *seg, uint8 number){
    Std_ReturnType status = E_NOT_OK;
    if((NULL == seg) || (number > 9)){
        status = E_NOT_OK;
    }
    else{
        status = gpio_pin_write_logic(&(seg->seven_segment_pin[SEGMENT_PIN0]), (number >> 0) & 0x01);
        status = gpio_pin_write_logic(&(seg->seven_segment_pin[SEGMENT_PIN1]), (number >> 1) & 0x01);
        status = gpio_pin_write_logic(&(seg->seven_segment_pin[SEGMENT_PIN2]), (number >> 2) & 0x01);
        status = gpio_pin_write_logic(&(seg->seven_segment_pin[SEGMENT_PIN3]), (number >> 3) & 0x01);
    }
    return status;
}

