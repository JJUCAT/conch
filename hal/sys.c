/**
 * @file sys.c
 * @author jucat (lmr2887@163.com)
 * @brief 
 * @version 0.1
 * @date 2026-02-13
 * 
 * @copyright Copyright (c) 2026 jucat
 * 
 */



#include "include/sys.h"


void CLKInitialize()
{
  CLK_DeInit();
  CLK_HSICmd(ENABLE);
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
}


void GPIOInitialize()
{

}


void systemConfig()
{
  CLKInitialize();
  GPIOInitialize();
}






