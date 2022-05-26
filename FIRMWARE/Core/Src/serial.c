/*
 * serial.c
 *
 *  Created on: Apr 14, 2022
 *      Author: vienchau
 */


#include "serial.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "usbd_cdc_if.h"


uint8_t g_nRxBuff[MAX_LEN];
uint8_t g_strCommand[4];
uint8_t g_nOption[3];
uint8_t g_nData[8];
bool g_bDataAvailable = false;


uint8_t STX[] = {0x02U};
uint8_t ETX[] = {0x03U};
uint8_t ACK[] = {0x06U};
uint8_t SYN[] = {0x16U};

//cut the string
uint8_t *subString(uint8_t *pBuff, int nPos, int nIndex)
{
    uint8_t *t = &pBuff[nPos];
    pBuff[nPos -1] = '\0';
    for(int i = nIndex; i <(strlen((char*)t) + 1); i++)
    {
        t[i] = '\0';
    }
    return t;
}


//Compare 2 string
bool StrCompare(uint8_t *pBuff, uint8_t *pSample, uint8_t nSize)
{
    for (int i = 0; i < nSize; i++)
    {
        if(pBuff[i] != pSample[i])
        {
            return false;
        }
    }
    return true;
}

//send data to GUI
void SerialWriteComm(uint8_t *pStrCmd, uint8_t *pOpt, uint8_t *pData)
{
    uint8_t *pBuff;
    pBuff = (uint8_t *)malloc(18);
    uint8_t nIndex = 0;

    memcpy(pBuff + nIndex, STX, 1);
    nIndex += 1;
    memcpy(pBuff + nIndex, pStrCmd, 4);
    nIndex += 4;
    memcpy(pBuff + nIndex, pOpt, 3);
    nIndex += 3;
    memcpy(pBuff + nIndex, pData, 8);
    nIndex += 8;
    memcpy(pBuff + nIndex, ACK, 1);
    nIndex += 1;
    memcpy(pBuff + nIndex, ETX, 1);

	CDC_Transmit_FS(pBuff, MAX_LEN);

    free(pBuff);

}

//parse data to Command, Option, Data
void SerialParse(uint8_t *pBuff)
{
    if((pBuff[0] == STX[0] && (pBuff[17] == ETX[0])))
  {
    memcpy(g_strCommand, subString(g_nRxBuff, 1,4), 4);
    memcpy(g_nOption, subString(g_nRxBuff, 5,3), 3);
    memcpy(g_nData, subString(g_nRxBuff, 8,8), 8);
  }
}


