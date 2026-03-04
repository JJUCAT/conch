/**
 * @file led.c
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-22
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */



/* Includes ------------------------------------------------------------------*/
#include "include/led.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_3


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO FunctionalState g_red_led_state = DISABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/* Public functions ----------------------------------------------------------*/

void RedLEDConfig()
{
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);
  LightenRedLED(DISABLE);
}


void LightenRedLED(const FunctionalState state)
{
  g_red_led_state = state;
  if (ENABLE == state) {         
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_HIGH_SLOW);
  } else {
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
  }
}


void ToggleRedLED()
{
  if (ENABLE == g_red_led_state) {
    LightenRedLED(DISABLE);
  } else {
    LightenRedLED(ENABLE);
  }
}

