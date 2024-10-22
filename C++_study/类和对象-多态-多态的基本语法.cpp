#include <iostream>

using namespace std;

//! 多态是C++面向对象的三大特性之一
//* 静态多态：函数重载和运算符重载属于静态多态，复用函数名
//* 动态多态：派生类结合虚函数实现运行时多态

//* 静态多态和动态多态区别：
//* 静态多态在编译阶段确定函数地址，动态多态在运行阶段确定函数地址
//* 原因：静态多态的函数名虽然都一样，但形参类型各不相同，所以本质仍是不同的可以区分的函数；
//* 动态多态的父类和子类中的函数名和形参完全一样，哪个类型的对象调用了这个函数，则执行哪个对象所属类的函数体，因此调用函数时，函数所属的地址随着对象的不同的发生变化，是动态的

//! 动态多态使用条件：
//* 1、有继承关系
//* 2、子类要重写父类的虚函数，函数名字、形参、返回值要完全相同

//* 动态多态如何使用？
//* 父类的指针或引用，传入子类对象

class Animal
{
public:
    virtual void doSpeak()//! 这里一定要加关键词 virtual，否则无法实现函数多态
    //* 函数变成虚函数，使编译器在编译阶段无法确定函数调用的函数体
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    void doSpeak()
    {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal
{
public:
    void doSpeak()
    {
        cout << "小狗在说话" << endl;
    }
};

void Test(Animal & animal)//* 注意这里一定需要引用，传入对象本身和新建一个复制体存在类型区别，当传入对象类型不同时
{
    animal.doSpeak();
}

int main()
{
    Animal animal;
    Cat cat;
    Dog dog;

    Test(animal);
    Test(cat);//* 猫对象调用动物说话函数，使用了虚函数，且猫类存在同名函数，故调用的是猫类自己的说话函数
    Test(dog);//狗同理


    return 0;
}
