cmake_minimum_required(VERSION 3.10)

project(sort_experiment)

# 添加头文件所在的目录，以便 CMake 可以找到它
#include_directories(${CMAKE_SOURCE_DIR})

# 将 sort.c 编译成一个库
#add_library(sort_lib sort.c)

# 将你的可执行文件与库链接
add_executable(main main.c)

# 链接 sort_lib 库到可执行文件
#target_link_libraries(sort_experiment sort_lib)
