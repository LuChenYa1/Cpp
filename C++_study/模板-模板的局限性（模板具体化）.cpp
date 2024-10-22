#include <iostream>
using namespace std;

#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//* 普通函数模板
template<typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T1, typename T2>
void TestSomeTypename(T1 a, T2 b)
{
	cout<< "函数模板可存在多个泛型"<< endl;
}

//* 具体化，显示具体化的原型，以template<>开头
//* 具体化优先于常规模板
template<>  //该句也可不写，不写就是普通函数，不再是函数模板的具体化
bool myCompare(Person &p1, Person &p2)
{
	if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	//* 内置数据类型可以直接使用通用的函数模板
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//* 自定义数据类型，不会调用普通的函数模板
	//* 可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}

int main() 
{

	test01();

	test02();

	TestSomeTypename(12, 3.14);

	return 0;
}
