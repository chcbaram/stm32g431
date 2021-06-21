/*
 * cli_mode.c
 *
 *  Created on: 2021. 6. 21.
 *      Author: baram
 */


#include "cli_mode.h"





bool cliModeInit(void)
{
  return true;
}

void cliModeMain(mode_args_t *args)
{
  uint32_t pre_time = millis();


  logPrintf("cliMode in\n");

  while(args->keepLoop())
  {
    if (millis()-pre_time >= 100)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }

    cliMain();
  }

  logPrintf("cliMode out\n");
}
