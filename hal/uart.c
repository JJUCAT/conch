/**
 * @file UART.c
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
#include "include/uart.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define UART_PORT GPIOA
#define UART_TX_PIN GPIO_PIN_3

#define OPTION_BYTE_AFR_ADDRESS_OFFSET 0x03
#define UART1_AFR 0x01

#define DEBUG_UART_BAUDRATE 9600
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void GPIOConfig()
{
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(UART_PORT, UART_TX_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
}


void UARTOptionBytesConfig()
{
  uint16_t afr_address =
    OPTION_BYTE_START_PHYSICAL_ADDRESS + OPTION_BYTE_AFR_ADDRESS_OFFSET;
  uint16_t afr_data = FLASH_ReadOptionByte(afr_address);
  uint8_t data = (uint8_t)(afr_data >> 8);
  data = data | UART1_AFR;
  FLASH_ProgramOptionByte(afr_address, data);
}


void UARTConfig()
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, ENABLE);

  UART1_DeInit();
  UART1_Init(DEBUG_UART_BAUDRATE, UART1_WORDLENGTH_8D,
    UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE,
    UART1_MODE_TX_ENABLE);
}


/* Public functions ----------------------------------------------------------*/

void DebugUARTConfig()
{
  GPIOConfig();
  UARTOptionBytesConfig();
  UARTConfig();
}


PUTCHAR_PROTOTYPE
{
  UART1_SendData8(c);
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);

  return (c);
}


GETCHAR_PROTOTYPE
{
#ifdef _COSMIC_
  char c = 0;
#else
  int c = 0;
#endif

  while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
    c = UART1_ReceiveData8();
  return (c);
}

