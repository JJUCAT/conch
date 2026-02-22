/**
 * @file led.h
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-22
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HAL_LED_H
#define HAL_LED_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/**
 * @brief 红色 LED 控制
 * @param state
 *        @ENABLE: 点亮
 *        @DISABLE: 熄灭
 */
void LightenRedLED(const FunctionalState state);


/**
 * @brief 翻转红色 LED 状态
 */
void ToggleRedLED();



#ifdef __cplusplus
}
#endif

#endif // HAL_LED_H
