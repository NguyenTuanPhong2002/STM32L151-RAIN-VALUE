

#include "epaper.h"

// command 0x32
const unsigned char EPAPER_part[30] = {
    0x10, 0x18, 0x18, 0x08, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x13, 0x14, 0x44, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

};

// command 0x32
const unsigned char EPAPER_full[30] = {
    0x50, 0xAA, 0x55, 0xAA, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static void EPAPER_Reset(void)
{
    DEV_Digital_Write(RST, 1);
    DEV_Delay_ms(100);
    DEV_Digital_Write(RST, 0);
    DEV_Delay_ms(2);
    DEV_Digital_Write(RST, 1);
    DEV_Delay_ms(100);
}

static void EPAPER_SendCommand(UBYTE Reg)
{
    DEV_Digital_Write(DC, 0);
    DEV_Digital_Write(CS, 0);
    DEV_SPI_WriteByte(Reg);
    DEV_Digital_Write(CS, 1);
}

static void EPAPER_SendData(UBYTE Data)
{
    DEV_Digital_Write(DC, 1);
    DEV_Digital_Write(CS, 0);
    DEV_SPI_WriteByte(Data);
    DEV_Digital_Write(CS, 1);
}

static void EPAPER_TurnOnDisplay(void)
{
    EPAPER_SendCommand(0x22); // Display Update Control
    // EPAPER_SendData(0xc7);
    EPAPER_SendData(0xC7); // Activate Display Update Sequence
    EPAPER_SendCommand(0x20);
    EPAPER_SendCommand(0xFF);
    EPAPER_ReadBusy();
}

void EPAPER_UpdatePart(void)
{
    EPAPER_SendCommand(0x22);
    EPAPER_SendData(0x44);
    EPAPER_SendCommand(0x20);
    EPAPER_SendCommand(0xFF);
    EPAPER_ReadBusy();
}

void EPAPER_UpdateFass(void)
{
    EPAPER_SendCommand(0x22);
    EPAPER_SendData(0x04);
    EPAPER_SendCommand(0x20);
    EPAPER_SendCommand(0xFF);
    EPAPER_ReadBusy();
}

static void EPAPER_SetRamPoiter(UWORD Xstart, UWORD Ystart)
{
    EPAPER_SendCommand(0x4E);
    EPAPER_SendData(Xstart);

    EPAPER_SendCommand(0x4F);
    EPAPER_SendData((Ystart - 1) % 256);
    EPAPER_SendData((Ystart - 1) / 256);
}
void EPAPER_Base(UBYTE *Image)
{
    UWORD i;

    EPAPER_SendCommand(0x24); // Write Black and White image to RAM
    for (i = 0; i < 4736; i++)
    {
        EPAPER_SendData(Image[i]);
    }
    EPAPER_UpdatePart();
}

void EPAPER_ReadBusy(void)
{
    while (1)
    { //=1 BUSY
        if (DEV_Digital_Read(BUSY) == 0)
            break;
        DEV_Delay_ms(50);
    }
    DEV_Delay_ms(50);
}

static void EPAPER_SetCursor(UWORD Xstart, UWORD Ystart)
{
    EPAPER_SendCommand(0x44); // SET_RAM_X_ADDRESS_COUNTER
    EPAPER_SendData(0x00);
    EPAPER_SendData((Xstart - 1) / 8);

    EPAPER_SendCommand(0x45); // SET_RAM_Y_ADDRESS_COUNTER
    EPAPER_SendData((Ystart - 1) % 256);
    EPAPER_SendData((Ystart - 1) / 256);
    EPAPER_SendData(0x00);
    EPAPER_SendData(0x00);
}

static void EPAPER_SetRamArea(UWORD Xstart, UWORD Ystart)
{
    EPAPER_SendCommand(0x4E);
    EPAPER_SendData(Xstart / 8);
    EPAPER_SendCommand(0x44);
    EPAPER_SendData(Ystart % 256);
    EPAPER_SendData(Ystart / 256);
}

void EPAPER_Init(void)
{
    EPAPER_Reset();

    // EPAPER_SendCommand(0x12);

    EPAPER_SendCommand(0x01);
    EPAPER_SendData((EPAPER_WIDTH - 1) % 256);
    EPAPER_SendData((EPAPER_WIDTH - 1) / 256);
    EPAPER_SendData(0x00);

    EPAPER_SendCommand(0x0C);
    EPAPER_SendData(0xD7);
    EPAPER_SendData(0xD6);
    EPAPER_SendData(0xD9);

    EPAPER_SendCommand(0x2C);
    EPAPER_SendData(0x8A);

    EPAPER_SendCommand(0x3A);
    EPAPER_SendData(0x1A);

    EPAPER_SendCommand(0x3B);
    EPAPER_SendData(0x08);

    EPAPER_SendCommand(0x11);
    EPAPER_SendData(0x01);

    EPAPER_SetCursor(EPAPER_HEIGHT, EPAPER_WIDTH);

    EPAPER_SendCommand(0x4E);
    EPAPER_SendData(0x00);
    EPAPER_SendCommand(0x4F);
    EPAPER_SendData((EPAPER_WIDTH) % 256);
    EPAPER_SendData((EPAPER_WIDTH) / 256);

    EPAPER_SendCommand(0x32);
    EPAPER_SendData((unsigned char *)EPAPER_full);

    EPAPER_SendCommand(0x22);
    EPAPER_SendData(0xC0);
    EPAPER_SendCommand(0x20);
}

void EPAPER_Init_Part(void)
{
    EPAPER_Reset();
    // set up 2.9 inch lcd
    //  Pannel configuration, Gate selection
    EPAPER_SendCommand(0x01);
    EPAPER_SendData((EPAPER_WIDTH - 1) % 256);
    EPAPER_SendData((EPAPER_WIDTH - 1) / 256);
    EPAPER_SendData(0x00);

    // X decrease, Y decrease
    EPAPER_SendCommand(0x0C);
    EPAPER_SendData(0xD7);
    EPAPER_SendData(0xD6);
    EPAPER_SendData(0xD9);

    // Vcom setting
    EPAPER_SendCommand(0x2C);
    EPAPER_SendData(0x8A);

    // dummy line per gate
    EPAPER_SendCommand(0x3A);
    EPAPER_SendData(0x1A);

    // gate time setting
    EPAPER_SendCommand(0x3B);
    EPAPER_SendData(0x08);

    EPAPER_SendCommand(0x11);
    EPAPER_SendData(0x01);

    EPAPER_SetCursor(EPAPER_HEIGHT, EPAPER_WIDTH);

    EPAPER_SendCommand(0x4E);
    EPAPER_SendData(0x00);
    EPAPER_SendCommand(0x4F);
    EPAPER_SendData((EPAPER_WIDTH - 1) % 256);
    EPAPER_SendData((EPAPER_WIDTH - 1) / 256);

    EPAPER_SendCommand(0x32);
    EPAPER_SendData((unsigned char *)&EPAPER_part);

    EPAPER_SendCommand(0x22);
    EPAPER_SendData(0xC0);
    EPAPER_SendCommand(0x20);
}

void EPAPER_Clear(void)
{
    UWORD i;
    EPAPER_SendCommand(0x24); // write RAM for black(0)/white (1)
    for (i = 0; i < 4736; i++)
    {
        EPAPER_SendData(0xFF);
    }
    EPAPER_TurnOnDisplay();
}

void EPAPER_ClearPart(void)
{
    UWORD i;
    EPAPER_SendCommand(0x24); // write RAM for black(0)/white (1)
    for (i = 0; i < 4736; i++)
    {
        EPAPER_SendData(0xFF);
    }
    EPAPER_UpdatePart();
}

void test(void)
{
    UWORD i;
    EPAPER_SendCommand(0x24); // write RAM for black(0)/white (1)
    EPAPER_SendData(0x00);
    for (i = 0; i < 4735; i++)
    {
        EPAPER_SendData(0xFF);
    }
    EPAPER_UpdatePart();
}

void EPD_2IN9_V2_Display(UBYTE *Image)
{
    UWORD i;
    EPAPER_SendCommand(0x24); // write RAM for black(0)/white (1)
    for (i = 0; i < 4736; i++)
    {
        EPAPER_SendData(Image[i]);
    }
    EPAPER_UpdateFass();
}

void EPAPER_displayFast(UWORD Xstart, UWORD Ystart)
{
    EPAPER_SetCursor(Xstart, Ystart);
    EPAPER_SetRamArea(Xstart, Ystart);
}

void EPD_2IN9_V2_Display_Base(UBYTE *Image)
{
    UWORD i;

    EPAPER_SendCommand(0x24); // Write Black and White image to RAM
    for (i = 0; i < 4736; i++)
    {
        EPAPER_SendData(Image[i]);
    }
    EPAPER_SendCommand(0x26); // Write Black and White image to RAM
    for (i = 0; i < 4736; i++)
    {
        EPAPER_SendData(Image[i]);
    }
    EPAPER_UpdateFass();
}

void EPAPER_DisplayString(UWORD Xstart, UWORD Ystart, unsigned char *Buffer)
{
    // set ram area
    EPAPER_SendCommand(0x44);
    EPAPER_SendData(Xstart / 8);
    EPAPER_SendData((Xstart + 25) / 8);
    EPAPER_SendCommand(0x45);
    EPAPER_SendData(Ystart % 256);
    EPAPER_SendData(Ystart / 256);
    EPAPER_SendData((Ystart + 20) % 256);
    EPAPER_SendData((Ystart + 20) / 256);
    // set ram pointer
    EPAPER_SendCommand(0x4E);
    EPAPER_SendData(Xstart);
    EPAPER_SendCommand(0x4F);
    EPAPER_SendData(Ystart % 256);
    EPAPER_SendData(Ystart / 256);

    // send data
    EPAPER_SendCommand(0x24);
    int XSize = 25;
    int YSize = 20 + 1;
    int i = 0, j = 0;
    if (XSize % 8 != 0)
    {
        XSize = XSize + (8 - XSize % 8);
    }
    XSize = XSize / 8;
    for (i = 0; i < YSize; i++)
    {
        for (j = 0; j < XSize; j++)
        {
            // HAL_SPI_Transmit(&hspi1, Dispbuff, sizeof(*Dispbuff), 100);
            EPAPER_SendData(Buffer);
            Buffer++;
        }
    }
}

void EPAPER_DisplayPicture(UWORD Xstart, UWORD Ystart, unsigned char *Buffer)
{
    // set ram area
    EPAPER_SendCommand(0x44);
    EPAPER_SendData(0 / 8);
    EPAPER_SendData((EPAPER_HEIGHT - 1) / 8);
    EPAPER_SendCommand(0x45);
    EPAPER_SendData(0 % 256);
    EPAPER_SendData(0 / 256);
    EPAPER_SendData((EPAPER_WIDTH - 1) % 256);
    EPAPER_SendData((EPAPER_WIDTH - 1) / 256);
    // set ram pointer
    EPAPER_SendCommand(0x4E);
    EPAPER_SendData(Xstart);
    EPAPER_SendCommand(0x4F);
    EPAPER_SendData(Ystart % 256);
    EPAPER_SendData(Ystart / 256);

    // send data
    EPAPER_SendCommand(0x24);
    int XSize = 128;
    int YSize = 296;
    int i = 0, j = 0;
    if (XSize % 8 != 0)
    {
        XSize = XSize + (8 - XSize % 8);
    }
    XSize = XSize / 8;
    for (i = 0; i < YSize; i++)
    {
        for (j = 0; j < XSize; j++)
        {
            // HAL_SPI_Transmit(&hspi1, Dispbuff, sizeof(*Dispbuff), 100);
            EPAPER_SendData(Buffer);
            Buffer++;
        }
    }
}
