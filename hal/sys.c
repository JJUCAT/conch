/**
 * @file sys.c
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Includes ------------------------------------------------------------------*/
#include "include/sys.h"
#include "include/led.h"
#include "include/motor.h"
#include "include/touch.h"
#include "include/uart.h"
#include "include/battery.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void CLKInitialize()
{
  CLK_DeInit();
  CLK_HSICmd(ENABLE);
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
}


void DevicesInitialize()
{
  DebugUARTConfig();
  RedLEDConfig();
  MotorConfig();
  TouchConfig();
  BatteryConfig();
}


/* Public functions ----------------------------------------------------------*/
void SystemConfig()
{
  CLKInitialize();
  DevicesInitialize();
}

