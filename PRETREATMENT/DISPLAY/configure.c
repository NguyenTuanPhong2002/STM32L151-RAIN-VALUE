/*
 * configure.c
 *
 *  Created on: Jun 27, 2023
 *      Author: ACER
 */

#include "configure.h"

#include "stm32l1xx_hal_spi.h"

extern SPI_HandleTypeDef hspi1;

/**
 * The function writes a single byte of data to a SPI device using the HAL_SPI_Transmit function.
 *
 * @param value The byte value to be transmitted over SPI.
 */
void DEV_SPI_WriteByte(UBYTE value)
{
    HAL_SPI_Transmit(&hspi1, &value, 1, 100);
}

/**
 * The function initializes a module by setting the values of three pins.
 *
 * @return an integer value of 0.
 */
int DEV_Module_Init(void)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    return 0;
}

/**
 * This function exits the module by setting the DC pin to 0 and turning off the power and reset pins.
 */
void DEV_Module_Exit(void)
{
    DEV_Digital_Write(EPD_DC_PIN, 0);

    // close 5V
    // DEV_Digital_Write(EPD_PWR_PIN, 0);
    DEV_Digital_Write(EPD_RST_PIN, 0);
}

/**
 * The function sends data to a display using SPI communication.
 *
 * @param Data Data is a variable of type UBYTE (unsigned byte) that represents the data to be sent
 * over SPI (Serial Peripheral Interface) communication.
 */
void DISPLAY_SendData(UBYTE Data)
{
    DEV_Digital_Write(EPD_DC_PIN, 1);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    DEV_SPI_WriteByte(Data);
    DEV_Digital_Write(EPD_CS_PIN, 1);
}

/**
 * The function sends a command to a display using SPI communication.
 *
 * @param Reg The parameter "Reg" is an unsigned byte (8-bit) variable that represents the command to
 * be sent to the display. This function sends the command to the display using SPI communication
 * protocol. The EPD_DC_PIN and EPD_CS_PIN are digital pins used for data/command selection and chip
 * select respectively
 */
void DISPLAY_SendCommand(UBYTE Reg)
{

    DEV_Digital_Write(EPD_DC_PIN, 0);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    DEV_SPI_WriteByte(Reg);
    DEV_Digital_Write(EPD_CS_PIN, 1);
}

/**
 * This function checks if the e-Paper display is busy and waits until it is not busy before
 * continuing.
 */
void DISPLAY_ReadBusy(void)
{
    UBYTE busy;
    // do
    // {
    //     DISPLAY_SendCommand(0x71);
    //     busy = DEV_Digital_Read(EPD_BUSY_PIN);
    //     busy = !(busy);
    // } while (busy);
    //displayDelay(200);
}

/**
 * The function turns on the display and waits for it to refresh.
 */
void DISPLAY_TurnOnDisplay(void)
{
    DISPLAY_SendCommand(0x12); // DISPLAY REFRESH
    displayDelay(100);
    DISPLAY_ReadBusy();
}

/**
 * The function clears the display by sending black and red data to all pixels.
 */
void DISPLAY_Clear(void)
{
    UWORD Width =
        (DISPLAY_WIDTH % 8 == 0) ? (DISPLAY_WIDTH / 8) : (DISPLAY_WIDTH / 8 + 1);
    UWORD Height = DISPLAY_HEIGHT;

    // send black data
    DISPLAY_SendCommand(0x10);
    for (UWORD j = 0; j < Height; j++)
    {
        for (UWORD i = 0; i < Width; i++)
        {
            DISPLAY_SendData(0xFF);
        }
    }

    // send red data
    DISPLAY_SendCommand(0x13);
    for (UWORD j = 0; j < Height; j++)
    {
        for (UWORD i = 0; i < Width; i++)
        {
            DISPLAY_SendData(0xFF);
        }
    }

    DISPLAY_SendCommand(0x12);
    DISPLAY_ReadBusy();
}

/**
 * The function displays two images (black and red-yellow) on a display.
 *
 * @param blackimage A pointer to an array of UBYTE values representing the black and white image to be
 * displayed on the e-paper display.
 * @param ryimage The parameter "ryimage" is a pointer to an array of unsigned bytes that represents
 * the red and yellow image data to be displayed on the screen.
 */
void DISPLAY_Display(const UBYTE *blackimage, const UBYTE *ryimage)
{
    UWORD Width, Height;
    Width = (DISPLAY_WIDTH % 8 == 0) ? (DISPLAY_WIDTH / 8) : (DISPLAY_WIDTH / 8 + 1);
    Height = DISPLAY_HEIGHT;
    DISPLAY_SendCommand(0x10);
    for (UWORD j = 0; j < Height; j++)
    {
        for (UWORD i = 0; i < Width; i++)
        {
            DISPLAY_SendData(blackimage[i + j * Width]);
        }
    }
    //DISPLAY_SendCommand(0x92);

    DISPLAY_SendCommand(0x13);
    for (UWORD j = 0; j < Height; j++)
    {
        for (UWORD i = 0; i < Width; i++)
        {
            DISPLAY_SendData(ryimage[i + j * Width]);
        }
    }
    //DISPLAY_SendCommand(0x92);
    DISPLAY_SendCommand(0x12);
    DISPLAY_ReadBusy();
}

/**
 * The function puts the display into deep sleep mode.
 */
void DISPLAY_Sleep(void)
{
    DISPLAY_SendCommand(0X50);
    DISPLAY_SendData(0xf7);
    DISPLAY_SendCommand(0X02); // power off
    DISPLAY_ReadBusy();        // waiting for the electronic paper IC to release the idle signal
    DISPLAY_SendCommand(0X07); // deep sleep
    DISPLAY_SendData(0xA5);
}

void DISPLAY_Init(void)
{
    DISPLAY_Reset();

    DISPLAY_SendCommand(0x04);
    DISPLAY_ReadBusy(); // waiting for the electronic paper IC to release the idle signal

    DISPLAY_SendCommand(0x00); // panel setting
    // DISPLAY_SendData(0x0f);
    DISPLAY_SendData(0x8f);
    DISPLAY_ReadBusy();

    DISPLAY_SendCommand(0x61); // resolution setting
    DISPLAY_SendData(0x80);
    DISPLAY_SendData(0x01);
    DISPLAY_SendData(0x28);
    DISPLAY_ReadBusy();

    DISPLAY_SendCommand(0X50); // VCOM AND DATA INTERVAL SETTING
    DISPLAY_SendData(0x77);    // WBmode:VBDF 17|D7 VBDW 97 VBDB 57
                               // WBRmode:VBDF F7 VBDW 77 VBDB 37  VBDR B
}

void DISPLAY_Reset(void)
{
    DEV_Digital_Write(EPD_RST_PIN, 1);
    displayDelay(200);
    DEV_Digital_Write(EPD_RST_PIN, 0);
    displayDelay(5);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    displayDelay(200);
}
