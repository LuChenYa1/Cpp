#include <iostream>

using namespace std;

//! 继承基本语法：class 子类名 ：继承方式 父类名
//* 父类-子类
//* 基类-派生类

//! 父类的私有成员，子类以任何方式继承都无法访问
//! 公共权限优先级最低，私有权限优先级最高
//* 例：子类以公共权限继承父类，则成员全部保持原来的属性（私有成员被继承后不可访问，不属于任何权限）
//* 子类以保护权限继承父类，则父类公共成员变成子类保护成员，父类保护成员权限不变
//* 子类以私有权限继承父类，则父类的公共成员和保护成员都变为私有成员

//定义一个基类 
class Base
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Derived_1 : public Base
{
public:
    void Func(void)
    {
        //* 子类无法访问父类私有权限成员
        // c = 30;
        a = 10;//公共
        b = 20;//保护
    }
};

class Derived_2 : protected Base
{
public:
    void Func(void)
    {
        //* 子类无法访问父类私有权限成员
        // c = 30;
        a = 10;//保护
        b = 20;//保护
    }
};

class Derived_3 : private Base
{
public:
    void Func(void)
    {
        //* 子类无法访问父类私有权限成员
        // c = 30;
        a = 10;//私有
        b = 20;//私有
    }
};

class Derived_4 : private Derived_3
{
public:
    void Func(void)
    {
        //* 全部私有
        // c = 30;
        // a = 10;
        // b = 20;
    }
};

int main()
{
    Derived_1 d1;
    d1.a = 20;

    Derived_2 d2;
    //d2.a = 30;

    Derived_3 d3;
    // d3.a = 40;

    return 0;
}
