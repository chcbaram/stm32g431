/*
 * ap.c
 *
 *  Created on: Jun 13, 2021
 *      Author: baram
 */


#include "ap.h"


typedef enum
{
  MODE_IDLE,
  MODE_CLI,
  MODE_CAN,
} ap_mode_t;


static ap_mode_t mode = MODE_IDLE;
static ap_mode_t mode_next = MODE_IDLE;


static void apLedUpdate(void);
static bool apLoopIdle(void);
static void apGetModeNext(ap_mode_t *p_mode_next);
static void apModeCli(void);
static void apModeCan(void);




void apInit(void)
{
  cliOpen(_DEF_UART1, 57600);
}

void apMain(void)
{

  while(1)
  {
    apLoopIdle();

    switch(mode)
    {
      case MODE_CLI:
        apModeCli();
        break;

      case MODE_CAN:
        apModeCan();
        break;

      default:
        break;
    }
  }
}

bool apLoopIdle(void)
{
  bool ret = true;


  apLedUpdate();

  apGetModeNext(&mode_next);
  if (mode != mode_next)
  {
    mode = mode_next;
    ret = false;
  }

  return ret;
}

void apLedUpdate(void)
{
  static uint32_t pre_time = 0;


  if (millis()-pre_time >= 500)
  {
    pre_time = millis();
    ledToggle(_DEF_LED1);
  }

  if (usbIsOpen() == true)
  {
    ledOn(_DEF_LED2);
  }
  else
  {
    ledOff(_DEF_LED2);
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
}

void apModeCli(void)
{
  cliMain();
}

void apModeCan(void)
{
  if (uartAvailable(_DEF_UART1) > 0)
  {
    uartPrintf(_DEF_UART1, "RX : 0x%X\n", uartRead(_DEF_UART1));
  }
}
