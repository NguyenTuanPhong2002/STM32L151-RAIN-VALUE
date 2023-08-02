
#include "moniter.h"
#include <stdio.h>

UBYTE *BlackImage, *RYImage; // Red or Yellow

void setup_moniter()
{
    DEV_Module_Init();
    DISPLAY_Init();

    UWORD Imagesize = ((DISPLAY_WIDTH % 8 == 0) ? (DISPLAY_WIDTH / 8) : (DISPLAY_WIDTH / 8 + 1)) * DISPLAY_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL)
    {
        return -1;
    }
    if ((RYImage = (UBYTE *)malloc(Imagesize)) == NULL)
    {
        return -1;
    }

    Paint_NewImage(BlackImage, DISPLAY_WIDTH, DISPLAY_HEIGHT, 270, WHITE);
    Paint_NewImage(RYImage, DISPLAY_WIDTH, DISPLAY_HEIGHT, 270, WHITE);
}

void moniter_begin()
{
    // Select Image
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_DrawString_EN(40, 25, "VRAIN DEVICE", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(40, 55, "VERSION 1.0.0", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(60, 100, "DESIGN BY THTECH", &Font16, WHITE, BLACK);
    Paint_SelectImage(RYImage);
    Paint_Clear(WHITE);
    Paint_DrawString_EN(40, 23, "VRAIN DEVICE", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(40, 57, "VERSION 1.0.0", &Font24, WHITE, BLACK);
    Paint_DrawString_EN(60, 102, "DESIGN BY THTECH", &Font16, WHITE, BLACK);

    DISPLAY_Display(BlackImage, RYImage);
}

void home_moniter(SIM simStatus, SD_CARD_STATUS sdStatus, DATA *data)
{
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    if (simStatus == SIM_STATUS_OK)
    {
        Paint_DrawString_EN(160, 0, "SIM CONNECT", &Font16, WHITE, BLACK);
    }
    else
    {
        Paint_DrawString_EN(120, 0, "SIM NOT CONNECT", &Font16, WHITE, BLACK);
    }

    if (sdStatus == SD_CARD_OK)
    {
        Paint_DrawString_EN(170, 20, "SD CONNECT", &Font16, WHITE, BLACK);
    }
    else
    {
        Paint_DrawString_EN(130, 20, "SD NOT CONNECT", &Font16, WHITE, BLACK);
    }
    Paint_DrawString_EN(60, 40, "READLY TO COUNT", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(20, 60, "COUNT:", &Font16, WHITE, BLACK);
    Paint_DrawNum(85, 60, data->count, &Font16, BLACK, WHITE);

    Paint_DrawString_EN(20, 80, "time:", &Font16, WHITE, BLACK);
    Paint_DrawNum(75, 80, data->hour, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(95, 80, "/", &Font16, WHITE, BLACK);
    Paint_DrawNum(105, 80, data->minute, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(125, 80, "/", &Font16, WHITE, BLACK);
    Paint_DrawNum(135, 80, data->second, &Font16, BLACK, WHITE);

    Paint_DrawString_EN(20, 100, "FLOW WARTER: --/-- mm", &Font16, WHITE, BLACK);

    Paint_DrawString_EN(200, 120, "DESIGN BY THTECH", &Font8, WHITE, BLACK);

    // 2.Draw red image
    Paint_SelectImage(RYImage);
    Paint_Clear(WHITE);

    DISPLAY_Display(BlackImage, RYImage);
};

void count_moniter(DATA *data)
{
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    Paint_DrawString_EN(60, 40, "COUNTING START ...", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(20, 60, "COUNT:", &Font16, WHITE, BLACK);
    Paint_DrawNum(85, 60, data->count, &Font16, BLACK, WHITE);

    Paint_DrawString_EN(20, 80, "time:", &Font16, WHITE, BLACK);
    Paint_DrawNum(75, 80, data->hour, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(95, 80, "/", &Font16, WHITE, BLACK);
    Paint_DrawNum(105, 80, data->minute, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(125, 80, "/", &Font16, WHITE, BLACK);
    Paint_DrawNum(135, 80, data->second, &Font16, BLACK, WHITE);

    Paint_DrawString_EN(20, 100, "FLOW WARTER: --/-- mm", &Font16, WHITE, BLACK);

    Paint_DrawString_EN(200, 120, "DESIGN BY THTECH", &Font8, WHITE, BLACK);

    // 2.Draw red image
    Paint_SelectImage(RYImage);
    Paint_Clear(WHITE);

    DISPLAY_Display(BlackImage, RYImage);
};

void finish_moniter(DATA *data, SIM checkSimStatus, SD_CARD_STATUS checkSdStatus)
{
    char flWarter[50];
    memset(flWarter, 0, 50);
    sprintf(flWarter, "%.2f", data->Flow_warter);
    char perCent[50];
    memset(perCent, 0, 50);
    sprintf(perCent, "%.2f", data->percent);

    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    if (checkSimStatus == SIM_STATUS_OK)
    {
        Paint_DrawString_EN(20, 0, "SIM SEND OKE", &Font16, WHITE, BLACK);
    }
    else
    {
        Paint_DrawString_EN(20, 0, "SIM SEND ERROR", &Font16, WHITE, BLACK);
    }

    if (checkSdStatus == SD_CARD_OK)
    {
        Paint_DrawString_EN(20, 20, "SD SEND 0K", &Font16, WHITE, BLACK);
    }
    else
    {
        Paint_DrawString_EN(20, 20, "SD SEND ERROR", &Font16, WHITE, BLACK);
    }

    Paint_DrawString_EN(60, 40, "FINISH COUNT", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(20, 60, "COUNT:", &Font16, WHITE, BLACK);
    Paint_DrawNum(85, 60, data->count, &Font16, BLACK, WHITE);

    Paint_DrawString_EN(120, 60, "time:", &Font16, WHITE, BLACK);
    Paint_DrawNum(170, 60, data->hour, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(200, 60, "/", &Font16, WHITE, BLACK);
    Paint_DrawNum(215, 60, data->minute, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(245, 60, "/", &Font16, WHITE, BLACK);
    Paint_DrawNum(260, 60, data->second, &Font16, BLACK, WHITE);

    Paint_DrawString_EN(20, 80, "FLOW WARTER:", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(150, 80, flWarter, &Font16, WHITE, BLACK);
    Paint_DrawString_EN(220, 80, "mm", &Font16, WHITE, BLACK);

    Paint_DrawString_EN(20, 100, "PERCENT WARTER:", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(190, 100, perCent, &Font16, WHITE, BLACK);
    Paint_DrawString_EN(250, 100, "%", &Font16, WHITE, BLACK);

    Paint_DrawString_EN(220, 120, "DESIGN BY THTECH", &Font8, WHITE, BLACK);

    // 2.Draw red image
    Paint_SelectImage(RYImage);
    Paint_Clear(WHITE);

    DISPLAY_Display(BlackImage, RYImage);
};


void deviceInformatio(DEVICE *device)
{
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    Paint_DrawString_EN(20, 20, "DEVICE ID: ", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(140, 20, (char *)&device->id, &Font16, WHITE, BLACK);

    Paint_DrawString_EN(20, 40, "URL DATA: ", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(120, 40, (char *)&device->url, &Font16, WHITE, BLACK);

    // 2.Draw red image
    Paint_SelectImage(RYImage);
    Paint_Clear(WHITE);

    DISPLAY_Display(BlackImage, RYImage);
};


void dataConfigure(DATA *data)
{
    char distanceHight[50];
    memset(distanceHight, 0, 50);
    sprintf(distanceHight, "%.2f", data->Distance_high);
    char distance[50];
    memset(distance, 0, 50);
    sprintf(distance, "%.2f", data->Distance);


    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    Paint_DrawString_EN(20, 20, "DISTANCE HIGH: ", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(185, 20, distanceHight, &Font16, WHITE, BLACK);

    Paint_DrawString_EN(20, 40, "DISTANCE: ", &Font16, WHITE, BLACK);
    Paint_DrawString_EN(120, 40, distance, &Font16, WHITE, BLACK);


    // 2.Draw red image
    Paint_SelectImage(RYImage);
    Paint_Clear(WHITE);

    DISPLAY_Display(BlackImage, RYImage);
};