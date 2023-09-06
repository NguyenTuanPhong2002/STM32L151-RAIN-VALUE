/*
 * DEV_Config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ACER
 */

#ifndef EPAPER_DEV_CONFIG_H_
#define EPAPER_DEV_CONFIG_H_

#include "main.h"
#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_gpio.h"
#include <stdint.h>
#include <stdio.h>

#define WHITE          0xFF
#define BLACK          0x00
#define RED            BLACK

#define UBYTE uint8_t
#define UWORD uint16_t
#define UDOUBLE uint32_t

#define CS RST_GPIO_Port, RST_Pin // change pin rst vs cs
#define RST CS_GPIO_Port, CS_Pin  // change pin cs vs rst
#define DC DC_GPIO_Port, DC_Pin
#define BUSY BUSY_GPIO_Port, BUSY_Pin

#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin)

#define DEV_Delay_ms(__xms) HAL_Delay(__xms);

void DEV_SPI_WriteByte(UBYTE value);

int DEV_Module_Init(void);
void DEV_Module_Exit(void);

#endif /* EPAPER_DEV_CONFIG_H_ */
