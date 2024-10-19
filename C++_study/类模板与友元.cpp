#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2> class Person;

//* 总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别
//如果声明了函数模板，可以将实现写到类的实现后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

//* 1、全局函数配合友元  类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> & p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
    //* 1、全局函数配合友元  类外实现
	friend void printPerson2<>(Person<T1, T2> & p);

	//* 2、全局函数配合友元  类内实现
	friend void printPerson(Person<T1, T2> & p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

//* 1、全局函数在类内实现
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}

//* 2、全局函数在类外实现
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}

int main() 
{
	test01();

	test02();

	return 0;
}
