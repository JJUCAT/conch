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
#include "include/battery.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BATTERY_V_PORT GPIOD
#define BATTERY_V_PIN GPIO_PIN_6

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void ADC_Config()
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, ENABLE);

  ADC1_DeInit();
  ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_6, \
    ADC1_PRESSEL_FCPU_D2, ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, \
    ADC1_SCHMITTTRIG_CHANNEL6, DISABLE);
  ADC1_StartConversion();
}


/* Public functions ----------------------------------------------------------*/

void BatteryConfig()
{
  GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(BATTERY_V_PORT, BATTERY_V_PIN, GPIO_MODE_IN_FL_NO_IT);

  ADC_Config();
}


float GetBatteryV()
{
  uint16_t adc_value = ADC1_GetConversionValue();

  float v = 0.0;
  return v;
}
