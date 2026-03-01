/**
 * @file touch.c
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Includes ------------------------------------------------------------------*/
#include "include/base.h"
#include "include/touch.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TOUCH_PORT GPIOB
#define TOUCH_PIN GPIO_PIN_4

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO FunctionalState g_touch_state = DISABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

void TouchConfig()
{
  GPIO_Init(TOUCH_PORT, TOUCH_PIN, GPIO_MODE_IN_FL_NO_IT);
}


bool IsTouch()
{
  if (GPIO_ReadInputPin(TOUCH_PORT, TOUCH_PIN)) {
    TimerDelayMs(50);
    if (GPIO_ReadInputPin(TOUCH_PORT, TOUCH_PIN)) {
      g_touch_state = ENABLE;
      return TRUE;
    }
  }

  g_touch_state = DISABLE;
  return FALSE;
}
