/* 
 * File:   eeprom_24C02C.c
 * Author: Mohamed
 *
 * Created on October 10, 2023, 5:02 PM
 */

#include "eeprom_24C02C.h"

void EEPROM_24C02C_Write_Byte(uint8 EEPROM_Address,uint8 Byte_Address,uint8 Data){
    MSSP_I2C_t MSSP_I2C;
    uint8 ACK;
    MSSP_I2C.i2c_clock = 100000;
    MSSP_I2C.i2c_cfg.i2c_Mode = I2C_MASTER_MODE;
    MSSP_I2C.i2c_cfg.i2c_Mode_cfg = I2C_MASTER_MODE_WITH_CLOCK;
    MSSP_I2C.i2c_cfg.slew_rate = I2C_SLEW_RATE_CONTROL_DISABLE;
    MSSP_I2C.i2c_cfg.SMBus = I2C_SMBUS_DISABLE;
    MSSP_I2C.I2C_DeaultIntrruptHandler = NULL;
    MSSP_I2C.I2C_Report_Write_Collosion = NULL;
    MSSP_I2C.I2C_Report_Receive_Overflow = NULL;
    I2C_Initialize(&MSSP_I2C);
    I2C_Master_Start(&MSSP_I2C);
    __delay_us(100);
    I2C_Master_Write_Blocking(&MSSP_I2C, EEPROM_Address, &ACK);
    __delay_us(100);
    I2C_Master_Write_Blocking(&MSSP_I2C, Byte_Address, &ACK);
    __delay_us(100);
    I2C_Master_Write_Blocking(&MSSP_I2C, Data, &ACK);
    __delay_us(100);
    I2C_Master_Stop(&MSSP_I2C);
}

uint8 EEPROM_24C02C_Read_Byte(uint8 EEPROM_Address,uint8 Byte_Address){
    
}