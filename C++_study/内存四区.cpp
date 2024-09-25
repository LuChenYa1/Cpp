#include <iostream>

using namespace std;

//! 四区：代码区、全局区、栈区、堆区
//!全局区：全局变量、静态变量、常量
//! 常量：const 修饰的全局变量，字符串常量

int g_a = 10;
static int g_b = 20;
  
// int * Fun_1(int b);
double * Fun_2(void);//堆，申请单个变量
double * Fun_3(void);//堆，申请多个变量


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

    // int * p_1 = Fun_1(3);
    // cout << *p_1 <<endl;
    //cout << *p_1 <<endl;
    //结论，栈区空间（函数内的局部变量和形参）出了函数立刻会被释放，VSstudio编译器会保留数据直到第一次指针指向该数据，再次指向就会报错（野指针）
    //! 所以，不要返回局部变量的地址，没有作用还会报错

    double * p_2 = Fun_2();
    cout << "堆区变量的值是：" << *p_2 <<endl;
    delete p_2;//释放堆区空间 
    cout << "堆区变量的值是：" << *p_2 <<endl;//指向非法空间，打印随机值

    Fun_3();

    return 0;
}

// int * Fun_1(int b)//栈
// {
//     b = 20;//形参和局部变量同理
//     int a = 10;//出了这个函数，a的空间就会被释放
//     return &a;//返回的地址变成野指针
// }

double * Fun_2(void)//堆，申请单个变量
{
    double * p = new double(12.3);//new 关键字用于把变量放到堆区，并返回对应类型的地址
    return p;
}

double * Fun_3(void)//堆，申请多个变量
{
    double * p = new double[10];//中括号代表数量，小括号代表数据
    for(int i = 0; i < 10; i++)
        p[i] = i + 100;
    for(int i = 0; i < 10; i++)
        cout << p[i] << endl;
    delete[] p;//要释放数组的话，得加上中括号，否则只释放第一个数据空间
    return p;
}
