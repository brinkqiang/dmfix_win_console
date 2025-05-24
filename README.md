# dmfix_win_console - Windows UTF-8编码解决方案

[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmfix_win_console/blob/master/LICENSE)
[![Windows Build](https://github.com/brinkqiang/dmfix_win_console/actions/workflows/win.yml/badge.svg)](https://github.com/brinkqiang/dmfix_win_console/actions/workflows/win.yml)
[![GitHub Stars](https://img.shields.io/github/stars/brinkqiang/dmfix_win_console.svg?style=social)](https://github.com/brinkqiang/dmfix_win_console/stargazers)

专为Windows平台设计的UTF-8编码解决方案，解决MSVC编译器下的中文编码问题。

## 目录
- [dmfix\_win\_utf8 - Windows UTF-8编码解决方案](#dmfix_win_console---windows-utf-8编码解决方案)
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
Windows平台下使用MSVC编译器时，常遇到以下编码问题：
- 源代码文件需要保存为带BOM的UTF-8格式
- 控制台输出中文乱码
- 跨平台项目编码不统一

本库通过CMake集成方案，提供一站式解决方案。

## 特性
- 🚀 自动配置MSVC编译选项 `/utf-8`
- 🔧 简化CMake项目配置
- 🌍 支持跨平台开发
- 📦 轻量级头文件库

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

    // 使用标准输出
    std::cout << "中文测试" << std::endl;
    return 0;
}
```

### CMake配置示例
```cmake
# 确保源代码保存为UTF-8 with BOM
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
```

⚠️ **注意**：使用前请确保：
1. 源代码文件保存为UTF-8 with BOM格式
2. 在CMakeLists.txt中正确包含本库

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
