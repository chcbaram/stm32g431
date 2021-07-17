/*
 * main.c
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */


#include "main.h"


static void mainThread(void const *argument);



int main(void)
{
  bspInit();


  osThreadDef(mainThread, mainThread, _HW_DEF_RTOS_THREAD_PRI_MAIN, 0, _HW_DEF_RTOS_THREAD_MEM_MAIN);
  if (osThreadCreate(osThread(mainThread), NULL) == NULL)
  {
    ledInit();
    while(1)
    {
      ledToggle(_DEF_LED1);
      delay(50);
    }
  }

  //-- Start scheduler
  //
  osKernelStart();

  return 0;
}

void mainThread(void const *argument)
{
  UNUSED(argument);

  hwInit();
  apInit();
  apMain();
}
