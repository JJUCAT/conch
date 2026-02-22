cmake_minimum_required(VERSION 3.13)
project(conch C)


# 外设驱动
set(DRIVERS_DIR "drivers/STM8S_StdPeriph_Driver/src")
set(DRIVER_SOURCES
  ${DRIVERS_DIR}/stm8s_clk.c
  ${DRIVERS_DIR}/stm8s_gpio.c
  ${DRIVERS_DIR}/stm8s_uart1.c
  ${DRIVERS_DIR}/stm8s_tim1.c
  ${DRIVERS_DIR}/stm8s_tim2.c
  ${DRIVERS_DIR}/stm8s_tim4.c
  ${DRIVERS_DIR}/stm8s_flash.c
)

# hal
set(HAL_DIR "hal")
set(HAL_SOURCES
  ${HAL_DIR}/sys.c
  ${HAL_DIR}/led.c
  ${HAL_DIR}/uart.c
)

# 用户功能
set(USER_DIR "user")
set(USER_SOURCES
  # ${USER_DIR}/system.c
)

set(USER_DIR "user")
set(USER_SOURCES
  # ${USER_DIR}/system.c
)


# 生成可执行文件（.ihx格式，用于烧录）
add_executable(${PROJECT_NAME}
  main.c
  stm8s_it.c
  ${DRIVER_SOURCES}
  ${HAL_SOURCES}
  ${USER_SOURCES}
)

# 设置目标自动包含的头文件路径
# PRIVATE 仅目标可见
# PUBLIC 目标及其依赖者可见
# INTERFACE 仅目标的依赖者可见
target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/drivers/STM8S_StdPeriph_Driver/inc
  ${CMAKE_SOURCE_DIR}/hal/include/
)


# 设置输出文件格式
set_target_properties(${PROJECT_NAME} PROPERTIES
  SUFFIX ".ihx"
  OUTPUT_NAME "${PROJECT_NAME}"
)
