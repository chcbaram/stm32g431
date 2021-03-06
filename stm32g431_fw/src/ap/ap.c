/*
 * ap.c
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */


#include "ap.h"
#include "mode/cli_mode.h"
#include "mode/can_mode.h"


typedef enum
{
  MODE_IDLE,
  MODE_CLI,
  MODE_CAN,
} ap_mode_t;


static ap_mode_t mode = MODE_IDLE;
static ap_mode_t mode_next = MODE_IDLE;
static mode_args_t mode_args;


static void apLedUpdate(void);
static bool apLoopIdle(void);
static void apGetModeNext(ap_mode_t *p_mode_next);

static void ledThread(void const *argument);


void apInit(void)
{
  cliOpen(_DEF_UART1, 57600);
  //canOpen(_DEF_CAN1, CAN_LOOPBACK, CAN_CLASSIC, CAN_500K, CAN_500K);
  canOpen(_DEF_CAN1, CAN_NORMAL, CAN_CLASSIC, CAN_1M, CAN_2M);
  i2cOpen(_DEF_I2C1, I2C_FREQ_400KHz);
  cliModeInit();
  canModeInit();

  mode_args.keepLoop = apLoopIdle;

  osThreadDef(ledThread, ledThread, _HW_DEF_RTOS_THREAD_PRI_LED, 0, _HW_DEF_RTOS_THREAD_MEM_LED);
  if (osThreadCreate(osThread(ledThread), NULL) == NULL)
  {
    logPrintf("ledThread Fail\n");
  }
}

void apMain(void)
{

  while(1)
  {
    switch(mode)
    {
      case MODE_CLI:
        cliModeMain(&mode_args);
        break;

      case MODE_CAN:
        canModeMain(&mode_args);
        break;

      default:
        apLoopIdle();
        break;
    }
  }
}

bool apLoopIdle(void)
{
  bool ret = true;


  apGetModeNext(&mode_next);
  if (mode != mode_next)
  {
    mode = mode_next;
    ret = false;

    ledOff(_DEF_LED1);
  }

  return ret;
}

void apLedUpdate(void)
{
  static uint32_t pre_time = 0;
  uint32_t led_blink_time;


  if (mode == MODE_CLI)
  {
    led_blink_time = 100;
  }
  else if (mode == MODE_CAN)
  {
    led_blink_time = 500;
  }
  else
  {
    led_blink_time = 1000;
  }


  if (millis()-pre_time >= led_blink_time)
  {
    pre_time = millis();
    ledToggle(_DEF_LED1);
  }
}

void apGetModeNext(ap_mode_t *p_mode_next)
{
  if (uartGetBaud(_DEF_UART1) == 1400)
  {
    *p_mode_next = MODE_CAN;
  }
  else
  {
    *p_mode_next = MODE_CLI;
  }

  if (usbIsOpen() != true)
  {
    *p_mode_next = MODE_IDLE;
  }
}

void ledThread(void const *argument)
{
  (void)argument;

  while(1)
  {
    apLedUpdate();
    delay(10);
  }
}
