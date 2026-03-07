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
#include "include/uart.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TOUCH_PORT GPIOB
#define TOUCH_PIN GPIO_PIN_4

#define OPTION_BYTE_AFR_ADDRESS_OFFSET 0x03
#define ADC_ETR_AFR4 0x10

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO FunctionalState g_touch_state = DISABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void TouchOptionBytesConfig()
{
  FLASH_Unlock(FLASH_MEMTYPE_DATA);

  uint16_t afr_address =
    OPTION_BYTE_START_PHYSICAL_ADDRESS + OPTION_BYTE_AFR_ADDRESS_OFFSET;
  uint16_t afr_data = FLASH_ReadOptionByte(afr_address);
  printf("touch option, afr data:0x%x\r\n", afr_data);
  uint8_t data = (uint8_t)(afr_data >> 8);
  data = data | ADC_ETR_AFR4;
  FLASH_ProgramOptionByte(afr_address, data);

  FLASH_Lock(FLASH_MEMTYPE_DATA);
}

/* Public functions ----------------------------------------------------------*/

void TouchConfig()
{
  GPIO_Init(TOUCH_PORT, TOUCH_PIN, GPIO_MODE_IN_FL_NO_IT);
  TouchOptionBytesConfig();
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
