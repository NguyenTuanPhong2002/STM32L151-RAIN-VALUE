/*
 * sim.h
 *
 *  Created on: Jul 17, 2023
 *      Author: ACER
 */

#ifndef SIM_SIM_H_
#define SIM_SIM_H_

#include "main.h"
#include "stm32l1xx.h"
#include "../../PRETREATMENT/SIM7600/sim7600.h"
#include "string.h"

#define PWRKEY PWRKEY_GPIO_Port, PWRKEY_Pin
#define RESETSIM RST_SIM_GPIO_Port, RST_SIM_Pin
#define FLIGHTMODE FLIGHT_GPIO_Port, FLIGHT_Pin

typedef enum
{
    SIM_STATUS_OK,
    SIM_STATUS_ERROR,
    SIM_STATUS_BUSY,
} SIM;

typedef struct realtime
{
    char dateTime[10];
    char realTime[10];
} REALTIME;

SIM startSIM();
SIM sendDataFirebase(char *data);
char getDateTime(REALTIME *realtimedata);
char getRealTime(REALTIME *realtimedata);

#endif /* SIM_SIM_H_ */
