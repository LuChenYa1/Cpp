#include <iostream>
using namespace std;

//! 对象的初始化和清理
//* 构造函数和析构函数


//* 创建一个类，如果用户不添加，则编译器会添加三个默认函数（不可见）：无参构造（空函数）、析构函数（空函数）、拷贝构造函数（对象全部属性进行值拷贝）
//* 如果用户定义了有参构造函数，则编译器不再提供默认的无参构造函数，但是会提供拷贝构造函数
//* 如果用户定义了拷贝构造函数，则编译器不再提供其他所有构造函数

class Person
{
private:
    int Age;
    int * pHeight;
public:
    int ReadAge(void)
    {
        return Age;
    }
    int ReadHeight(void)
    {
        return *pHeight;
    }
    //! 1、构造函数 进行初始化的操作
    //* 没有返回值，可以有参数（可以发生函数重载） 
    //* 函数名和类名相同
    //* 创建对象时，会自动调用一次构造函数，且只调用一次

    //* 两种分类
    //* 无参和有参
    //* 普通和拷贝
    Person()
    {
        cout << "Person 无参/普通构造函数！" << endl;
    }
    Person(int a, int Height)
    {
        Age = a;
        pHeight = new int (Height);
        cout << "Person 有参/普通构造函数！" << endl;
    }
    Person(int a)
    {
        Age = a;
        cout << "Person 隐式转换法调用有参构造函数" << endl;
    }

    Person(const Person &p)//拷贝构造函数不允许形参创建新的空间（可能会套娃），所以只能采取引用
    {
        Age = p.Age;
        pHeight = new int(*p.pHeight);
        cout << "Person 拷贝构造函数！" << endl;
    }

    //! 2、析构函数 进行清理的操作
    //* 没有返回值，没有参数
    //* 函数名和类名相同
    //* 销毁对象之前，会自动调用一次析构函数，且只调用一次
    ~Person()
    {
        cout << "Person 析构函数！" << endl;

        //* 析构函数用法：释放在堆区申请的空间
        //! 浅拷贝：若对象成员含有堆区指针，使用默认拷贝函数会使两对象的指针值相同，指向同一块空间，当两个对象先后释放，后释放的对象执行析构函数时，会再次 delete 同一块空间，导致报错
        //* 深拷贝(解决方法))：使用自定义的拷贝构造函数，申请一块专门的空间和原对象的堆区空间区分开
        delete(pHeight);
        pHeight = NULL;
    }
};

void Test_01(void)
{
    //* 1、括号法
    //! 调用无参构造时不要加括号
    Person p1;//* 调用无参构造
    //! Person p1();//* 注意：编译器认为是函数声明，不会创建对象
    Person p2(10, 160);//调用有参构造
    Person p3(p2);//调用拷贝构造
    cout << "p2.Age = " << p2.ReadAge() << endl;
    cout << "p3.Age = " << p3.ReadAge() << endl;

    //* 2、显示法
    Person p4 = Person(20, 160);
    Person p5 = Person(p2);
    cout << "aaa" << endl;
    Person(10, 160);//匿名对象，当前行执行结束后，系统会自动回收该匿名对象
    // Person(p3);//不要利用拷贝构造函数初始化匿名对象且不赋值给有名字的对象，编译器认为 Person(p3) === Person p3，导致重定义错误

    //* 3、隐式转换法
    Person p6 = 30;
    Person p7 = p4;
}

//什么时候会调用构造/析构函数？只要创建了对象，包括形参。
void DoWork_01(Person p)//* 形参创建对象
{
    p.ReadAge();
}

Person DoWork_02(void)//* 返回值创建对象
{
    Person p_in(20, 170);
    cout << &p_in << endl;
    return p_in;
}

void Test_02()
{
    // Person p(10);
    // DoWork_01(p);
    Person p_out = DoWork_02();//注意：这里的对象 p_out 继承了 DoWork_02 函数内部的即将被释放的对象 p_in 的空间，因此不再调用构造和析构函数
    cout << &p_out << endl;
    cout << p_out.ReadHeight() << endl;
}

int main(void)
{
    Test_01();

    Person p(10, 160);
    Person p2(p);
    cout << p2.ReadHeight() << endl;

    return 0;
}
