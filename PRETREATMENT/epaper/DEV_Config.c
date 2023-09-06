#include "main.h"
#include "DEV_Config.h"
#include "stm32l1xx_hal_spi.h"

extern SPI_HandleTypeDef hspi1;
void DEV_SPI_WriteByte(UBYTE value)
{
    HAL_SPI_Transmit(&hspi1, &value, 1, 1000);
}

int DEV_Module_Init(void)
{
    DEV_Digital_Write(DC, 0);
    DEV_Digital_Write(CS, 0);
    // DEV_Digital_Write(EPD_PWR_PIN, 1);
    DEV_Digital_Write(RST, 1);
    return 0;
}

void DEV_Module_Exit(void)
{
    DEV_Digital_Write(DC, 0);
    DEV_Digital_Write(CS, 0);

    // close 5V
    // DEV_Digital_Write(EPD_PWR_PIN, 0);
    DEV_Digital_Write(RST, 0);
}
