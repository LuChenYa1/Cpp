#include <iostream>

using namespace std;

//* 在类对象A作为类B成员并创建对象b时，一般在类B中使用初始化列表赋值类对象A和其他成员，然后再进入花括号执行剩下内容
//* 故，对象A先入栈（执行构造函数），b后入栈，栈“先进后出”，所以b先出栈（执行析构函数），然后A出栈

class Phone
{
public:
    string Name_Phone;

    Phone()
    {
        cout << "这是Phone默认无参构造函数" << endl;
    }
    Phone(string Str):Name_Phone(Str)
    {
        cout << "这是Phone有参构造函数" << endl;
    }

    ~Phone()
    {
        cout << "这是Phone析构函数" << endl;
    }
};

class Person
{
public:
    int A;
    int B, C;
    Phone ph;

    // Person():A(10),B(20), C(30)
    // {

    // }

    Person(int a, int b, int c, string Str):A(a),B(b), C(c), ph(Str)
    {
        cout << "这是Person有参构造函数" << endl;
        // ph = Str;
        //! 当类对象A作为类B成员时，B的构造函数中应当尽可能使用初始化列表对A进行赋值，不要在花括号内赋值
        //* 原因：在花括号内赋值对象A时，发现A调用了两次构造和析构函数，且调用顺序混乱不清
    }

    ~Person()
    {
        cout << "这是Person析构函数" << endl;
    }
};

void Test_01(void)
{
    // Person p;
    Person p(10, 20, 30, "苹果ProMax");

    cout << "A:" << p.A << endl;
    cout << "B:" << p.B << endl;
    cout << "C:" << p.C << endl;
}

int main(void)
{
    Test_01();
    return 0;
}
