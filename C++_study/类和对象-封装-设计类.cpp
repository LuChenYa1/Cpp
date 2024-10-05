#include <iostream>

using namespace std;


//! C++面向对象的三大特性：封装、继承、多态
//* 对象都有其属性和行为
//* 具有相同性质的对象，可以抽象为类

//! 类中的属性和行为，统一称为成员
//* 属性  成员属性 成员变量
//* 行为  成员方法 成员函数

//! 由类实例化一个对象，若该对象是空对象，则占一个字节
//* 所有静态成员通通存储在全局区，直属于类
//* 非静态成员中，只有成员变量存储在对象空间里

class Person
{
    //* 测试空对象占字节大小：1个
};
class Person1//* 该对象占四个字节
{
    int a;
    void Func(void)
    {
        //! 成员函数不占对象空间
    }
};

const double PI = 3.14;

class Circle
{
    //* 访问权限
    //公共权限
    public:
    //* 属性
    //* 半径
    int Radius;
    //* 行为
    double GetPerimeter()
    {
        return 2 * PI * Radius;
    }
};

class Student
{
    //公共权限
    public:
    //属性
    string Name;
    int ID;
    //行为
    //显示姓名和学号
    void ShowStudent()
    {
        cout << "姓名: " << Name << "  学号:" << ID << endl;
    }
    //* 给姓名赋值
    void SetName(string S_Name)
    {
        Name = S_Name;
    }
    //* 给学号赋值
    void SetID(int S_ID)
    {
        ID = S_ID;
    }
};

int main(void)
{
    Person1 p;
    cout << "Person p 占" << sizeof(p) << "个字节" << endl;

    //* 通过类，创建具体的对象
    //* 实例化 
    Circle C1;
    //* 给对象的属性赋值
    C1.Radius = 10;
    //* 对象行为：获取它的周长
    cout << "圆的半径是" << C1.GetPerimeter() << endl;

    Student S1;
    // S1.Name = "张三";
    S1.SetName("张三");
    // S1.ID = 1;
    S1.SetID(1);
    S1.ShowStudent();
    Student S2;
    S2.Name = "李四";
    S2.ID = 2;
    S2.ShowStudent();

    return 0;
}
