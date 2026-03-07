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
#define VDDA 3300UL // VDDA 电压
#define VREF VDDA // ADC 参考电压
#define VREF_LOW 2750UL // ADC 最低电压
#define ADC_RES 1024UL // ADC 分辨率
#define TIMER_SEC 1000UL // 定时器 1 秒
#define TIMER_MIN 60000UL // 定时器 1 分钟

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
 * @brief 设置闹钟，延迟 ms 秒到时
 * @param ms 
 */
void TimerSetAlarmMs(const uint32_t ms);


/**
 * @brief 定时器闹钟到时
 * @return true 
 * @return false 
 */
bool TimerAlarm();


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
