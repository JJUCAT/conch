#!/bin/bash

set -e # 出错立即退出

# 将 stm8flash 添加到编译环境中
STM8FLASH_PATH=~/app/stm8flash/
export PATH=$PATH:$STM8FLASH_PATH
if ! command -v stm8flash &> /dev/null; then
  echo "错误: 在 $STM8FLASH_PATH 或系统路径中找不到 stm8flash 工具。"
  exit 1
fi

SCRIPT_DIR=$(cd "$(dirname "$0")"; pwd)
MCU="stm8s001j3" 
PROGRAMMER="stlinkv2"
TARGET="$SCRIPT_DIR/../../build/conch.ihx"

echo "================================"
echo " STM8 Project Flash System"
echo " MCU: $MCU"
echo " PROGRAMMER: $PROGRAMMER"
echo " TARGET = $TARGET"
echo "================================"

echo "检查 stm8flash 是否支持目标 MCU: $MCU..."
SUPPORTED_MCUS=$(stm8flash -l)
if echo "$SUPPORTED_MCUS" | grep -iwq "$MCU"; then
  echo " stm8flash 确认支持: $MCU"
else
  echo "错误: 目标 MCU '$MCU' 不在 stm8flash 支持列表中！"
  echo "支持列表如下："
  echo "$SUPPORTED_MCUS"
  exit 1
fi

if [ ! -f "$TARGET" ]; then
  echo "错误: 找不到目标文件 $TARGET, 请先执行编译。"
  exit 1
fi

# -c 指定烧录器, -p 指定芯片型号, -w 指定目标文件
# 如果报错，尝试在前面加上 sudo
stm8flash -c $PROGRAMMER -p $MCU -w $TARGET

if [ $? -eq 0 ]; then
  echo "烧录成功！"
else
  echo "烧录失败，请检查连线或权限。"
fi