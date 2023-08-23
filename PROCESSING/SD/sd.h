
#ifndef SD_H_
#define SD_H_

#include "main.h"
#include "fatfs.h"
#include "../../PRETREATMENT/SD_CARD/sd_card.h"

typedef enum
{
    SD_CARD_OK,
    SD_CARD_ERROR,
    SD_CARD_BUSY
}SD_CARD_STATUS;

SD_CARD_STATUS SD_Init();
SD_CARD_STATUS SD_CreatFile(char* newForder, char* newFile, char* data);

#endif