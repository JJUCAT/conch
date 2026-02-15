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



#include "include/sys.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LED_PORT GPIOB
#define LED_PIN GPIO_PIN_4

#define USART_PORT GPIOB
#define USART_TX_PIN GPIO_PIN_5

#define TOUCH_PORT GPIOC
#define TOUCH_PIN GPIO_PIN_5
#define TOUCH_PIN0 GPIO_PIN_4
#define TOUCH_PIN1 GPIO_PIN_3

#define MOTOR_PORT GPIOD
#define MOTOR_PIN GPIO_PIN_5

#define SWIM_PORT GPIOD
#define SWIM_PORT0 GPIOC
#define SWIM_PIN GPIO_PIN_1
#define SWIM_PIN0 GPIO_PIN_3
#define SWIM_PIN1 GPIO_PIN_5
#define SWIM_PIN2 GPIO_PIN_6

#define BAT_V_ADC_PORT GPIOD
#define BAT_V_ADC_PIN GPIO_PIN_6

#define TIM4_PERIOD 124

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t g_timeing_delay = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void CLKInitialize()
{
  CLK_DeInit();
  CLK_HSICmd(ENABLE);
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_SPI, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, DISABLE);
  // CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, DISABLE);
  // CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
}


void GPIOInitialize()
{
  // 触摸配置
  GPIO_Init(TOUCH_PORT, TOUCH_PIN, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(TOUCH_PORT, TOUCH_PIN0, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(TOUCH_PORT, TOUCH_PIN1, GPIO_MODE_IN_FL_NO_IT);

  LightenRedLED(ENABLE);

}


/**
 * @brief 计时定时器
 * TIM4 时钟频率 = 16MHz / 128 = 125 000 Hz
 * 最大周期 = (255 + 1) / 125000 = 2.048 ms
 * 最小周期 = (  1 + 1) / 125000 = 0.016 ms
 * 1ms 周期 = (0.001 * 125000 - 1) = 124
 */
void TIM4_Config(void)
{
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_PERIOD);
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  TIM4_Cmd(ENABLE);


}


void TIM_ResetConfig(void)
{
  TIM1_ITConfig(TIM1_IT_UPDATE, DISABLE);
  TIM1_Cmd(DISABLE);
  TIM2_ITConfig(TIM1_IT_UPDATE, DISABLE);
  TIM2_Cmd(DISABLE);
}


void SPI_ResetConfig(void)
{
  SPI_Cmd(DISABLE);
}


void TimingDelay_Decrement(void)
{
  if (g_timeing_delay != 0x00)
    g_timeing_delay--;
}


/* Public functions ----------------------------------------------------------*/
void SystemConfig()
{
  CLKInitialize();
  GPIOInitialize();

  SPI_ResetConfig();
  TIM_ResetConfig();
  // TIM4_Config();

  // enableInterrupts();
}


void LightenRedLED(const FunctionalState state)
{
  if (ENABLE == state) {         
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
  } else {
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_OD_LOW_SLOW);
  }
}


bool IsTouch()
{
  if (GPIO_ReadInputPin(TOUCH_PORT, TOUCH_PIN)) {
    return TRUE;
  } else {
    return FALSE;
  }
}


void BlockingDelayMs(const uint32_t ms)
{
  g_timeing_delay = ms;
  while (g_timeing_delay != 0);
}

void SetMotor(const FunctionalState state)
{
  if (ENABLE == state) {         
    GPIO_Init(SWIM_PORT, SWIM_PIN, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(SWIM_PORT, SWIM_PIN0, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(SWIM_PORT, SWIM_PIN1, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(SWIM_PORT0, SWIM_PIN2, GPIO_MODE_OUT_PP_HIGH_SLOW);
  } else {
    GPIO_Init(SWIM_PORT, SWIM_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SWIM_PORT, SWIM_PIN0, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SWIM_PORT, SWIM_PIN1, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SWIM_PORT0, SWIM_PIN2, GPIO_MODE_OUT_PP_LOW_SLOW);
  }
}
