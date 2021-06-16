/*
 * reset.h
 *
 *  Created on: 2021. 6. 16.
 *      Author: baram
 */

#ifndef SRC_COMMON_HW_INCLUDE_RESET_H_
#define SRC_COMMON_HW_INCLUDE_RESET_H_

#include "hw_def.h"


#ifdef _USE_HW_RESET

#define RESET_REG_PARAM         0
#define RESET_REG_COUNT         1

bool resetInit(void);

uint32_t resetGetCount(void);
void resetToBoot(uint32_t timeout);
void resetToSysBoot(void);

#endif

#endif /* SRC_COMMON_HW_INCLUDE_RESET_H_ */
