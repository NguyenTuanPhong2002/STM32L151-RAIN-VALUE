/*
 * display.c
 *
 *  Created on: Jun 27, 2023
 *      Author: ACER
 */
#include "display.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
/**
 * The function displays a delay for a specified amount of time and returns a status indicating if the
 * delay was successful.
 *
 * @param time The amount of time in milliseconds that the function should delay before returning a
 * status of OK.
 *
 * @return a value of type TIME, which is an enum type. The possible values that can be returned are
 * BUSY and OK.
 */
TIME displayDelay(uint8_t time)
{
    TIME status = BUSY;
    // uint8_t time_begin;
    // time_begin = HAL_GetTick();
    // while (TRUE)
    // {
    //     if (time_begin - HAL_GetTick() > time)
    //     {
    //         TIME status = OK;
    //         exit;
    //     }
    // }
    HAL_Delay(time);
    return status;
};
