#ifndef  BUTTION_H_
#define BUTTION_H_

#include "main.h"

#define BUTTION1 GPIO_PIN_0
#define BUTTION2 GPIO_PIN_1
#define BUTTION3 GPIO_PIN_2
#define BUTTION4 GPIO_PIN_3
#define BUTTION5 GPIO_PIN_4
#define BUTTION6 GPIO_PIN_5
#define BUTTION7 GPIO_PIN_6
#define BUTTION8 GPIO_PIN_7

typedef enum {
    BUTTION_ON,
    BUTTTION_OFF
}Status_Buttion;


#endif