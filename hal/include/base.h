/**
 * @file base.h
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HAL_BASE_H
#define HAL_BASE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
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

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/**
 * @brief 系统基础配置
 * @details 延迟函数
 */
void BaseConfig();


/**
 * @brief 定时器延迟
 * @attention 精确延迟
 * @param ms 
 */
void TimerDelayMs(const uint32_t ms);


/**
 * @brief 延迟
 * @attention 粗野延迟
 * @param ms 
 */
void DelayMs(uint32_t t);


#ifdef __cplusplus
}
#endif

#endif // HAL_BASE_H
