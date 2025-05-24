# dmfix_win_console - Windows控制台颜色输出解决方案

[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmfix_win_console/blob/master/LICENSE)
[![Windows Build](https://github.com/brinkqiang/dmfix_win_console/actions/workflows/win.yml/badge.svg)](https://github.com/brinkqiang/dmfix_win_console/actions/workflows/win.yml)
[![GitHub Stars](https://img.shields.io/github/stars/brinkqiang/dmfix_win_console.svg?style=social)](https://github.com/brinkqiang/dmfix_win_console/stargazers)

专为Windows平台设计的控制台颜色输出解决方案，修复默认输出ANSI转义码(\33)显示问题。

## 目录
- [dmfix\_win\_console - Windows控制台颜色输出解决方案](#dmfix_win_console---windows控制台颜色输出解决方案)
    - [目录](#目录)
    - [背景](#背景)
    - [特性](#特性)
    - [安装](#安装)
        - [通过CMake集成](#通过cmake集成)
    - [使用指南](#使用指南)
        - [基本使用](#基本使用)
        - [CMake配置示例](#cmake配置示例)
    - [贡献指南](#贡献指南)
    - [测试](#测试)
    - [许可证](#许可证)

## 背景
Windows控制台默认不兼容ANSI转义码，导致以下问题：
- 颜色输出显示为原始转义字符（如\33[32m）
- 跨平台应用的终端输出不一致
- 需要手动启用虚拟终端支持

本方案通过自动配置控制台和编译器，提供无缝的颜色输出支持。

## 特性
- 🎨 自动启用Windows虚拟终端(ENABLE_VIRTUAL_TERMINAL_PROCESSING)
- 🔧 简化CMake配置流程
- 💻 支持现代控制台应用开发
- 📦 跨平台兼容性设计
- ⚡ 零额外依赖

## 安装
### 通过CMake集成
```cmake
include(FetchContent)
FetchContent_Declare(
    dmfix_win_console
    GIT_REPOSITORY https://github.com/brinkqiang/dmfix_win_console.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(dmfix_win_console)

target_link_libraries(your_target PRIVATE dmfix_win_console)
```

## 使用指南
### 基本使用
```cpp
#include "dmfix_win_console.h"

int main() {
    // 纯C 需要 自己初始化控制台配置 C++仅包含头文件即可
    dm_win_console_init();
    
    // 正常输出颜色代码
    std::cout << "\033[32mSuccess!\033[0m" << std::endl;
    std::cout << "\033[31mError!\033[0m" << std::endl;
    return 0;
}
```

### CMake配置示例
```cmake
# 自动配置控制台虚拟终端支持
target_link_libraries(your_target PRIVATE dmfix_win_console)

```

⚠️ **注意**：
1. 需要Windows 10 1607+ 或更新版本
2. 确保调用dm_win_console_init()初始化
3. 支持标准ANSI转义码格式

## 贡献指南
欢迎通过Issue和PR参与贡献！请遵循：
1. 提交前运行测试用例
2. 保持代码风格统一
3. 更新相关文档

## 测试
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
ctest -C Release
```

## 许可证
本项目采用 [MIT许可证](LICENSE)，欢迎自由使用和修改。

---
维护者：[@brinkqiang](https://github.com/brinkqiang)  
项目地址：https://github.com/brinkqiang/dmfix_win_console
