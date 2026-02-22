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
#define LED_PORT GPIOB
#define LED_PIN GPIO_PIN_4

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO FunctionalState g_red_led_state = DISABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/* Public functions ----------------------------------------------------------*/

void LightenRedLED(const FunctionalState state)
{
  g_red_led_state = state;
  if (ENABLE == state) {         
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
  } else {
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_OD_LOW_SLOW);
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

