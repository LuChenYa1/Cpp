# MinGW、mingw64、GCC、gcc、g++

VScode只是一个编辑器，没有编译调试功能，用户可以根据自身需求来配置特定的编译器和插件

## mingw64

MinGW（Minimalist GNU for Windows）是一个为 Windows 系统提供 GCC（GNU Compiler Collection）的编译器系统。它包括了 C、C++ 和 Fortran 的编译器以及其他相关工具。

MinGW-w64 是 MinGW 的一个分支，它支持 32 位和 64 位 Windows 系统。

mingw64 是 MinGW-w64 分发版的一部分，它提供了针对 Windows 64 位系统的交叉编译工具链，包含了 GCC 和 G++ 编译器的特定版本，这些版本被配置为交叉编译环境，用于生成 Windows 平台上的可执行文件。

总结来说，mingw64 使得在 Windows 上进行原生编译成为可能，不需要依赖于 Windows 的 Visual C++ 工具链。

## gcc 和 g++

gcc 和 g++ 都是 GNU 编译器集合（GNU Compiler Collection，简称 GCC）的一部分，但它们用于编译不同类型的程序。

gcc：最初是 GNU C Compiler 的缩写，它是用于编译 C 语言程序的编译器。随着 GCC 的发展，它现在支持多种编程语言，包括 C、Objective-C、Fortran、Ada 等，因此现在通常被称为 GNU Compiler Collection。对于 C 程序，你会使用 gcc 命令来编译。

g++：是 GCC 的一部分，专门用于编译 C++ 程序。它支持 C++ 语言的所有特性，包括类、继承、模板等。当你编写 C++ 代码时，应该使用 g++ 而不是 gcc，因为 g++ 理解 C++ 的特定语法和特性。

简而言之，gcc 用于编译 C 语言程序，而 g++ 用于编译 C++ 程序。尽管 g++ 可以编译 C 语言代码（因为它兼容 C 的语法），但最好还是使用 gcc 来编译 C 代码，以避免不必要的混淆和潜在的问题。对于 C++ 代码，应该使用 g++，因为它提供了对 C++ 特性的完整支持。

### g++ 命令行操作

1、g++ .\基础-案例-九九乘法表.cpp
    这个命令会经历以下步骤：
    编译：g++ 编译器会将 基础-案例-九九乘法表.cpp 文件中的人类可读的 C++ 代码转换成机器代码。
    链接：编译器还会链接该程序可能依赖的任何库，以生成一个完整的可执行文件。
    生成可执行文件：如果编译和链接过程没有错误，g++ 会生成一个可执行文件（在 Windows 上可能会是 九九乘法表.exe）。
    如果想要指定生成的可执行文件的名称，可以使用 -o 选项: g++ .\九九乘法表.cpp -o 九九乘法表.exe

2、.\基础-案例-九九乘法表.exe   /  .\九九乘法表
    如果编译成功，可以通过在命令行中输入生成的可执行文件的名称来运行程序

3、输出调试：g++ -g .\基础-案例-九九乘法表.cpp -o MyDeBugTest
    和第一步过程一样，但输出的可执行文件带了调试信息，并且指定了名称

### 使用 g++ 编译多文件项目

1、通过 settings.json 配置 Code Runner
    进入 设置 → 工作区 → 搜索 “Code Runner” → 点击 Edit in settings.json，配置如下：
    "cpp": "cd $dir && g++ $fileName -IMulti_Func Multi_Func/Func.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
2、手动编译多文件
    g++ main.cpp Multi_Func/Func.cpp -IMulti_Func -o exe_g++
3. 调试配置
    launch.json：用于配置调试信息，包括编译器选择（C 用 gcc，C++ 用 g++）。
    task.json：在调试前执行，用于生成 .exe 文件。调试多文件时需在其中配置所有相关源码文件路径。
    settings.json: 是VS Code众多配置文件中的一个，可以编辑VS Code的页面风格、代码格式、字体颜色大小等，例如:自动保存、字体、文件编码等，该文件能影响Code Run
    在设置->工作区->搜索 code run–>选择 Code-runner:Executor Map 设置编译参数，点击编辑，会在 .vscode 生成 settings.json
    ⚠️ 注意：使用右上角调试按钮时依赖 launch.json 和 task.json

## Tips

### 基础操作及概念

1、查看文件信息
    使用 ls 命令可以查看当前目录下文件的名称、类型、大小和最后修改时间。
2、文件层级与路径
    编译和调试应在文件的父级目录下执行，不能是祖父级目录。
    运行或调试时，若文件直接位于项目根目录下，可直接使用文件名（如 main.cpp）；若文件位于子目录中，则需指明路径（如 Multi_Func/Func.cpp）。
    使用 cd .. 可返回上一级目录（. 表示当前目录）。
3、删除文件
    使用 rm * 可删除当前目录下的所有文件，例如在路径 D:\A_Project\C++\Code\C++_study> 下执行。
4、VS Code 配置层级
    用户区：适用于该用户打开的所有项目，用于配置通用设置。
    工作区：仅适用于当前打开的目录，可覆盖用户区设置。

### CMake

1、基本概念
    CMake 是跨平台构建工具，通过 CMakeLists.txt 配置文件生成平台相关的 Makefile，无需手动编写。
2、使用步骤
    编写 CMakeLists.txt：指定要编译的源码及输出文件名。
    构建项目：在 build 目录下终端输入执行：cmake ..，生成 Makefile 文件
    编译项目：make，在 build 目录下生成可执行文件（如 main.exe）
    运行程序：main，其中 main 是在 CMakeLists.txt 中定义的可执行文件名称
3、程序内容有修改时，使用 make clean 删除之前的可执行文件，再执行 make 重新编译程序
4、可直接点击 VS Code 底部工具栏的“三角形”运行按钮，自动完成编译与执行

### g++ 与 CMake 的区别

#### **CMake**：构建系统生成器

- 高级抽象工具，管理整个项目的构建过程
- 生成平台特定的构建文件（Makefile、Visual Studio项目等）
- 通过 CMakeLists.txt 配置，使用下方工具栏中的 CMake 工具进行构建和调试
- CMake**本身不编译代码**。CMake生成构建文件（如Makefile），然后使用构建工具（如make）**调用编译器（如g++）来编译代码**
- CMake可以配置**使用不同的编译器**，包括**g++（默认）**、**clang++、MSVC**等

#### **g++**：编译器

- 实际执行编译和链接的工具

- 将C++源代码转换为可执行文件或库

- 调试通过 task.json 和 launch.json 配置，点击右上角调试按钮执行

  **2种程序运行方式**

  g++ .\xxx.cpp ，cmake->make->main

  cmake_minimum_required(VERSION 3.10)
  project(MyCppProject VERSION 1.0)
  
  **设置C++标准**

  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  
  **编译器特定选项**

    **g++ 特定选项**
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-Wall -Wextra -O2)
    **Clang 特定选项**
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        add_compile_options(-Weverything -O2)
    **MSVC 特定选项**
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_compile_options(/W4 /O2)
    endif()
  
  **添加可执行文件**

  add_executable(myapp main.cpp src/utils.cpp)
  
  **添加库依赖**

  target_link_libraries(myapp PRIVATE pthread)

#### 补充技巧

1、按下 F1 可打开命令面板，快速访问各类设置与操作。
2、若未安装 CMake 工具，编译多文件项目需通过修改 settings.json 实现，过程较为繁琐。
3、在 VS Code 中开发 C/C++ 项目时：
    轻量级、文件较少时，可使用 g++ 配合 settings.json 快速编译运行；
    项目较复杂或需跨平台构建时，推荐使用 CMake 进行管理。
