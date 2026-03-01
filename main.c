/**
 * @file main.c
 * @author jucat (lmr2887@163.com)
 * @brief conch 程序入口
 * @version 0.1
 * @date 2026-02-11
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */


#include "stm8s_conf.h"
#include "stm8s_it.h"
#include "hal/include/base.h"
#include "hal/include/sys.h"
#include "hal/include/led.h"
#include "hal/include/motor.h"
#include "hal/include/uart.h"

// 配置引脚默认模式
#define CONFIG_UNUSED_PINS_STM8S001 \
{ \
GPIOA->DDR |= GPIO_PIN_2; \
GPIOB->DDR |= GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_6 | GPIO_PIN_7; \
GPIOC->DDR |= GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_7; \
GPIOD->DDR |= GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_7; \
GPIOE->DDR |= GPIO_PIN_5; \
GPIOF->DDR |= GPIO_PIN_4; \
}


int main()
{
  CONFIG_UNUSED_PINS_STM8S001;

  // 延迟配置 SWIM 引脚
  uint32_t start_blocking_time = 5 * 1000;
  DelayMs(start_blocking_time);

  // 系统配置
  SystemConfig();
  BaseConfig();
  enableInterrupts();

  while(1) {
    printf("hello stm8s\r\n");  
    ToggleRedLED();
    TimerDelayMs(1000);
  }
}


