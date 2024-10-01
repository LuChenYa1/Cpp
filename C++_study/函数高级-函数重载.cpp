#include <iostream>

using namespace std;

//! 函数重载的条件：
//! 1、函数名字相同
//! 2、函数作用域相同
//! 3、形参的个数不同 / 类型不同 / 类型的顺序不同
//! 4、无法重载仅按返回值类型区分的函数
//! 技巧，必须保证：进行函数调用时，编译器能明确知道调用的是哪个函数，不发生混淆

// void Func(void)
// {
//     cout << "这是Func" << endl;
// }

// //* void Func(int a = 10) 当其被调用使用默认值时，例 Func(); ，和void Func(void) 的调用发生混淆，即出现二义性
// void Func(int a)
// {
//     cout << "这是Func(int a)" << endl;
// }

// void Func(double a)
// {
//     cout << "这是Func(double a)" << endl;
// }

// void Func(double a, int b)
// {
//     cout << "这是Func(double a, int b)" << endl;
// }

// void Func(int a, double b)
// {
//     cout << "这是Func(int a, double b)" << endl;
// }

//* 无法重载仅按返回值类型区分的函数
// int Func(int a, double b)
// {
//     cout << "这是Func(int a, double b)" << endl;
// }

//* 引用作为重载条件时，const 和不加 const 可同时重载函数
void Func(int &a)//只接受变量名
{
    cout << "这是Func(int a)" << endl;
}

void Func(const int &a)//* const int &a 变量名和常量都能接收，但当另外存在不加 const 的形参 int &a 的重载函数时，只接收常量（为区分俩函数）
{
    cout << "这是Func(const int a)" << endl;
}

int main(void)
{
    // Func(1.23,1);
    // Func();

    int a = 10;
    int &b = a;
    const int &c = 10;
    const int &d = a;//* 使用原名a作为名字时可以修改值，使用引用b作为名字时为常量，不可修改
    a = 20;
    b = 30;
    // c = 40;

    Func(a);
    Func(10);

    return 0;
}
