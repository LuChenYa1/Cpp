cmake_minimum_required(VERSION 3.17)
project(Pro_MyMulti) # 起一个项目名称

# 1、普通写法:挨个列举
# add_executable(
#     DeBug
#     DeBug.cpp
#     Multi_Func/Circle.cpp
#     Multi_Func/Point.cpp
# ) # 可执行文件名字（位于build文件夹下） 要编译的文件（可多个）

# 2、使用set命令去新建变量来存放需要的源文件
# set( SRC_LIST
# 	 ./DeBug.cpp
# 	 ./Multi_Func/Circle.cpp
# 	 ./Multi_Func/Point.cpp)
# add_executable(
#     debug 
#     ${SRC_LIST})

# 3、使用aux_source_directory把当前目录下的源文件存列表存放到变量SRC_LIST里：无需挨个列举
# aux_source_directory(. SRC_LIST)
# add_executable(
#    DuBug 
#    ${SRC_LIST})

# 4、向工程添加多个指定头文件的搜索路径，路径之间用空格分隔：存在子级文件夹

# 设置默认构建类型为 Debug（如果未指定）
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

include_directories(Multi_Func) 
aux_source_directory(Multi_Func SRC_LIST)
add_executable(
    DeBug
    DeBug.cpp 
    ${SRC_LIST})
