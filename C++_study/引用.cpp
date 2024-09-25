#include <iostream>

using namespace std;

void Swap(int &a, int &b);
// int & ReDef(void);//! 不要返回局部变量的引用
int & Left(void);


//! 引用的本质是指针常量，新名字表面用法是变量，实际内部是指针操作

int main(void)
{
    int a = 10;
    int &b = a;//! 给变量起别名
    b = 22;//内部发现b是引用，自动转换为 *b = 22;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //! 注意事项
    //!int &c;  引用必须初始化
    //! 引用初始化后，不可再改变,也没有方法可以更改
    int d = 20;
    b = d;//这是赋值操作，不是更改引用
    //&b = d;//&b 是变量地址，是常量，无法实现引用更改

    //! 引用的应用，作为形参，实现址传递
    int i = 10, j = 20;
    Swap(i, j);
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    // int &e = ReDef();//不合法，给空间已经被释放的局部变量重命名，使用时指向非法空间
    // cout << "e = " << e << endl;

    //! 引用作为返回值时，返回的是变量本身而不是变量的值
    int &e = Left();//给静态变量空间起个主函数认识的名字
    Left() = 1111;//引用作为左值
    cout << "e = " << e << endl;

    //! 引用本身需要一个合法的内存空间
    //int &name = 10;
    //! 解决方案：加const, 优点是能给常量重命名，缺点是不可修改
    const int & name = 10;//int temp = 10; const int & name = temp;
    //name = 20;
    cout << "name = " << name << endl;

    return 0;
}

//引用做函数参数
void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//做右值
// int & ReDef(void)//! 不要返回局部变量（除了静态变量）的引用,会报错
// {
//     int a = 10;
//     return a;
// }

//做左值
int & Left(void)
{
    static int v = 11;//静态变量，在全局区
    return v;
}
