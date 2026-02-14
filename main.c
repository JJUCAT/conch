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


static void delay(uint32_t t)
{
    while(t--);
}


int main(int argc, char** argv)
{

  CONFIG_UNUSED_PINS_STM8S001;

  systemConfig();


  while(1) {
    delay(3000);
  }
}


