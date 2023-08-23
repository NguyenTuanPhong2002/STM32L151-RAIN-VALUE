/*
 * SD.h
 *
 *  Created on: Jul 10, 2023
 *      Author: ACER
 */

#ifndef SD_CARD_H_
#define SD_CARD_H_

#include "main.h"
#include "fatfs.h"

#include "fatfs_sd.h"
#include "string.h"
#include "stdio.h"

typedef enum
{
    SD_OK,
    SD_ERROR,
} SD_CARD;

int bufsize(char *buf);
void clear_buffer(void);
SD_CARD sd_mount();
char sd_check_space();
SD_CARD SD_creat_file(char *fileName);
char SD_readData(char *fileName);
SD_CARD SD_removeFile(char *fileName);
SD_CARD SD_putData(char *fileName, char *data);
SD_CARD SD_sendData(char *fileName, char *data);

#endif

