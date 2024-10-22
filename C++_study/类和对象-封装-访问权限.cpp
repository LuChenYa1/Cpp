#include <iostream>

using namespace std;

//! 访问权限有三种：(默认私有权限)
//* 1. public    公共权限  类内可以访问，类外可以访问
//* 2. protected 保护权限  类内可以访问，类外不可以访问
//* 3. private   私有权限  类内可以访问，类外不可以访问 儿子不可以访问父亲（继承）

//* struct 和 class 很像，但struct 不能有成员方法，且默认公共权限

//! 如何设置读写权限？
//* 1、将属性设置为私有/保护
//* 2、利用行为访问属性，根据需求进行读写

class Test
{
    int a;
};

class Person
{
public:
    string ReadName()
    {
        return Name;
    }
    void SetAge(int S_Age)
    {
        if(S_Age < 0 || S_Age > 150)
        {
            cout << "年龄设置不合理，请重新设置" << endl;
            return;
        }
        Age = S_Age;
    }
    double ReadHeight()
    {
        return Height;
    }
    void SetHeight(double S_Height)
    {
        Height = S_Height;
    }

    //* 使用成员函数判断两对象的身高属性是否相等
    bool isSameHeightByClass(Person C)//也可以引用，不过没必要
    {
        if(Height == C.ReadHeight())
            return true;
        return false;
    }

private:
    string Name;//只读
    int Age;//只写
    double Height;//可读可写
};

//* 使用全局函数判断两对象的身高属性是否相等 
bool isSameHeight(Person C1, Person C2)//也可以引用，不过没必要
{
    if(C1.ReadHeight() == C2.ReadHeight())
        return true;
    return false;
}

int main(void)
{
    //默认私有权限，成员不可访问
    // Test T1;
    // T1.a = 1;

    Person P1;
    cout << "姓名：" <<  P1.ReadName() << endl;
    P1.SetAge(151);
    P1.SetHeight(157);
    cout << "身高：" <<  P1.ReadHeight() << endl;

    Person P2;
    P2.SetHeight(156);
    // bool ret = isSameHeight(P1, P2);
    bool ret = P1.isSameHeightByClass(P2);
    if(ret == true)
        cout << "身高一样" << endl;
    else
        cout << "身高不一样" << endl;
    return 0;
}
