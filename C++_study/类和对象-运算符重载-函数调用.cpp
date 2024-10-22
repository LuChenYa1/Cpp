#include <iostream>

using namespace std;

//* 重载 () ，使用时像调用函数，故被称为仿函数

class MyPrint
{
public:
    void operator() (string test)
    {
        cout << test << endl;
    }
};

//* 括号重载（仿函数）非常灵活
class MyAdd
{
public:
    int operator() (int A, int B)
    {
        return A + B;
    }
};

void Func(string test)
{
    cout << test << endl;
}

int main()
{
    MyPrint p1;
    p1("这是仿函数调用，实际为括号重载");

    MyAdd Add;
    int Ret = Add(100, 120);
    cout << "Ret = " << Ret << endl;

    Func("这是正常函数调用");

    //! 匿名函数对象:类名 + ()，执行完当前语句立马释放
    cout << MyAdd()(20, 30) << endl;

    return 0;
}
