#include <iostream>

using namespace std;

//! 加号运算符重载，只能是两个东西相加，不能是三个、四个。。。

//! 简化写法：Result = A + B;
//* 用省略写法时要避免无法辨别究竟使用的哪个重载函数的情况，所以同一运算符的不同重载函数要做到相加类型不同

class Person
{
public:
    int A;
    int B;
    //* 成员函数重载加号，实现两对象值对应相加
    // Person operator+(Person &p)
    // {
    //     Person Temp;
    //     Temp.A = this->A + p.A;
    //     Temp.B = this->B + p.B;
    //     return Temp;
    // }
};

//* 全局函数重载加号，实现两对象值对应相加
Person operator+(Person & p1, Person & p2)
{
    Person Temp;
    Temp.A = p1.A + p2.A;
    Temp.B = p1.B + p2.B;
    return Temp;
}

//* 全局函数重载加号，实现对象（的成员变量）和变量相加
Person operator+(Person & p1, int a)
{
    Person Temp;
    Temp.A = p1.A + a;
    Temp.B = p1.B + a;
    return Temp;
}

int main()
{
    Person p1;
    p1.A = 10;
    p1.B = 20;

    Person p2;
    p2.A = 10;
    p2.B = 20;

    Person p3;
    p3.A = 100;
    p3.B = 200;

    // Person p4 = p1.operator+(p2);
    Person p4 = p1 + p2;
    cout << "A = " << p4.A << endl;
    cout << "B = " << p4.B << endl;

    // p4 = operator+(p1, p3);
    p4 = p1 + p3;
    cout << "A = " << p4.A << endl;
    cout << "B = " << p4.B << endl;

    p4 = p4 + 3;
    cout << "A = " << p4.A << endl;
    cout << "B = " << p4.B << endl;

    return 0;
}
