cmake_minimum_required(VERSION 3.17)

project(Pro_WorkerManager) # 起一个项目名称

add_executable(
    DeBug
    DeBug.cpp
    Boss.cpp 
    Employee.cpp 
    Manager.cpp
    workerManager.cpp
    Worker.h
) # 可执行文件名字（位于build文件夹下） 要编译的文件（可多个）
