/*
 * can_mode.c
 *
 *  Created on: 2021. 6. 21.
 *      Author: baram
 */


#include "can_mode.h"



//static uint8_t can_ch = _DEF_CAN1;




bool canModeInit(void)
{
  return true;
}

void canModeMain(mode_args_t *args)
{
  uint32_t pre_time = millis();


  logPrintf("canMode in\n");

  while(args->keepLoop())
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }


    if (uartAvailable(_DEF_UART1) > 0)
    {
      uartPrintf(_DEF_UART1, "RX : 0x%X\n", uartRead(_DEF_UART1));
    }
  }

  logPrintf("canMode out\n");
}
