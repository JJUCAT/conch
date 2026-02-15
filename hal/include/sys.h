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



/**
 * @brief 系统配置
 */
void SystemConfig();


/**
 * @brief 红色 LED 控制
 * @param state
 *        @ENABLE: 点亮
 *        @DISABLE: 熄灭
 */
void LightenRedLED(const FunctionalState state);


/**
 * @brief 是否触摸了电容按键
 * @return true 
 * @return false 
 */
bool IsTouch();


/**
 * @brief 阻塞等待，uint:ms
 * @param ms 
 */
void BlockingDelayMs(const uint32_t ms);


/**
 * @brief 控制电机开关
 * @param state 
 *        @ENABLE: 开电机
 *        @DISABLE: 关电机
 */
void SetMotor(const FunctionalState state);


#ifdef __cplusplus
}
#endif

#endif // HAL_SYS_H
