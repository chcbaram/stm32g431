/*
 * can_mode.h
 *
 *  Created on: 2021. 6. 21.
 *      Author: baram
 */

#ifndef SRC_AP_MODE_CAN_MODE_H_
#define SRC_AP_MODE_CAN_MODE_H_

#include "ap_def.h"

bool canModeInit(void);
void canModeMain(mode_args_t *args);

#endif /* SRC_AP_MODE_CAN_MODE_H_ */
