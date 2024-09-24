#include <iostream>

using namespace std;

//! 四区：代码区、全局区、栈区、堆区
//!全局区：全局变量、静态变量、常量
//! 常量：const 修饰的全局变量，字符串常量

int g_a = 10;
static int g_b = 20;

int * Fun(void);

int main(int argc, const char** argv)
{
    int a = 10;
    static int b = 20;
    const int c = 10;

    cout << "局部变量地址：" << &a << endl;
    cout << "局部常量地址：" << &c << endl;
    cout << "静态局部变量地址：" << &b << endl;
    cout << "静态全局变量地址：" << &g_b << endl;
    cout << "字符串常量地址：" << &"Hello World" << endl;
    cout << "全局变量地址：" << &g_a << endl;

    // int * p = Fun();
    // cout << *p <<endl;
    // cout << *p <<endl;
    //结论，栈区空间（函数内的局部变量和形参）出了函数立刻会被释放，VSstudio编译器会保留数据直到第一次指针指向该数据，再次指向就会报错（野指针）
    return 0;
}

int * Fun(void)
{
    int a = 10;//出了这个函数，a的空间就会被释放
    return &a;//返回的地址变成野指针
}
