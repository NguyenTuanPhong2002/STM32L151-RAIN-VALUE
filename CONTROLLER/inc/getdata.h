
#ifndef GETDATA_H_
#define GETDATA_H_

#include "main.h"
#include "stm32l1xx.h"

#include "../../../PROCESSING/DATA/data.h"

typedef enum{
    WAITE_MODE,
    RUN_MODE,
    FINISH,
}MODE;


typedef struct deviceConfigure
{
	char id[15];
    char url[200];
}DEVICE;

void deviceInit();
MODE dataCounter();
void resetData();
void textData();

#endif