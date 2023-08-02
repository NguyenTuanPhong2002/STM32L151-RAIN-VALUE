/*
 * sim7600.h
 *
 *  Created on: May 29, 2023
 *      Author: ACER
 */

#ifndef SIM7600_H_
#define SIM7600_H_

#include "string.h"
#include "main.h"
#include "stm32l1xx_hal.h"

#define SIM_BUFFER_SIZE 500
#define SIM_TX_BUFFER_SIZE 300
/* Change your extern variable */
extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;

typedef enum
{
    SIM_OK,
    SIM_ERROR,
    SIM_TIMEOUT,
    SIM_BUSY,
} SIM_StatusTypeDef;

typedef enum{
    SIMTRUE,
    SIMFALSE,
}BOOL;

typedef struct sim7600
{
    BOOL rxFlag;
    UART_HandleTypeDef *UART;
    DMA_HandleTypeDef *HDMA;
    char rxBuffer[SIM_BUFFER_SIZE];
    char txBuffer[SIM_TX_BUFFER_SIZE];
} SIM7600;

void SIM7600_init(SIM7600 *sim);

SIM_StatusTypeDef SIM7600_Start(SIM7600 *sim);
SIM_StatusTypeDef SIM7600_httpStart(SIM7600 *sim);
SIM_StatusTypeDef SIM7600_httpStop(SIM7600 *sim);
SIM_StatusTypeDef SIM7600_httpRead(SIM7600 *sim, const char *url);
SIM_StatusTypeDef SIM7600_httpPost(SIM7600 *sim, const char *data);
SIM_StatusTypeDef SIM7600_setUrl(SIM7600 *sim,const char *url);
SIM_StatusTypeDef SIM7600_setTime(SIM7600 *sim);
SIM_StatusTypeDef SIM7600_getTime(SIM7600 *sim);
#endif /* SIM7600_H_ */
