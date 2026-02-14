# 交叉编译的目标系统
# 常见参数 @Linux @Windows @Generic 裸机mcu @BareMetal 新版裸机
set(CMAKE_SYSTEM_NAME Generic)
# 交叉编译的目标芯片架构
# 常见参数 @arm @arm-none-eabi @riscv @avr @stm8 等
set(CMAKE_SYSTEM_PROCESSOR stm8)

# 指定 c 编译器
set(CMAKE_C_COMPILER sdcc)
#指定汇编编译器
# set(CMAKE_ASM_COMPILER sdcc)

# 定义变量，这个变量是下面给编译器用的
# 指定芯片型号，这里是 sdcc 的参数，必须是 sdcc 支持的芯片架构
# 执行 sdcc --help 查看支持芯片架构
set(FAMILY stm8)
set(MCU STM8S001)
set(COMPILER __SDCC__)

# 定义宏
add_definitions(-D${COMPILER} -D${MCU})

# 上面指定的 c 编译器执行的“全局”指令
set(CMAKE_C_FLAGS "-m${FAMILY} --std-c99 --opt-code-size" CACHE INTERNAL "c compiler flags")
