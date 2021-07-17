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

  logPrintf("cliMode in\n");

  while(args->keepLoop())
  {
    cliMain();
    delay(2);
  }

  logPrintf("cliMode out\n");
}
