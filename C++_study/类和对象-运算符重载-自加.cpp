#include <iostream>

using namespace std;

//! 使用成员函数重载前置和后置++，前置++的重载函数形参只能是void，后置++的重载函数形参只能是int
//* 前置++ 特点是自加后的值参与当前运算，所以自加操作结束后返回的是被自加的这个变量空间，故返回类型是类名的引用
//* 后置++ 特点是自加前的值参与当前运算，所以自加操作结束后返回的只能是临时创建的用于存储自加前的值的变量空间，返回类型是类名

//* 定义一种新的数据类型，类型名叫MyInterger
class MyInterger
{
    friend ostream & operator<<(ostream & cout, MyInterger IntNumber);
    // friend MyInterger & operator++(MyInterger & IntNumber);
    // friend MyInterger operator++(MyInterger & IntNumber, int);

private:
    int Num;
public:
    MyInterger()
    {
        Num = 0;
    }

    // //* 前置++
    MyInterger & operator++(void)
    {
        Num ++;
        return *this;
    }

    // //* 后置++
    MyInterger operator++(int)
    {
        MyInterger Temp = *this;
        Num ++;
        return Temp;//返回新空间，装着自加前的值
    }
};

//重载 << 运算符
ostream & operator<<(ostream & cout, MyInterger IntNumber)
{
    cout << IntNumber.Num;
    return cout;
}

//* 前置++ 重载（全局函数）
//一定要返回引用，否则返回的是装着值的新空间，不是原来的变量空间
// MyInterger & operator++(MyInterger & IntNumber)
// {
//     IntNumber.Num ++;
//     return IntNumber;
// }

//* 无法使用全局函数实现后置 ++ 重载
// MyInterger operator++(MyInterger & IntNumber, int)
// {
//     MyInterger Temp = IntNumber;
//     IntNumber.Num ++;
//     return Temp;//返回新空间，装着自加前的值
// }


int main()
{
    MyInterger IntNumber;
    cout << IntNumber << endl;

    //* 测试前置++
    ++ (++ IntNumber); 
    cout << ++IntNumber << endl;

    // IntNumber.operator++();//无参数，前置++

    //* 测试后置++
    (IntNumber ++)++; 
    cout << IntNumber++ << endl;

    return 0;
}
