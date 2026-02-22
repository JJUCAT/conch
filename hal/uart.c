/**
 * @file usart.c
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-22
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Includes ------------------------------------------------------------------*/
#include "stm8s_flash.h"
#include "stm8s_uart1.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define USART_PORT GPIOA
#define USART_TX_PIN GPIO_PIN_3
#define USART_FORBIT_PORT GPIOB
#define USART_FORBIT_PIN GPIO_PIN_5

#define OPTION_BYTE_AFR_ADDRESS_OFFSET 0x03
#define UART1_AFR 0x01
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/* Public functions ----------------------------------------------------------*/

void DebugUsartConfig(const FunctionalState state)
{
  GPIO_Init(USART_FORBIT_PORT, USART_FORBIT_PIN, GPIO_MODE_IN_FL_NO_IT);

  GPIO_Init(USART_PORT, USART_TX_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
  uint16_t afr_address = OPTION_BYTE_START_PHYSICAL_ADDRESS + OPTION_BYTE_AFR_ADDRESS_OFFSET;
  uint16_t afr_data = FLASH_ReadOptionByte(afr_address);
  uint8_t data = (uint8_t)(afr_data >> 8);
  if (ENABLE == state) {
    data = data | UART1_AFR;
  } else {
    uint8_t data = data & (~UART1_AFR);
  }
  FLASH_ProgramOptionByte(afr_address, data);

  UART1_DeInit();
  if (ENABLE == state) {
    uint32_t baudrate = 115200;
    UART1_Init(baudrate, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
      UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TX_ENABLE);
  }
}

#ifdef _SDCC_

int putchar(int c)
{
  UART1_SendData8(c);
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);

  return (c);
}


int getchar(void)
{
  char c = 0;
  while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
    c = UART1_ReceiveData8();
  return (c);
}

#endif
