#include <iostream>
#include <string.h>

using namespace std;

//* 与函数模板的区别：类模板在模板参数列表中可以有默认参数，函数模板不行
//* 类模板中成员函数和普通类中成员函数创建时机是有区别的：
//* 普通类中的成员函数一开始就可以创建
//* 类模板中的成员函数在调用时才创建
//* 通过类模板创建的对象，可以有三种方式向函数中进行传参,使用比较广泛的是直接指定传入的所有类型

//* 类模板
template<typename NameType, typename AgeType = int> 
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

//* 参数模板化
template <typename T1, typename T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();                   
}

int main() 
{
    //C17标准以上，类模板可以使用自动类型推导
	Person p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
	p.showPerson();

    Person <string, int >p2("沙悟净", 90);
	printPerson2(p2);

	return 0;
}
