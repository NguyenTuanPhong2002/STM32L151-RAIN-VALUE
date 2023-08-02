#include "../inc/maincontroller.h"
#include <stdio.h>

extern uint32_t ButtionOn;
extern REALTIME realtimedata;
extern DATA data;
extern DEVICE device;

MODE_STATUS checkMode = STOP;
SIM simStatus;
SD_CARD_STATUS sdStatus;

uint8_t flagButtion = 0;

void start()
{
    setup_moniter();
    //moniter_begin();
    deviceInit();
    dataInit();
    startSIM();
    checkMode = RUN;
    simStatus = simInit();
    sdStatus = SD_Init();
    initCounter(&data);
    home_moniter(simStatus, sdStatus, &data);
};

void maincontroller()
{
    MODE status = WAITE_MODE;
    if (checkMode == RUN)
    {
        status = dataCounter();
    }
    if (status == WAITE_MODE)
    {
    }

    if (status == FINISH)
    {
    	char forder[10] = {0};
    	char file[10] = {0};
    	char timeSend[50] = {0};
    	char bufferData[500] = {0};
        
        SIM checkSimStatus = SIM_STATUS_ERROR;

        checkMode = STOP;
        handleData();

        getDateTime(&realtimedata);
        getRealTime(&realtimedata);
        memcpy(forder, (char *)&realtimedata.dateTime, 8);
        memcpy(file, (char *)&realtimedata.realTime, 8);

        sprintf(timeSend, "DATE %s-TIME %s", forder, file);

        sprintf(bufferData , "{\"id\":\"%s\",\"time\":\"%s\",\"count\":\"%lu\",\"hour\":\"%lu\",\"minute\":\"%lu\",\"second\":\"%lu\",\"Distance high\":\"%.2f\",\"Distance\":\"%.2f\",\"flow water\":\"%.2f\",\"percent\":\"%.2f\"}", device.id, timeSend, data.count, data.hour, data.minute, data.second, data.Distance_high, data.Distance, data.Flow_warter, data.percent);

        SD_CARD_STATUS checkSdStatus = SD_CreatFile(forder, file, bufferData);
        if (checkSdStatus == SD_CARD_OK)
        {
            checkSimStatus = sendDataFirebase(bufferData);
        }
        finish_moniter(&data, checkSimStatus, checkSdStatus);
    }

    if (ButtionOn == 1)
    {
        HAL_NVIC_SystemReset();
        // ButtionOn = 0;
        // flagButtion = 0;
        // checkMode = RUN;
        // simStatus = simInit();
        // sdStatus = SD_Init();
        // dataInit();
        // home_moniter(simStatus, sdStatus, &data);
    }

    if (ButtionOn == 2)
    {
        ButtionOn = 0;
        flagButtion = 0;
        deviceInformatio(&device);
    }
    if (ButtionOn == 3 && flagButtion == 1)
    {
        ButtionOn = 0;
        data.Distance_high = data.Distance_high + 0.5;
        dataConfigure(&data);
    }
    if (ButtionOn == 4 && flagButtion == 1)
    {
        flagButtion = 1;
        ButtionOn = 0;
        data.Distance_high = data.Distance_high - 0.5;
        dataConfigure(&data);
    }
    if (ButtionOn == 5)
    {
        ButtionOn = 0;
        flagButtion = 1;
        dataConfigure(&data);
    }
    if (ButtionOn == 6 && flagButtion == 1)
    {
        ButtionOn = 0;
        data.Distance = data.Distance + 0.5;
        dataConfigure(&data);
    }
    if (ButtionOn == 7 && flagButtion == 1)
    {
        ButtionOn = 0;
        data.Distance = data.Distance - 0.5;
        dataConfigure(&data);
    }
}
