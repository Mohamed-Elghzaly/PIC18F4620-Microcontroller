/* 
 * File:   seven_segment.h
 * Author: Mohamed
 *
 * Created on September 11, 2023, 1:23 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section : Macro Declaration */
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 3

#define SEGMENT_COMMON_ANODE     0
#define SEGMENT_COMMON_CATHODE   1

/* Section : Data Type Declaration */
typedef struct{
    pin_config_t seven_segment_pin[4];
    uint8 segment_type;
}segment_t;

/* Section : Function Declaration */
Std_ReturnType seven_segment_inialize(const segment_t *seg);
Std_ReturnType seven_segment_write_number(const segment_t *seg, uint8 number);


#endif	/* SEVEN_SEGMENT_H */

