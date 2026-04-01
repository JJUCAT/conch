/**
 * @file battery.c
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
#include "include/battery.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BATTERY_V_PORT GPIOD
#define BATTERY_V_PIN GPIO_PIN_6

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint16_t g_adc_value = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void ADC_Config()
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, ENABLE);

  ADC1_DeInit();
  // ADC 时钟 = 16MHz / 18 = 889kHz
  // 一次 ADC 转换需要 14 个时钟
  // 一次 ADC 转换耗时 = 14 / 889kHz = 16ms
  ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_6, \
    ADC1_PRESSEL_FCPU_D18, ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, \
    ADC1_SCHMITTTRIG_CHANNEL6, DISABLE);
  // ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);

  ADC1_StartConversion();
}


void UpdateBatteryADC(const uint16_t adc_v)
{
  g_adc_value = adc_v;
}

/* Public functions ----------------------------------------------------------*/

void BatteryConfig()
{
  GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(BATTERY_V_PORT, BATTERY_V_PIN, GPIO_MODE_IN_FL_NO_IT);

  ADC_Config();
}


uint32_t GetBatteryV()
{
  while(RESET == ADC1_GetFlagStatus(ADC1_FLAG_EOC));
  uint16_t adc_value = ADC1_GetConversionValue();
  ADC1_ClearFlag(ADC1_FLAG_EOC);
  uint32_t v = VREF * adc_value / ADC_RES;
  v = v * 2; // 根据原理图计算
  return v;
}
