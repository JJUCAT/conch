/**
 * @file base.c
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


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TIM4_PERIOD 124

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// 定时器定时计数器
__IO uint32_t g_timer_delay = 0;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief 计时定时器
 * TIM4 时钟频率 = 16MHz / 128 = 125 000 Hz
 * 最大周期 = (255 + 1) / 125000 = 2.048 ms
 * 最小周期 = (  1 + 1) / 125000 = 0.016 ms
 * 1ms 周期 = (0.001 * 125000 - 1) = 124
 */
void BaseTimer_Config(void)
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);

  TIM4_DeInit();
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_PERIOD);
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  TIM4_Cmd(ENABLE);
}


/**
 * @brief 定时器计数器增减
 */
void TimingDelay_Decrement(void)
{
  if (g_timer_delay != 0x00)
    g_timer_delay--;
}


/* Public functions ----------------------------------------------------------*/
void BaseConfig()
{
  BaseTimer_Config();


}


void TimerDelayMs(const uint32_t ms)
{
  g_timer_delay = ms;
  while (g_timer_delay != 0);
}


void DelayMs(uint32_t t)
{
  while (t--) {
    uint32_t st = 850;
    while(st--);
  }
}

