/* 
 * File:   eeprom_24C02C.h
 * Author: Mohamed
 *
 * Created on October 10, 2023, 5:02 PM
 */

#ifndef EEPROM_24C02C_H
#define	EEPROM_24C02C_H

#include "../../MCAL_Layer/I2C/hal_i2c.h"

void EEPROM_24C02C_Write_Byte(uint8 EEPROM_Address,uint8 Byte_Address,uint8 Data);
uint8 EEPROM_24C02C_Read_Byte(uint8 EEPROM_Address,uint8 Byte_Address);

#endif	/* EEPROM_24C02C_H */

