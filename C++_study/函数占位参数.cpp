#include <iostream>

using namespace std;

//! 目前阶段用不到占位参数
//! 占位参数也可以有默认值
//! 调用函数时，必须给占位参数写值（如果没有默认值）

//! 经测试，仅有两个整形形参且其中一个是占位参数时，产生重定义错误
void Func(int a, int)
// void Func(int a, double b, double)
{
    cout << "This is func" << endl;
}

int main(void)
{
    // Func(10, 1, 2.34);
    Func(10, 2);
    return 0;
}
