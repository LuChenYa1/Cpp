#include <iostream>

using namespace std;

//! 非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码（函数实例）
//* 类的所有非静态成员函数随类诞生，和有无对象无关，就算一个对象也没有，这些函数依旧存在
//* 构造函数也属于非静态成员函数

//! this指针隐藏在每一个非静态成员函数内，哪个对象调用其所属的成员函数，该指针就指向该对象,调用成员属性时也会用到 this 指针
//! Person * const this
//* this 指针本质和引用一样是指针常量，不可被人为修改
//* 用途：
//* 1、 当形参和函数成员变量同名时，用this指针作为区分
//* 2、在类的非静态成员函数中返回对象本身，可使用 return * this;

class Person
{
private:
    int Age;

public:
    Person(int Age)
    {
        //* 每次调用成员属性时，Age === this->Age
        this-> Age = Age;//* 1
    }

    int ReadAge(void)
    {
        return Age;
    }

    Person AddAge(Person &p)
    {
        this->Age += p.ReadAge();
        return *this;//* 2  注意：只要是返回值，都只能保证返回的值是对的，但装着值的空间不是原来的空间，而是新创建的空间
    }
    Person & AddAge_1(Person &p)//* 2 的解决方法：将想要的从返回的空间变成返回值，即返回类型变成引用， 加&
    {
        this->Age += p.ReadAge();
        return *this;//*
    }
};

int main(void)
{
    Person p = 10;
    Person p1 = 10;
    cout << p.ReadAge() << endl;
    cout << p.AddAge(p).ReadAge() << endl;
    //! 链式编程
    p1.AddAge(p).AddAge(p).AddAge(p).AddAge(p);//! 执行一次后返回的对象是新的对象，不是原对象p1，所以Age只加了一次值，结果是30不是90
    cout << p1.ReadAge() << endl;
    p1.AddAge_1(p).AddAge_1(p).AddAge_1(p);//30 + 20 + 20 + 20
    cout << p1.ReadAge() << endl;

    return 0;
}
