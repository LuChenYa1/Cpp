#include <iostream>

using namespace std;

//* 只要同名，就加作用域

//! 子类和父类成员名字可以相同，但需要在成员名字前加上作用域来调用父类同名成员
//! 注意:不同名时子类或其对象可以直接调用父类成员（特殊权限除外）
//* 父类之间同名也加作用域区分
//* 即使存在函数重载，即子类和父类同名成员参数类型不一样，还是需要加作用域才能调用父类同名成员

//* 静态成员和非静态成员子父同名时访问方式基本一样，但静态成员可以直接通过类访问

class Father
{
public:
    Father()
    {
        a = 100;
    }
    void Func(void)
    {
        cout << "调用父类成员函数（无参）" << endl;
        a = 333;
        Father::a = 444;
    }
    void Func(int a)
    {
        cout << "调用父类成员函数（有参）" << endl;
        a = 333;
        Father::a = 444;
    }
    static void Func(int a, int b)
    {
        cout << "调用父类静态成员函数（有参）" << endl;
    }
    int a;
    int Father_Num;
    static int Num;
};

class Son : public Father
{
public:
    Son()
    {
        a = 200;
        b = 300;
    }
    void Func(void)
    {
        cout << "调用子类成员函数" << endl;
        a = 111;
        Father::a = 222;
    }
    static void Func(int a, int b)
    {
        cout << "调用子类静态成员函数（有参）" << endl;
    }
    int a;
    int b;
    static int Num;
};

int main()
{
    Son son1;

    son1.Func();
    cout << "父类的成员a:" << son1.Father::a << endl;
    cout << "子类的成员a:" << son1.a << endl;

    son1.Father::Func();
    cout << "父类的成员a:" << son1.Father::a << endl;
    cout << "子类的成员a:" << son1.a << endl;

    son1.Father::Func(2);

    //* 不同名时调用父类成员不需要加作用域
    son1.Father_Num = 12;

    //! 以下对静态同名成员的调用语法没有问题，但编译器报错显示未定义：“Son::Num”、“Father::Num”
    // cout << "通过对象访问父类的静态成员变量Num:" << son1.Father::Num << endl;
    // cout << "通过类名访问父类的静态成员变量Num:" << Son::Father::Num << endl;
    // cout << "通过类名访问子类的静态成员变量Num:" << Son::Num << endl; 
    // cout << "通过对象访问子类的静态成员变量Num:" << son1.Num << endl;

    // //* 通过类名访问父类的静态成员函数
    // Son::Father::Func(10, 20);
    // //* 通过类名访问子类的静态成员函数
    // Son::Func(20, 30);
}
