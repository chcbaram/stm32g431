/*
 * hw_def.h
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "bsp.h"


#define _USE_HW_RTC
#define _USE_HW_RESET

#define _USE_HW_LED
#define      HW_LED_MAX_CH          2

#define _USE_HW_CDC
#define _USE_HW_USB
#define      HW_USE_CDC             1
#define      HW_USE_MSC             0


#endif /* SRC_HW_HW_DEF_H_ */
