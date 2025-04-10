# 指定所需的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(Lab3Practice)

# 设置 C++ 标准（例如 C++11 或更高版本）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/inc)

# 定义源文件路径
set(SOURCES
    src/fib.cpp
    src/lab3_practice.cpp
    src/print_hello.cpp
)

# 生成可执行文件
add_executable(lab3_practice ${SOURCES})

# （可选）设置输出目录
set_target_properties(lab3_practice PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
)