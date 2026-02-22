/**
 * @file usart.h
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-22
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HAL_UART_H
#define HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#ifdef _SDCC_

int putchar (int c);
int getchar (void);

#endif


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/



/**
 * @brief 调试串口配置
 * @attention 该配置会修改 pin1 脚 PD6 复用为 UART1_RX 功能
 * @param state 
 *        @ENABLE: 使用 UART 功能
 *        @DISABLE: 关闭 UART 功能
 */
void DebugUsartConfig(const FunctionalState state);




#ifdef __cplusplus
}
#endif

#endif // HAL_UART_H
