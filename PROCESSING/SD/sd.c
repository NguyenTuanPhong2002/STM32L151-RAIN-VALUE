
#include "sd.h"
#include <stdio.h>

SD_CARD_STATUS SD_Init()
{
    SD_CARD_STATUS status = SD_CARD_BUSY;
    if (sd_mount() == SD_OK)
    {
        return SD_CARD_OK;
    }
    else
    {
        return SD_CARD_ERROR;
    }
    return status;
};

SD_CARD_STATUS SD_CreatFile(char *newForder, char *newFile, char *data)
{
    char forderPath[50];
    char filePath[50];
    memset(forderPath, 0, 50);
    sprintf(forderPath, "%s", newForder);
    memset(filePath, 0, 50);
    sprintf(filePath, "%s\\%s.txt", newForder, newFile);

    if (sd_mount() == SD_OK)
    {
        f_mkdir(forderPath);
        sd_check_space();
        if (SD_creat_file(filePath) != SD_OK)
        {
            return SD_CARD_ERROR;
        }
        SD_sendData(filePath, data);
        return SD_CARD_OK;
    }
    return SD_CARD_ERROR;
};
