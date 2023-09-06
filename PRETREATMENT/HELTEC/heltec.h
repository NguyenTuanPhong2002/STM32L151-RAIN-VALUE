/*
 * heltec.h
 *
 *  Created on: Aug 23, 2023
 *      Author: ACER
 */

#ifndef HELTEC_HELTEC_H_
#define HELTEC_HELTEC_H_

#include "main.h"
#include "stm32l1xx_hal.h"

#define CS RST_GPIO_Port, RST_Pin // change pin rst vs cs
#define RST CS_GPIO_Port, CS_Pin  // change pin cs vs rst
#define DC DC_GPIO_Port, DC_Pin

#define xDot 128
#define yDot 296

void EPD_Dis_Part(unsigned char xStart, unsigned char xEnd, unsigned long yStart, unsigned long yEnd, uint8_t *DisBuffer, unsigned char Label);
void EPD_Dis_Full(unsigned char *DisBuffer, unsigned char Label);
void EPD_init_Full(void);
void EPD_init_Part(void);

void SPI_Write(unsigned char value);

unsigned char ReadBusy(void);
extern const unsigned char LUTDefault_part[31];
extern const unsigned char LUTDefault_full[31];
void EPD_W21_WriteCMD(uint8_t command);
void EPD_W21_WriteCMD_p1(uint8_t command, uint8_t para);
void EPD_W21_Write(unsigned char *value, unsigned char datalen);

void EPD_W21_WirteLUT(unsigned char *LUTvalue, unsigned char Size);
void EPD_W21_Update_Part(void);
void EPD_W21_Update(void);
void EPD_W21_Init(void);
void EPD_W21_DispInit(void);
void DisplayRefresh(void);
void Display_Part(void);

void EPD_W21_POWERON(void);
void EPD_W21_POWEROFF(void);
void EPD_W21_SLEEP(void);

void EPD_W21_WriteDispRam(unsigned char XSize, unsigned int YSize, unsigned char *Dispbuff);
void EPD_W21_WriteDispRamMono(unsigned char XSize, unsigned int YSize, uint8_t dispdata);
void EPD_W21_SetRamArea(unsigned char Xstart, unsigned char Xend, unsigned char Ystart, unsigned char Ystart1, unsigned char Yend, unsigned char Yend1);
void EPD_W21_SetRamPointer(unsigned char addrX, unsigned char addrY, unsigned char addrY1);
void part_display(unsigned char RAM_XST, unsigned char RAM_XEND, unsigned char RAM_YST, unsigned char RAM_YST1, unsigned char RAM_YEND, unsigned char RAM_YEND1);

#endif /* HELTEC_HELTEC_H_ */
