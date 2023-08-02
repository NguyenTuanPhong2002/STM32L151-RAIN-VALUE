/*
 * moniter.h
 *
 *  Created on: Jul 8, 2023
 *      Author: ACER
 */

#ifndef MONITER_H_
#define MONITER_H_

#include "main.h"
#include "../../PRETREATMENT/DISPLAY/configure.h"
#include "../../PRETREATMENT/DISPLAY/display.h"
#include "../../PRETREATMENT/DISPLAY/Fonts/fonts.h"
#include "../../PRETREATMENT/DISPLAY/GUI_Paint.h"
#include "../../PROCESSING/SIM/sim.h"
#include "../../PROCESSING/SD/sd.h"
#include "../../PROCESSING/DATA/data.h"
#include "../../CONTROLLER/inc/getdata.h"

void setup_moniter();
void moniter_begin();
void home_moniter(SIM simStatus, SD_CARD_STATUS sdStatus, DATA *data);
void count_moniter(DATA *data);
void finish_moniter(DATA *data, SIM checkSimStatus, SD_CARD_STATUS checkSdStatus);

#endif /* MONITER_H_ */
