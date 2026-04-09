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
#define MOTOR_PIN GPIO_PIN_3

#define TIM1_PRESCALER_128 128
#define TIM1_PERIOD 124
#define TIM1_OC3_WIDTH 15

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO FunctionalState g_motor_state = DISABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
 * @brief 计时定时器
 * TIM4 时钟频率 = 16MHz / 128 = 125 000 Hz
 * 最大周期 = (255 + 1) / 125000 = 2.048 ms
 * 最小周期 = (  1 + 1) / 125000 = 0.016 ms
 * 1ms 周期 = (0.001 * 125000 - 1) = 124
 */
void PWM_Config(void)
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE);

  TIM1_DeInit();
  TIM1_TimeBaseInit(TIM1_PRESCALER_128, TIM1_COUNTERMODE_UP, TIM1_PERIOD, 0);
  TIM1_OC3Init(TIM1_OCMODE_PWM2, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_ENABLE,
               TIM1_OC3_WIDTH, TIM1_OCPOLARITY_LOW, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET,
               TIM1_OCNIDLESTATE_RESET);
  TIM1_Cmd(ENABLE);
  TIM1_CtrlPWMOutputs(DISABLE);
}


/* Public functions ----------------------------------------------------------*/

void MotorConfig()
{
  SetMotorState(DISABLE);
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);

  PWM_Config();
}


void SetMotorState(const FunctionalState state)
{
  g_motor_state = state;
  if (ENABLE == state) {
    TIM1_CtrlPWMOutputs(ENABLE);
  } else {
    TIM1_CtrlPWMOutputs(DISABLE);
  }
}


bool IsMotorRunning()
{
  return ENABLE == g_motor_state;
}
