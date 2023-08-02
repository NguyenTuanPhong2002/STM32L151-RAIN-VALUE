/*
 * data.h
 *
 *  Created on: Jun 24, 2023
 *      Author: ACER
 */

#ifndef DATA_H_
#define DATA_H_

#include "main.h"
#include "stm32l1xx_hal.h"

extern RTC_HandleTypeDef hrtc;
extern TIM_HandleTypeDef htim4;

typedef enum
{
    RUN_RTC,
    STOP_RTC,
} RTC_STATUS;

typedef enum
{
    RUN_COUNT,
    STOP_COUNT,
    RUN_TIME,
    STOP_TIME,
} TIM_STATUS;

typedef struct data
{
    uint32_t count;
    uint32_t hour;
    uint32_t minute;
    uint32_t second;

    uint64_t tim_cut;
    uint8_t even_get_mode;
    uint8_t count_time;
    uint8_t time_count_second;
    uint8_t real_time;
    
    float Distance_high;
    float Distance;

    float Flow_warter;
    float percent;

    TIM_STATUS evenMode;
    TIM_STATUS countTime;
} DATA;

typedef enum
{
    DATA_RUN,
    DATA_STOP,
    DATA_WAITE,
} DATA_STATUS;

void initCounter();
void dataInit();
TIM_STATUS evenMode(DATA *data, TIM_STATUS status);
TIM_STATUS countTime(DATA *data, TIM_STATUS status);
DATA_STATUS dataGetTime(DATA *data);
void handleData();

#endif /* DATA_H_ */
