/*
 * bsp.h
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"

#include "cmsis_os.h"
#include "stm32g4xx_hal.h"


bool bspInit(void);

void delay(uint32_t time_ms);
uint32_t millis(void);

void Error_Handler(void);

void logPrintf(const char *fmt, ...);

#endif /* SRC_BSP_BSP_H_ */
