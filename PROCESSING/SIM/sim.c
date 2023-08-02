#include "sim.h"
#include "../../CONTROLLER/inc/getdata.h"

extern SIM7600 sim;
extern REALTIME realtimedata;
extern DEVICE device;

SIM startSIM()
{
    HAL_GPIO_WritePin(FLIGHTMODE, SET);
    // HAL_GPIO_WritePin(RESETSIM, SET);
    // HAL_Delay(1500);
    // HAL_GPIO_WritePin(RESETSIM, RESET);
    // HAL_Delay(1500);
    HAL_GPIO_WritePin(PWRKEY, SET);
    // HAL_Delay(15000);
};

SIM simInit(){
    SIM status = SIM_STATUS_BUSY;
    SIM7600_init(&sim);  
    if (SIM7600_Start(&sim) == SIM_OK)

        status = SIM_STATUS_OK;
    SIM7600_httpStart(&sim);

    SIM7600_setUrl(&sim, device.url);

    return status;
}

char getDateTime(REALTIME *realtimedata)
{
    memset((char *)realtimedata->dateTime, 0, 500);
    SIM7600_getTime(&sim);
    char year[10];
    char month[10];
    char day[10];
    memset(year, 0, 10);
    memset(month, 0, 10);
    memset(day, 0, 10);
    memcpy(year, (char *)&sim.rxBuffer[19], 2);
    memcpy(month, (char *)&sim.rxBuffer[22], 2);
    memcpy(day, (char *)&sim.rxBuffer[25], 2);
    sprintf((char *)realtimedata->dateTime, "%s %s %s", year, month, day);
    return (char *)realtimedata->dateTime;
};

/**
 * The function "getRealTime" retrieves the real-time from a SIM7600 module and returns it as a
 * character array.
 *
 * @return a character array (string) containing the real-time value.
 */
char getRealTime(REALTIME *realtimedata)
{
    memset((char *)realtimedata->realTime, 0, 500);
    SIM7600_getTime(&sim);
    char hour[10];
    char minute[10];
    char second[10];
    memset(hour, 0, 10);
    memset(minute, 0, 10);
    memset(second, 0, 10);
    memcpy(hour, (char *)&sim.rxBuffer[28], 2);
    memcpy(minute, (char *)&sim.rxBuffer[31], 2);
    memcpy(second, (char *)&sim.rxBuffer[34], 2);
    sprintf((char *)realtimedata->realTime, "%s %s %s", hour, minute, second);
    return (char *)realtimedata->realTime;
};

/**
 * The function sends data to Firebase using the SIM7600 module and returns the status of the
 * operation.
 *
 * @param data The parameter "data" is of type char and represents the data that you want to send to
 * Firebase.
 *
 * @return a SIM status, which can be either SIM_STATUS_OK or SIM_STATUS_ERROR.
 */
SIM sendDataFirebase(char *data)
{
    if (SIM7600_httpPost(&sim, data) == SIM_OK)
        return SIM_STATUS_OK;
    return SIM_STATUS_ERROR;
}