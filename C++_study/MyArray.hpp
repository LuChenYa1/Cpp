#pragma once
#include <iostream>
using namespace std;

//* 案例描述:  实现一个通用的数组类，要求如下：

// * 可以对内置数据类型以及自定义数据类型的数据进行存储`
// * 将数组中的数据存储到堆区
// * 构造函数中可以传入数组的容量
// * 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// * 可以对数组中的数据进行增加和删除
// * 可以通过下标的方式访问数组中的元素
// * 可以获取数组中当前元素个数和数组的容量

template<typename T>
class MyArray
{
public:
    
	//有参构造函数
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray & arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			//如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值
            //编译器不支持一个对象赋值给另外一个对象的写法，只能重载运算符'='
			// 注意：pAddress[i]如果是普通类型就可以直接= 但如果是指针类型则需要深拷贝，不能直接赋值导致指向同一块空间
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载 = 操作符  防止浅拷贝问题
	MyArray& operator=(const MyArray& myarray) 
    {
		if (this->pAddress != NULL) 
        {
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) 
			this->pAddress[i] = myarray[i];
		return *this;
	}

	//重载[] 操作符  arr[0]
	T& operator [](int index)
	{
		return this->pAddress[index]; //不考虑越界，用户自己去处理
	}

	//尾增加
	void Push_Back(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删除
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取数组实际数量
	int	getSize()
	{
		return this->m_Size;
	}

	//析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
            //下面的可写可不写
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T * pAddress;  //指向一个堆空间，这个空间存储真正的数据-数组
	int m_Capacity; //容量
	int m_Size;   // 实际数量
};
