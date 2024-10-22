#include <iostream>

using namespace std;

class Person
{
private:
    string Name;
    int Age;
public:
    Person(string Name, int Age)
    {
        this->Name = Name; 
        this->Age = Age;
    }

    //* == 相等关系运算符重载
    bool operator== (Person & p)
    {
        if(this->Name == p.Name && this->Age == p.Age)
            return true;
        else
            return false;
    }
    //* ！= 不等关系运算符重载
    bool operator!= (Person & p)
    {
        if(this->Name != p.Name || this->Age != p.Age)
            return true;
        else
            return false;
    }
};

int main()
{
    Person p1("张三", 20);
    Person p2("李四", 18);
    Person p3("张三", 20);

    if(p1 == p2)
        cout << "俩对象是一样的" << endl;
    else
        cout << "俩对象有区别" << endl;

    if(p1 != p2)
        cout << "俩对象有区别" << endl;
    else
        cout << "俩对象是一样的" << endl;

    return 0;
}
