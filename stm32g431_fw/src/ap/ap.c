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

    if (cdcIsConnect() == true)
    {
      ledOn(_DEF_LED2);
    }
    else
    {
      ledOff(_DEF_LED2);
    }

    if (cdcAvailable() > 0)
    {
      uint8_t rx_data;

      rx_data = cdcRead();

      cdcWrite("RX : ", 5);
      cdcWrite(&rx_data, 1);
      cdcWrite("\n", 1);
    }
  }
}
