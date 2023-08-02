/**
 * The function "dataGetTime" gets the current time and counts the number of seconds elapsed until a
 * certain condition is met.
 *
 * @param data a pointer to a struct of type DATA, which contains various data related to time and
 * counting.
 */
/*
 * data.c
 *
 *  Created on: Jun 24, 2023
 *      Author: ACER
 */

#include "data.h"
#include "../../PROCESSING/MONITER/moniter.h"

extern DATA data;

uint64_t gettick_count;
uint64_t timCutCount;
extern RTC_TimeTypeDef setCurrTime;
RTC_TimeTypeDef HTime = {0};
RTC_DateTypeDef HDate = {0};
/**
 * The function initializes the values of a struct called DATA to zero.
 *
 * @param data a pointer to a struct of type DATA.
 */
void initCounter(){
	data.Distance_high = 10.00;
	data.Distance = 0.2;
}
void dataInit()
{
	data.count = 0;
	data.hour = 0;
	data.minute = 0;
	data.second = 0;
};

/**
 * The function evenMode returns the input status.
 *
 * @param data A pointer to a struct of type DATA.
 * @param status The TIM_STATUS variable that is being passed as a parameter to the function.
 *
 * @return the TIM_STATUS variable named "status".
 */
TIM_STATUS evenMode(DATA *data, TIM_STATUS status)
{
	return status;
};

/**
 * The function countTime returns the TIM_STATUS status.
 *
 * @param data A pointer to a struct or object of type DATA.
 * @param status The status of a timer, which is of type TIM_STATUS.
 *
 * @return the TIM_STATUS variable named "status".
 */
TIM_STATUS countTime(DATA *data, TIM_STATUS status)
{
	return status;
};

/**
 * The function `dataGetTime` retrieves the current time from a real-time clock and updates the time
 * count and other variables in a `DATA` struct.
 *
 * @param data A pointer to a structure of type DATA, which contains various data fields and variables.
 *
 * @return a variable of type DATA_STATUS.
 */
DATA_STATUS dataGetTime(DATA *data)
{
	DATA_STATUS status = DATA_WAITE;
	while (data->countTime == RUN_TIME)
	{
		if (data->count == 0)
		{
			HAL_RTC_Init(&hrtc);
			HTime.Hours = 0;
			HTime.Minutes = 0;
			HTime.Seconds = 0;
			HAL_RTC_SetTime(&hrtc, &HTime, RTC_FORMAT_BIN);
			status = DATA_RUN;
		}

		HAL_RTC_GetTime(&hrtc, &HTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &HDate, RTC_FORMAT_BIN);
		if (data->evenMode == RUN_COUNT)
		{
			gettick_count = HAL_GetTick();
			if (gettick_count - timCutCount > 50)
			{
				data->count++;
				data->hour = HTime.Hours;
				data->minute = HTime.Minutes;
				data->second = HTime.Seconds;
				timCutCount = HAL_GetTick();
				count_moniter(data);
			}
		}
		data->evenMode = STOP_COUNT;
		data->time_count_second = data->hour * 3600 + data->minute * 60 + data->second;
		data->real_time = HTime.Hours * 3600 + HTime.Minutes * 60 + HTime.Seconds;
		if ((data->real_time - data->time_count_second > 40))
		{
			data->countTime = STOP_TIME;
			status = DATA_STOP;
			return status;
		}
	}
	return status;
}

/**
 * The function "handleData" calculates the flow water and percentage based on the given data.
 *
 * @param data A pointer to a structure of type DATA.
 */
void handleData()
{
	data.Flow_warter = data.Distance_high / ((data.hour * 60.0) + (data.minute * 1.0) + (data.second / 60.0))	;
	data.percent = ((data.Distance * data.count) / data.Distance_high) * 100;
	// if (data->percent > 100)
	// {
	// 	data->percent = 100 - data->percent;
	// 	data->percent = 0 - data->percent;
	// }
}