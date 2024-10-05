#include <iostream>
#include <string>
using namespace std;


//定义一个房子类
class Building
{
    //! 通过关键字 friend 使类外的类或者函数成为友元，从而使这些函数或者类外的类能够访问类的私有属性
    friend void GoodFriend_1(Building * building);
    friend class GoodFriend_2;
    //这里不能定义成员函数为友元，报错：未定义，原因未知。
    // friend void GoodFriend_3::Visit_2(void);//是友元

private:
    string BedRoom;
public:
    string SittingRoom;

    Building()
    {
        BedRoom = "卧室";
        SittingRoom = "客厅";
    }
};

// Tips:类外不能写构造函数，但成员函数和成员变量都可以
// Building::Building()
// {
//     this->BedRoom = "卧室";
//     this->SittingRoom = "客厅";
// }

//! 1、全局函数作友元
void GoodFriend_1(Building * pBuilding)
{
    cout << "好朋友函数甲正在访问" << pBuilding->SittingRoom << endl;//访问类的公有属性
    cout << "好朋友函数甲正在访问" << pBuilding->BedRoom << endl;//访问类的私有属性
}

//! 2、类作友元
class GoodFriend_2
{
private:
    Building * pBuilding;
public:
    void VisitBuilding(void);
    GoodFriend_2()
    {
        pBuilding = new Building;
    }
};

//! 3、成员函数作友元（不可行，原因未知）
class GoodFriend_3
{
private:
    Building * pBuilding;
public:
    void Visit(void)//不是友元，不可以访问目标类的私有成员
    {
        cout << "非友元的成员函数访问" << pBuilding->SittingRoom << endl;
    }
    // void Visit_2(void);//是友元
    void Visit_2(void)
    {
        // cout << "友元成员函数访问" << pBuilding->BedRoom << endl;
        //! 报错：不可访问
    }
    GoodFriend_3()
    {
        pBuilding = new Building;
    }
};

//* Tips:类外写成员函数
void GoodFriend_2::VisitBuilding(void)
{
    cout << "好朋友类乙正在访问" << pBuilding->SittingRoom << endl;//访问类的公有属性
    cout << "好朋友类乙正在访问" << pBuilding->BedRoom << endl;//访问类的私有属性
}

int main()
{
    Building building;

    GoodFriend_1(&building);

    GoodFriend_2 Friend;
    Friend.VisitBuilding();

    GoodFriend_3 Fr3;
    Fr3.Visit();

    return 0;
}
