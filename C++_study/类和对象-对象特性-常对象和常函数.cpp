#include <iostream>
using namespace std;


class Person
{
// private:
public:
    int Age;
    mutable int Height;//* 该关键字使得成员变量可在常对象和常函数内被修改

public:
    //! 常函数：不能修改成员属性
    //* 原理：在成员函数声明后面加 const，修饰的是 this 指向，等价于指针常量 this 前面加 const 即 const Person * const this
    //* 于是，this 指针本身和其指向的对象的值都不可以修改（this指针一般隐藏不写）
    void ShowPerson() const
    {
        // Age = 200;
        // this->Age = 100;
        // this = NULL;
        Height = 157;
    }
};

int main()
{
    Person p1;
    const Person p2 = p1;
    //! 常对象只能调用常函数，即使普通函数没有修改成员属性，也不能被调用
    p2.ShowPerson();
    //* 常对象的成员均不可被修改，除了mutable 修饰的特殊变量，原理同常函数
    // p2.Age = 300;
    p2.Height = 165;
    return 0;
}
