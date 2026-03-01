/**
 * @file touch.h
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HAL_TOUCH_H
#define HAL_TOUCH_H

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


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/**
 * @brief 触摸配置
 */
void TouchConfig();


/**
 * @brief 是否触摸
 * @attention 带防抖滤波
 * @return true 有触摸
 * @return false 无触摸
 */
bool IsTouch();



#ifdef __cplusplus
}
#endif

#endif // HAL_TOUCH_H
