#include <iostream>

using namespace std;

//! 如果函数声明已经有默认参数，则函数定义不能出现默认参数
//* 补充：函数声明和定义中，对于同一个形参，只能有其中一个有默认参数
int Func(int a, int b, int c = 30);

//! 如果某个位置已经有了默认值，则往后位置都要有默认值
int Func(int a, int b = 20, int c)
{
    return a + b + c;
}

int main(void)
{
    int Sum = Func(10, 30, 20);
    cout << "Sum = " << Sum << endl;
    Sum = Func(1);
    cout << "Sum = " << Sum << endl;

    return 0;
}
