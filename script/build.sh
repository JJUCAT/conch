#!/bin/bash

set -e # 出错立即退出

SCRIPT_DIR=$(cd "$(dirname "$0")"; pwd)
PROJECT_ROOT=$(cd "$SCRIPT_DIR/../.."; pwd)
CMAKE_DIR="$PROJECT_ROOT/src"
BUILD_DIR=$PROJECT_ROOT/build


echo "================================"
echo " STM8 Project Build System"
echo " SCRIPT_DIR: $SCRIPT_DIR"
echo " PROJECT_ROOT: $PROJECT_ROOT"
echo " CMAKE_DIR = $CMAKE_DIR"
echo " BUILD_DIR = $BUILD_DIR"
echo "================================"


# 清理旧数据
case "$1" in
  clean)
    echo "Cleaning build directory..."
    rm -rf $BUILD_DIR
    exit 0
    ;;
esac


# 创建目录
mkdir -p $BUILD_DIR
cd $BUILD_DIR


# 编译
cmake "$CMAKE_DIR" \
  -DCMAKE_TOOLCHAIN_FILE="$CMAKE_DIR/toolchain-stm8.cmake" \
  -DCMAKE_BUILD_TYPE=Release

make -j$(nproc)


echo "================================"
echo " Build Done"
echo "================================"
