#include <iostream>

using namespace std;

//! 目前总结，只要是成员函数，不论是否是静态，都不存储在对象空间，直属于类，类存在则唯一的成员函数（实例化）也存在
//* 成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码（函数实例）
//* 构造函数也属于非静态成员函数



class Person
{
public:
    void ShowClassName(void)
    {
        cout << "这是 person 类" << endl;
    }

    void ShowPersonAge(void)
    {
        if(this == NULL)
            return ;
        cout << "Age = " << Age << endl;//this->Age
    }

private:
    int Age;
};

int main()
{
    Person * p = NULL;
    p->ShowClassName();
    //! 因为成员函数不论有无对象都存在唯一的实例，所以空指针可以访问成员函数
    //* 但是，如果是空指针，则说明没有指向的对象，相对应的非静态成员变量都不存在
    //* 所以，空指针访问的成员函数如果调用了非静态成员变量，就会报错，需要加上 this 指针保证非空调用
    p->ShowPersonAge();

    return 0;
}


