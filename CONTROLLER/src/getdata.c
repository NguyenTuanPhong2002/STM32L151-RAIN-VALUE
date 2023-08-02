#include "../inc/getdata.h"
#include "../../PROCESSING/DATA/data.h"
#include <stdio.h>

//extern DATA data;
extern DEVICE device;

void deviceInit(){
	sprintf((char *)device.id,"%s","+84123456789");
	sprintf((char *)device.url,"%s","https://rain-4a16a-default-rtdb.firebaseio.com/test2.json");
};

MODE dataCounter()
{
	extern DATA data;
	DATA_STATUS status = dataGetTime(&data);
	if (status == DATA_STOP)
	{
		return FINISH;
	};
	if (status == DATA_WAITE)
	{
		return WAITE_MODE;
	};
	if (status == DATA_RUN)
	{
		return RUN_MODE;
	};
	return WAITE_MODE;
};