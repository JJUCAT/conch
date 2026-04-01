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


/* Includes ------------------------------------------------------------------*/
#include "stm8s_conf.h"
#include "stm8s_it.h"
#include "hal/include/base.h"
#include "hal/include/sys.h"
#include "hal/include/led.h"
#include "hal/include/motor.h"
#include "hal/include/uart.h"
#include "hal/include/battery.h"
#include "hal/include/touch.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define MOTOR_WORKTIME 1*TIMER_MIN // 电机工作时间


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
  uint32_t loop_delay = 100;
  uint32_t blocking_time = 5 * 1000;
  uint32_t delay_counter = 0;
  while(delay_counter < blocking_time) {
    delay_counter += loop_delay;
    ToggleRedLED();
    DelayMs(loop_delay);
  }

  // 系统配置
  SystemConfig();
  BaseConfig();
  enableInterrupts();

  printf("start task\n");
  while(1) {
    uint32_t battery_v = GetBatteryV();
    if (battery_v < 2700) LightenRedLED(ENABLE);
    else LightenRedLED(DISABLE);

    if (TRUE == IsTouch()) {
      printf("touch\n");
      if (TRUE == IsMotorRunning()) {
        printf("disable motor\n");
        SetMotorState(DISABLE);
      } else {
        printf("enable motor\n");
        SetMotorState(ENABLE);
        TimerSetAlarmMs(MOTOR_WORKTIME);
      }
    }
    
    if (TRUE == TimerAlarm() && TRUE == IsMotorRunning()) {
      printf("time is over\n");
      SetMotorState(DISABLE);
    }

    TimerDelayMs(1000);
  }
}


