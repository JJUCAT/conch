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
#include "hal/include/sys.h"
#include "hal/include/led.h"
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


void delay_ms(const uint32_t t)
{
  uint32_t tt = 850;
  while (tt--) {
    uint32_t st = t;
    while(st--);
  }
}


int main()
{

  CONFIG_UNUSED_PINS_STM8S001;

  SystemConfig();

  // 延迟配置 SWIM 引脚
  uint32_t start_blocking_time = 10 * 1000;
  // BlockingDelayMs(start_blocking_time);
  delay_ms(start_blocking_time);

  // SetMotor(DISABLE);
  // uint32_t motor_worktime_max = 1 * 60 * 1000;
  // uint32_t motor_worktime = 0;

  while(1) {

    // if (IsTouch()) {
    //   if (motor_worktime == 0) {
    //     SetMotor(ENABLE);
    //     motor_worktime = motor_worktime_max;
    //   } else {
    //     SetMotor(DISABLE);
    //     motor_worktime = 0;
    //   }
    //   delay_ms(3);
    // }

    // if (motor_worktime > 0) {
    //   if (--motor_worktime == 0) {
    //     SetMotor(DISABLE);
    //   }
    // }

    printf("\n\r test \n\r");
    ToggleRedLED();
    // delay_ms(1000);
    delay_ms(1);
  }
}


