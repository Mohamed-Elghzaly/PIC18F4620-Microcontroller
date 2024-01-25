/* 
 * File:   ecu_dc_motor.h
 * Author: Mohamed
 *
 * Created on September 6, 2023, 5:31 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
 
/* Section : Macro Declaration */
#define DC_MOTOR_OFF   0
#define DC_MOTOR_ON    1

/* Section : Macro Functions Declaration */

/* Section : Data Type Declaration */
typedef struct{
    pin_config_t dc_motor[2];
}dc_motor_pin_t;

/* Section : Function Declaration */
Std_ReturnType dc_motor_intialize(const dc_motor_pin_t *_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_pin_t *_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_pin_t *_motor);
Std_ReturnType dc_motor_stop(const dc_motor_pin_t *_motor);


#endif	/* ECU_DC_MOTOR_H */

