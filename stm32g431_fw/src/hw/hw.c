/*
 * hw.c
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */


#include "hw.h"





bool hwInit(void)
{
  bool ret = true;


  ret &= bspInit();

  ret &= cliInit();
  ret &= rtcInit();
  ret &= resetInit();
  ret &= ledInit();


  if (resetGetCount() == 2)
  {
    resetToSysBoot();
  }

  ret &= usbInit();
  ret &= usbBegin(USB_CDC_MODE);
  ret &= uartInit();
  ret &= uartOpen(_DEF_UART1, 57600);
  ret &= canInit();

  return ret;
}
