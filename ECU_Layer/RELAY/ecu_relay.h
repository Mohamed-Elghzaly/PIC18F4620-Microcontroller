/* 
 * File:   ecu_relay.h
 * Author: Mohamed
 *
 * Created on September 6, 2023, 12:59 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

 
/* Section : Macro Declaration */
#define RELAY_OFF   0
#define RELAY_ON    1

/* Section : Macro Functions Declaration */

/* Section : Data Type Declaration */
typedef struct{
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 relay_status : 1;
}relay_t;

/* Section : Function Declaration */
Std_ReturnType relay_intialize(const relay_t *_relay);
Std_ReturnType relay_on(const relay_t *_relay);
Std_ReturnType relay_off(const relay_t *_relay);

#endif	/* ECU_RELAY_H */

