/**
 * @file battery.h
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-01
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HAL_BATTERY_H
#define HAL_BATTERY_H

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
 * @brief 电池配置
 */
void BatteryConfig();


/**
 * @brief 获取电池电压
 * @return float 
 */
float GetBatteryV();



#ifdef __cplusplus
}
#endif

#endif // HAL_BATTERY_H
