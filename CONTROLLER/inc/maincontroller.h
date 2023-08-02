#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

#include "main.h"
#include "getdata.h"
#include "../../PRETREATMENT/BUTTION/buttion.h"
#include "../../PROCESSING/SIM/sim.h"
#include "../../PROCESSING/DATA/data.h"
#include "../../PROCESSING/SD/sd.h"
#include "../../PROCESSING/MONITER/moniter.h"

typedef enum
{
    RUN,
    STOP,
} MODE_STATUS;

void strat();
void maincontroller();

#endif
