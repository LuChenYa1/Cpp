#include <iostream>
using namespace std;

//* 对象的初始化和清理
//* 构造函数和析构函数
class Person
{
public:
    //! 1、构造函数 进行初始化的操作
    //* 没有返回值，可以有参数（可以发生函数重载）
    //* 函数名和类名相同
    //* 创建对象时，会自动调用一次构造函数，且只调用一次
    Person(/* args */)
    {
        cout << "Person 构造函数的调用" << endl;
    }
    //! 2、析构函数 进行清理的操作
    //* 没有返回值，没有参数
    //* 函数名和类名相同
    //* 销毁对象之前，会自动调用一次析构函数，且只调用一次
    ~Person()
    {
        cout << "Person 析构函数的调用" << endl;
    }
};

void Test(void)
{
    Person p;
}

int main(void)
{
    Test();

    return 0;
}
