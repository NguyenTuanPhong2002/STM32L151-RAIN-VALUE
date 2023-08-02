#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "main.h"

#include "stm32l1xx.h"

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 296

#define EPD_RST_PIN    RST_GPIO_Port,RST_Pin
#define EPD_DC_PIN     DC_GPIO_Port,DC_Pin
#define EPD_CS_PIN     CS_GPIO_Port,CS_Pin
#define EPD_BUSY_PIN   BUSY_GPIO_Port,BUSY_Pin

typedef enum{
    BUSY,
    OK,
}TIME;

TIME displayDelay(uint8_t time);

#endif