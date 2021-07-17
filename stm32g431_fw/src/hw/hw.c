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

  ret &= cliInit();
  ret &= logInit();
  ret &= rtcInit();
  ret &= resetInit();
  ret &= ledInit();

  if (resetGetCount() == 2)
  {
    resetToSysBoot();
  }

  logPrintf("[ Firmware Begin... ]\r\n");
  logPrintf("Booting..Name \t\t: %s\r\n", _DEF_BOARD_NAME);
  logPrintf("Booting..Ver  \t\t: %s\r\n", _DEF_FIRMWATRE_VERSION);


  ret &= usbInit();
  ret &= usbBegin(USB_CDC_MODE);
  ret &= uartInit();
  ret &= uartOpen(_DEF_UART1, 57600);
  ret &= canInit();
  ret &= i2cInit();

  logBoot(false);

  return ret;
}
