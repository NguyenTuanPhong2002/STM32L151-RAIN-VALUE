/*
 * epaper.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ACER
 */

#ifndef EPAPER_EPAPER_H_
#define EPAPER_EPAPER_H_

#include "main.h"
#include "DEV_Config.h"
#include "stm32l1xx_hal.h"

#define EPAPER_HEIGHT 128
#define EPAPER_WIDTH 296

void EPAPER_Init(void);
void EPAPER_Init_Part(void);
void EPAPER_Clear(void);
void EPAPER_Base(UBYTE *Image);

void EPD_2IN9_V2_Display(UBYTE *Image);
void test(void);
void EPD_2IN9_V2_Display_Base(UBYTE *Image);

void EPAPER_UpdatePart(void);
void EPAPER_UpdateFass(void);
void EPAPER_DisplayPicture(UWORD Xstart, UWORD Ystart, unsigned char *Buffer);
void EPAPER_DisplayString(UWORD Xstart, UWORD Ystart, unsigned char *Buffer);

#endif /* EPAPER_EPAPER_H_ */
