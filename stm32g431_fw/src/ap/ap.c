/*
 * ap.c
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */


#include "ap.h"





void apInit(void)
{

}

void apMain(void)
{
  uint32_t pre_time[2];

  pre_time[0] = millis();
  pre_time[1] = millis();
  while(1)
  {
    if (millis()-pre_time[0] >= 500)
    {
      pre_time[0] = millis();
      ledToggle(_DEF_LED1);
    }

    if (millis()-pre_time[1] >= 100)
    {
      pre_time[1] = millis();
      ledToggle(_DEF_LED2);
    }
  }
}
