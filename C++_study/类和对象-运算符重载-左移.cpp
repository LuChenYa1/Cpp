#include <iostream>

using namespace std;

//* ostream : 输出流
//* ostream 对象只能有一个，即cout

class Person
{
    friend ostream & operator<< (ostream &cout, Person &p);
public:
    Person()
    {
        A = 10;
        B = 20;
    }
private:
    int A;
    int B;
    //! 成员函数不能重载 <<  
    //* 原因：调用时 p.operator << (cout)（或者p1），简化后为 p << cout（p1），显然不对
};

//* 实现 cout << p ，打印对象p 的所有成员属性
ostream & operator<< (ostream &out, Person &p)//* 注意一定要引用，否则重载的不是 cout 本身, 且cout 只能有一个
{
    out << "A = " << p.A << "," << "B = " << p.B;
    return out;
}

int main()
{
    Person p1;
    
    cout << p1 << endl;//* 链式编程
    cout << "..." << endl;

    return 0;
}
