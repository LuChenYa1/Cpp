#include <iostream>
#include "myArray.hpp"
#include <string>

using namespace std;

void printIntArray(MyArray<int>& arr) 
{
	for (int i = 0; i < arr.getSize(); i++) 
		cout << arr[i] << " ";//这里使用了[]重载，增加了可读性
	cout << endl;
}

//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
		array1.Push_Back(i);
	
	cout << "array1打印输出：" << endl;
	printIntArray(array1);
	cout << "array1的大小：" << array1.getSize() << endl;
	cout << "array1的容量：" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_Back();
	cout << "array2打印输出：" << endl;
	printIntArray(array2);
	cout << "array2的大小：" << array2.getSize() << endl;
	cout << "array2的容量：" << array2.getCapacity() << endl;
}

//测试自定义数据类型
class Person 
{
public:
    //* 涉及三种默认构造函数的应用
    //* 用户写了有参构造，则默认无参构造消失，拷贝构造仍存在
    //* 所以这个类的对象可以使用 p1 = p2 直接拷贝式赋值（不是初始化也可以用这个拷贝构造，详情看下方代码）
    //* 注意不能有指针，否则会发生浅拷贝
	Person() {} 
    Person(string name, int age) 
    {
        this->m_Name = name;
        this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) 
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
}

void test02()
{
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;
}

int main() 
{
	test01();

	test02();

	return 0;
}
