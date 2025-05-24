cmake_minimum_required(VERSION 3.21)

PROJECT(dmfix_win_console)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

InterfaceImport("dmfix_win_console" "include" "")

if (PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "dmfix_win_console")
endif()
