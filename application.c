/* 
 * File:   application.c
 * Author: Mohamed Elghzaly
 *
 * Created on September 3, 2023, 12:00 AM
 */
#include"application.h"
#include "MCAL_Layer/SPI/hal_spi.h"

MSSP_SPI_t spi_obj = {
    .spi_mode = SPI_MASTER_MODE_CLK_OSC_DIV_4,
    .spi_clock_polarity = SPI_CLK_LOW_AT_IDLE_STATE,
    .spi_transmit_clk_select = SPI_TRANSMIT_FROM_IDLE_TO_ACTIVE
};

void application_initialize(void);


int main() {
    SPI_Initialize(&spi_obj);
    while(1){
    SPI_Master_Send_Byte_polling('a');
    SPI_Master_Send_Byte_polling('b');
    SPI_Master_Send_Byte_polling('c');
        
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
    //ecu_layer_intialize();
}

