#include <iostream>

using namespace std;

//* 菱形/钻石继承：羊和驼都是动物的派生类，羊驼是羊和驼共同的派生类
//! 显然羊驼的年龄成员只需要有一个，但普通写法不考虑基类们的基类是否相同，使得年龄成员成为两个同名成员
//! 菱形继承的主要问题是子类继承两份相同的数据，导致资源浪费且毫无意义
//* 解决方法-虚继承：使用virtual 关键字修饰这个发生成员冗余的类的基类们
//* 原理：子类继承父类时会继承到一个指针，指针指向父类的父类，使子类直接继承爷爷类，从而避免重复继承

//* 动物类（虚基类）
class Animal
{
public:
    int Age;
};

//* 羊类
class Sheep : virtual public Animal{};
//* 驼类
class Tuo : virtual public Animal{};

//* 羊驼
class SheepTuo : public Sheep, public Tuo{};

int main()
{
    SheepTuo ST1;
    ST1.Sheep::Age = 20;
    ST1.Tuo::Age = 18;
    cout << "羊驼的羊龄有" << ST1.Sheep::Age << "岁" << endl;
    cout << "羊驼的驼龄有" << ST1.Tuo::Age << "岁" << endl;
    cout << "羊驼的驼龄有" << ST1.Age << "岁" << endl;

    Sheep S1;
    S1.Age = 40;
    cout << "羊的羊龄有" << S1.Age << "岁" << endl;

    return 0;
}
