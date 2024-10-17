#include <iostream>

using namespace std;


class Animal
{
public:
    //! 加关键字virtual 后，类型字节数从空类的1个字节变成8个字节，因为多了一个vfptr 指针
    //* v:virtual f:function ptr:pointer
    //* vfptr 指针指向的空间 vftable 装着dospeak() 的函数体地址，若没有子类重写该函数名，则函数体地址为父类原装的函数体地址
    virtual void doSpeak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    //! 子类重写了父类的 doSpeak函数，
    //! 故子类继承的父类里的 vfptr 指针指向的空间里，装着的函数体地址变为子类的 doSpeak 函数体地址，原值被覆盖
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

void Test(Animal & animal)
{
    //* 当形参为子类对象时，父类的指针或引用指向子类对象，因此还是会进入子类执行函数
    //* 因为 doSpeak 函数是虚函数，因此需要找到 vfptr 指针，子类对象里该指针指向的空间里装着子类重写的函数体地址，因此执行子类的 doSpeak 函数
    animal.doSpeak();
}

int main()
{
    Animal animal;
    Cat cat;
    Dog dog;

    Test(animal);
    Test(cat);
    Test(dog);//狗同理

    cout << "Animal类型有" << sizeof(Animal) << "个字节" << endl;

    return 0;
}
