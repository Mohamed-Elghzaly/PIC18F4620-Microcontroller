/* 
 * File:   ecu_ultrasonic.h
 * Author: Mohamed
 *
 * Created on September 29, 2023, 10:07 AM
 */

#ifndef ECU_ULTRASONIC_H
#define	ECU_ULTRASONIC_H

/*------------------- Includes -------------------*/
#include "../../MCAL_Layer/CCP1/hal_ccp1.h"
#include "../../MCAL_Layer/Timer1/hal_timer1.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*------------------- Macro Declarations -------------------*/

/*------------------- Macro Functions Declarations -------------------*/

/*------------------- Data Type Declarations -------------------*/
typedef struct{
    pin_config_t trigger_pin;
    pin_config_t eco_pin;
}ultrasonic_t;

/*------------------- Software Interfaces Declarations -------------------*/
Std_ReturnType Ultrasonic_Initializaion(const ultrasonic_t *ultrasonic);
Std_ReturnType Ultrasonic_Send_Pulse( ultrasonic_t *ultrasonic);
Std_ReturnType Ultrasonic_Read_Pulse(const ultrasonic_t *ultrasonic, uint32 *Distance);

#endif	/* ECU_ULTRASONIC_H */

