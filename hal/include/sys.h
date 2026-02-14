/**
 * @file sys.h
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */



#ifndef HAL_SYS_H
#define HAL_SYS_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm8s.h"



#define LED_PORT GPIOB
#define LED_PIN GPIO_PIN_4

#define USART_PORT GPIOB
#define USART_TX_PIN GPIO_PIN_5

#define TOUCH_PORT GPIOC
#define TOUCH_PIN GPIO_PIN_5

#define MOTOR_PORT GPIOD
#define MOTOR_PIN GPIO_PIN_5

#define SWIM_PORT GPIOD
#define SWIM_PIN GPIO_PIN_5

#define BAT_V_ADC_PORT GPIOD
#define BAT_V_ADC_PIN GPIO_PIN_6







/**
 * @brief 系统配置
 */
void systemConfig();





#ifdef __cplusplus
}
#endif

#endif // HAL_SYS_H
