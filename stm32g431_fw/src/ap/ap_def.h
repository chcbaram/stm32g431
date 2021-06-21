/*
 * ap_def.h
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */

#ifndef SRC_AP_AP_DEF_H_
#define SRC_AP_AP_DEF_H_

#include "hw.h"


typedef struct
{
  bool (*keepLoop)(void);
} mode_args_t;


#endif /* SRC_AP_AP_DEF_H_ */
