#include <iostream>

using namespace std;

//* 赋值运算符重载的用途：实现深拷贝

class Person
{
private:
    int * pAge;

public:
    Person(int Age)
    {
        pAge = new int (Age);
    }
    ~Person()
    {
        if(pAge == NULL)
            return;
        delete pAge;
        cout << "释放堆区空间" << endl;
    }

    int ReadAge(void)
    {
        return *pAge;
    }

    //* 重载 赋值运算符(实现深拷贝)
    Person & operator=(Person & p)
    {
        // if(pAge != NULL)
        //     delete pAge;
        // pAge = new int(p.ReadAge());
        //...其他非指针变量赋值

        *pAge = p.ReadAge();
        //...其他非指针变量赋值
        return p;//也可以写 *this
    }
};

int main()
{
    Person p1(18);
    cout << "p1的年龄是" << p1.ReadAge() << endl;

    Person p2(20);
    cout << "p2的年龄是" << p2.ReadAge() << endl;

    //! 浅拷贝，只是简单地将所有变量的值进行复制，包括指针变量
    //! 出现问题：拷贝后两个指针变量指向同一块空间，两对象执行析构函数会重复释放同一块空间
    p2 = p1;
    cout << "p1的年龄是" << p1.ReadAge() << endl;
    cout << "p2的年龄是" << p2.ReadAge() << endl;

    Person p3(22);
    p1 = p2 = p3;

    return 0;
}
