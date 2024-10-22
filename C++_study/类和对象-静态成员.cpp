#include <iostream>

using namespace std;

//* 静态成员本质上属于类，不属于某一个具体的对象
//* 所有类的对象共享同一份静态空间
//* 静态成员属于全局区，在编译阶段分配内存
//* 静态成员和普通成员一样具有访问权限，私有属性的静态成员类外不可直接访问

class Person
{
public:
    static int A;//TODO   类内声明，类外初始化
    int C;
    static void Func()
    {
        A = 111;
        //! 静态成员函数不能引用非静态成员
        //* 原因：静态成员函数属于类，不属于某个对象，因此调用函数时，无法区分非静态成员具体属于哪个对象
        // C = 222;
        cout << "静态成员函数调用" << endl;
    }
private:
    static int B;
};
int Person::A = 10;
int Person::B = 20;

int main()
{
    //* 通过类名访问
    Person::Func();
    cout << Person::A << endl;

    //* 通过对象访问
    Person p;
    p.A = 100;
    cout << p.A << endl;
    p.Func();
    cout << p.A << endl;

    // cout << p.B << endl;

    return 0;
}
