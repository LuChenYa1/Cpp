// #pragma once 
//#pragma once 是一种编译器指令，用于告诉编译器这个文件只应该被包含一次，以避免重复包含。这个指令通常放在头文件的最开始位置，而不是源文件（.cpp 文件）中。
//! warning: #pragma once in main file" 表示在头文件中使用了 #pragma once 指令，但编译器认为它出现在了一个主文件（通常是 .cpp 文件）中。这通常是一个无害的警告，提示开发者可能在源文件中而不是头文件中使用了 #pragma once。

#include <iostream>
using namespace std;
#include <string>

//! 问题：
//! 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

//* 解决方式1：主文件直接包含.cpp源文件
//* 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称
//* 总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp

template<class T1, class T2>
class Person 
{
public:
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};

//构造函数 类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) 
{
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() 
{
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}
