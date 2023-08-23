/*
 * configure.h
 *
 *  Created on: Jun 27, 2023
 *      Author: ACER
 */

#ifndef CONFIGURE_H_
#define CONFIGURE_H_

#include "display.h"
#include "main.h"

#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_gpio.h"
#include <stdint.h>
#include <stdio.h>

#define UBYTE uint8_t
#define UWORD uint16_t
#define UDOUBLE uint32_t

#define EPD_2IN9_FULL			0
#define EPD_2IN9_PART			1

#define black 0x10
#define red 0x13

#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin)

int module_Init(void);
void DEV_SPI_WriteByte(UBYTE value);
int DEV_Module_Init(void);
void DEV_Module_Exit(void);
void DISPLAY_SendData(UBYTE Data);
void DISPLAY_SendCommand(UBYTE Reg);
void DISPLAY_ReadBusy(void);
void DISPLAY_TurnOnDisplay(void);
void DISPLAY_Clear(void);
void DISPLAY_Display(const UBYTE *blackimage, const UBYTE *ryimage);
void DISPLAY_Sleep(void);
void DISPLAY_Reset(void);
void display_print();
void DISPLAY_Init(void);
#endif /* CONFIGURE_H_ */
