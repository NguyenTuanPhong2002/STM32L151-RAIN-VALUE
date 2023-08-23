/*
 * sim7600.c
 *
 *  Created on: May 29, 2023
 *      Author: ACER
 */

#include "sim7600.h"

/**
 * The function initializes the SIM7600 structure with the UART and HDMA pointers and sets the rxFlag
 * to FALSE.
 *
 * @param sim a pointer to a SIM7600 struct, which likely contains information about the SIM7600 module
 * being used.
 */
void SIM7600_init(SIM7600 *sim)
{
    sim->UART = &huart1;
    sim->HDMA = &hdma_usart1_rx;
    sim->rxFlag = SIMFALSE;
}

/**
 * The function `sendATcommand` sends an AT command to a SIM7600 module and waits for a response,
 * returning the status of the operation.
 *
 * @param sim A pointer to the SIM7600 structure, which contains information about the SIM7600 module.
 * @param ATCommand The AT command to send to the SIM7600 module.
 * @param Response The "Response" parameter is a string that represents the expected response from the
 * SIM7600 module after sending the AT command.
 * @param unexpect The "unexpect" parameter is a string that represents an unexpected response from the
 * SIM7600 module. If the received response from the module matches this string, the function will
 * return SIM_ERROR.
 * @param Timeout The Timeout parameter is the maximum time in milliseconds that the function will wait
 * for a response from the SIM7600 module before considering it a timeout.
 *
 * @return a value of type SIM_StatusTypeDef.
 */
SIM_StatusTypeDef sendATcommand(SIM7600 *sim, const char *ATCommand,
                                const char *Response, const char *unexpect, uint32_t Timeout)
{
    SIM_StatusTypeDef status = SIM_BUSY;
    HAL_UARTEx_ReceiveToIdle_DMA(sim->UART, sim->rxBuffer, SIM_BUFFER_SIZE);
    __HAL_DMA_DISABLE_IT(sim->HDMA, DMA_IT_HT);
    //-----------------------------------------------------------------------
    memset((char *)sim->rxBuffer, 0, SIM_BUFFER_SIZE);
    memset((char *)sim->txBuffer, 0, SIM_TX_BUFFER_SIZE);
    sprintf((char *)sim->txBuffer, "%s\r\n", ATCommand);
    uint16_t len = strlen((char *)sim->txBuffer);
    HAL_UART_Transmit(sim->UART, (uint8_t *)sim->txBuffer, len, HAL_MAX_DELAY);
    //-----------------------------------------------------------------------
    uint32_t tickStart = HAL_GetTick();
    while (status == SIM_BUSY)
    {
        if ((HAL_GetTick() - tickStart >= Timeout))
        {
            status = SIM_TIMEOUT;
            break;
        }
        if (sim->rxFlag == SIMTRUE)
        {
            if (strstr((char *)sim->rxBuffer, Response) != NULL)
            {
                status = SIM_OK;
                break;
            }
            else if (strstr((char *)sim->rxBuffer, unexpect) != NULL)
            {
                status = SIM_ERROR;
                break;
            }
        }
    }
    sim->rxFlag = SIMFALSE;
    return status;
}

/**
 * The function sends an AT command to the SIM7600 module and returns the status of the command
 * execution.
 *
 * @param sim a pointer to a SIM7600 struct, which contains information about the SIM7600 module being
 * used.
 *
 * @return The function `SIM7600_Start` is returning a `SIM_StatusTypeDef` which is a user-defined data
 * type that represents the status of the SIM7600 module. The actual value being returned depends on
 * the result of the `sendATcommand` function, which is called with the parameters `sim`, `"AT"`,
 * `"OK"`, `"ERROR"`, and `1200`.
 */
SIM_StatusTypeDef SIM7600_Start(SIM7600 *sim)
{
    SIM_StatusTypeDef status = SIM_BUSY;
    if (sendATcommand(sim, "AT", "OK", "ERROR", 1200) == SIM_OK)
        if (sendATcommand(sim, "AT+CPIN?", "OK", "ERROR", 1200) == SIM_OK)
            if (sendATcommand(sim, "AT+CSQ", "OK", "ERROR", 1200) == SIM_OK)
                if (sendATcommand(sim, "AT+CGMR", "OK", "ERROR", 1200) == SIM_OK)
                    if (sendATcommand(sim, "AT+CTZU=1", "OK", "ERROR", 1200) == SIM_OK)
                        status = SIM_OK;
    return status;
};

/**
 * The function starts an HTTP session on a SIM7600 module.
 *
 * @param sim a pointer to a SIM7600 struct, which contains information about the SIM7600 module being
 * used.
 *
 * @return The function `SIM7600_httpStart` is returning a `SIM_StatusTypeDef` which is the result of
 * calling the `sendATcommand` function with the parameters `sim`, `"AT+HTTPINIT"`, `"OK"`, `"ERROR"`,
 * and `1200`.
 */
SIM_StatusTypeDef SIM7600_httpStart(SIM7600 *sim)
{
    SIM7600_httpStop(sim);
    return sendATcommand(sim, "AT+HTTPINIT", "OK", "ERROR", 1200);
};

/**
 * The function stops the HTTP service on a SIM7600 module.
 *
 * @param sim a pointer to a SIM7600 object, which contains information about the SIM7600 module being
 * used.
 *
 * @return The function `SIM7600_httpStop` is returning a `SIM_StatusTypeDef` which is a user-defined
 * data type that represents the status of the SIM7600 module. The return value depends on the success
 * or failure of the `sendATcommand` function which sends an AT command to the module and waits for a
 * response. If the response contains "OK", the function returns `SIM_SUCCESS`
 */
SIM_StatusTypeDef SIM7600_httpStop(SIM7600 *sim)
{
    return sendATcommand(sim, "AT+HTTPTERM", "OK", "ERROR", 500);
};

/**
 * The function sends AT commands to a SIM7600 module to read data from a specified URL using HTTP.
 *
 * @param sim a pointer to a SIM7600 object, which contains information about the SIM module being
 * used.
 * @param url a string containing the URL to be accessed by the HTTP request.
 *
 * @return If the function executes successfully, it will return SIM_BUSY. If there is an error or the
 * function fails to execute, it will return SIM_OK.
 */
SIM_StatusTypeDef SIM7600_httpRead(SIM7600 *sim, const char *url)
{
    if (SIM7600_httpStart(sim) == SIM_OK)
    {
        char Url[200];
        sprintf((char *)Url, "AT+HTTPPARA=\"URL\",\"%s\"", url);
        if (sendATcommand(sim, (char *)Url, "OK", "ERROR", 1200) == SIM_OK)
        {
            if (sendATcommand(sim, "AT+HTTPACTION=0", "OK", "ERROR", 1200) == SIM_OK)
            {
                if (sendATcommand(sim, "AT+HTTPREAD=300", "OK", "ERROR", 1200) == SIM_OK)
                    return SIM_BUSY;
            }
        }
    }
    return SIM_OK;
}

/**
 * The function sets the URL parameter for HTTP requests on a SIM7600 module.
 *
 * @param sim a pointer to a SIM7600 struct, which contains information about the SIM7600 module being
 * used.
 * @param url A pointer to a string containing the URL to be set for the HTTP request.
 *
 * @return a SIM_StatusTypeDef, which is likely an enumerated type indicating the success or failure of
 * the operation.
 */
SIM_StatusTypeDef SIM7600_setUrl(SIM7600 *sim, const char *url)
{
    if (SIM7600_httpStart(sim) == SIM_OK)
    {
        uint8_t cmd[100] = {0};
        sprintf((char *)cmd, "AT+HTTPPARA=\"URL\",\"%s\"", url);
        return sendATcommand(sim, (char *)cmd, "OK", "ERROR", 12000);
    }
}

/**
 * The function sends an HTTP POST request with JSON data to a specified SIM7600 module.
 *
 * @param sim a pointer to a SIM7600 object, which contains information about the SIM7600 module and
 * its communication settings.
 * @param data A pointer to a character array containing the data to be sent in the HTTP POST request.
 *
 * @return a SIM_StatusTypeDef, which is likely an enumerated type indicating the status of the HTTP
 * POST request.
 */
SIM_StatusTypeDef SIM7600_httpPost(SIM7600 *sim, const char *data)
{
    // sendATcommand(sim, "AT+HTTPPARA=\"CONTENT\",\"application/json\"", "OK", "ERROR", 12000);
    uint8_t cmd[30] = {0};
    uint8_t len = strlen(data);
    sprintf((char *)cmd, "AT+HTTPDATA=%d,%d", len, 12000);
    if (sendATcommand(sim, "AT+HTTPACTION=1", "+HTTPACTION: 1,400", "ERROR", 12000) == SIM_OK)
    {
        if (sendATcommand(sim, (char *)cmd, "DOWNLOAD", "ERROR", 12000) != SIM_OK)
        {
            return sendATcommand(sim, (char *)cmd, "DOWNLOAD", "ERROR", 12000);
        }
        else
        {
            sendATcommand(sim, data, "OK", "ERROR", 12000);
        }
    }
    return sendATcommand(sim, "AT+HTTPACTION=1", "+HTTPACTION: 1,200", "ERROR", 12000);
}

// read data from fire base
//  if (SIM7600_httpRead(&sim, "https://rain-4a16a-default-rtdb.firebaseio.com/123.json") == TRUE)
//        {
//          sprintf((char *)text, "%s", &sim.rxBuffer);
//        }

/**
 * The function SIM7600_getTime retrieves the current time from a SIM7600 module.
 *
 * @param sim A pointer to the SIM7600 object, which contains information about the SIM7600 module.
 *
 * @return a SIM_StatusTypeDef, which is an enumerated type. It can either return SIM_OK or SIM_ERROR.
 */
SIM_StatusTypeDef SIM7600_getTime(SIM7600 *sim)
{
    if (sendATcommand(sim, "AT+CCLK=?", "OK", "ERROR", 12000) == SIM_OK)
        if (sendATcommand(sim, "AT+CCLK?", "OK", "ERROR", 12000) == SIM_OK)
            return SIM_OK;
    return SIM_ERROR;
};
