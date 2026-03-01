/**
 * @file motor.c
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Includes ------------------------------------------------------------------*/
#include "include/motor.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MOTOR_PORT GPIOC
#define MOTOR_PIN GPIO_PIN_5

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO FunctionalState g_motor_state = DISABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

void MotorConfig()
{
  GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
  SetMotorState(DISABLE);
}


void SetMotorState(const FunctionalState state)
{
  g_motor_state = state;
  if (ENABLE == state) {         
    GPIO_Init(MOTOR_PORT, MOTOR_PIN, GPIO_MODE_OUT_PP_HIGH_SLOW);
  } else {
    GPIO_Init(MOTOR_PORT, MOTOR_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
  }
}
