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

  ret &= rtcInit();
  ret &= resetInit();
  ret &= ledInit();


  if (resetGetCount() == 2)
  {
    // Jump To SystemBootloader
    //
    resetToSysBoot();
  }

  return ret;
}
