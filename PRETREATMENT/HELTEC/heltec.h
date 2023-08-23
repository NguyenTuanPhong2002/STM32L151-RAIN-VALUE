/*
 * heltec.h
 *
 *  Created on: Aug 23, 2023
 *      Author: ACER
 */

#ifndef HELTEC_HELTEC_H_
#define HELTEC_HELTEC_H_

#include "main.h"
#include "stm32l1xx_hal.h"

#define CS RST_GPIO_Port,RST_Pin // change pin rst vs cs
#define RST CS_GPIO_Port,CS_Pin //change pin cs vs rst
#define DC DC_GPIO_Port,DC_Pin

#define xDot 128
#define yDot 296


#endif /* HELTEC_HELTEC_H_ */
