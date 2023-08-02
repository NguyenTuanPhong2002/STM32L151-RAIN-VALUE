/*
 * sd.c
 *
 *  Created on: Jul 10, 2023
 *      Author: ACER
 */

#include "sd_card.h"

FATFS fs; // file system
FIL fil;  // File
FILINFO fno;
FRESULT fresult; // result
UINT br, bw;     // File read/write count

FATFS *pfs;
DWORD fre_clust;
uint32_t total, free_space;

#define BUFFER_SIZE 128
char buffer[BUFFER_SIZE]; // to store strings..
int i = 0;

int bufsize(char *buf)
{
    int i = 0;
    while (*buf++ != '\0')
        i++;
    return i;
}

void clear_buffer(void)
{
    for (int i = 0; i < BUFFER_SIZE; i++)
        buffer[i] = '\0';
}

SD_CARD sd_mount()
{
    SD_CARD status = SD_ERROR;
    fresult = f_mount(&fs, "", 1);
    if (fresult != FR_OK)
        status = SD_ERROR;
    else
        status = SD_OK;
    return status;
}

char sd_check_space()
{
    clear_buffer();
    f_getfree("", &fre_clust, &pfs);
    total = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5);
    sprintf(buffer, "SD CARD Total Size: \t%lu\n", total);
    //send_uart(buffer);
    clear_buffer();
    free_space = (uint32_t)(fre_clust * pfs->csize * 0.5);
    sprintf(buffer, "SD CARD Free Space: \t%lu\n\n", free_space);
    //send_uart(buffer);
    return buffer;
}

SD_CARD SD_creat_file(char *fileName)
{
    SD_CARD status = SD_ERROR;
    fresult = f_open(&fil, fileName, FA_OPEN_ALWAYS | FA_WRITE);

    fresult = f_close(&fil);
    if (fresult == FR_OK)
        status = SD_OK;
    return status;
};

char SD_readData(char *fileName)
{
    clear_buffer();
    fresult = f_open(&fil, fileName, FA_READ);
    f_gets(buffer, f_size(&fil), &fil);
    f_close(&fil);
    return buffer;
};

SD_CARD SD_removeFile(char *fileName)
{
    SD_CARD status = SD_ERROR;
    fresult = f_unlink(fileName);
    if (fresult == FR_OK)
        status = SD_OK;
    return status;
};

SD_CARD SD_putData(char *fileName, char *data)
{
    SD_CARD status = SD_ERROR;
    fresult = f_open(&fil, fileName, FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
    f_puts(data, &fil);
    fresult = f_close(&fil);
    if (fresult == FR_OK)
    {
        status = SD_OK;
    }

    return status;
};

SD_CARD SD_sendData(char *fileName, char *data){
    clear_buffer();
    SD_CARD status = SD_ERROR;
    fresult = f_open(&fil, fileName, FA_CREATE_ALWAYS | FA_WRITE);
    f_printf(&fil, data);
    f_close(&fil);
    return status;
};
