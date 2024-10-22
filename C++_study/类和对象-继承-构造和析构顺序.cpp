#include <iostream>

using namespace std;

//* 子类实例化对象时，第一步是继承父类的所有成员，并执行父类的构造函数，然后回到子类执行自己的构造函数
//* 释放子类对象时，遵守栈的逻辑，先入后出，故先执行子类的析构函数，后执行父类的析构函数

class Father
{
public:
    Father()
    {
        cout << "执行父类构造函数" << endl;
    }
    ~Father()
    {
        cout << "执行父类析构函数" << endl;
    }

    int a;
};

class Son : public Father
{
public:
    Son()
    {
        cout << "执行子类构造函数" << endl;
    }
    ~Son()
    {
        cout << "执行子类析构函数" << endl;
    }
    int a;
    int b;
};

int main()
{
    cout << "子类对象有" << sizeof(Son) << "个字节" << endl;//继承自父类的变量a + 子类本身个性化的变量b

    Son son1;

}
