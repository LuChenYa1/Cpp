#include <iostream>

using namespace std;

//* 函数模板作用：
//* 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个**虚拟的类型**来代表。
//* 使用函数模板有两种方式：自动类型推导、显示指定类型
//* 调用模板函数时 T 必须有确定且唯一的数据类型
//* 调用时如果使用显示指定类型的方式，则可以发生隐式类型转换，即当 Func<int>('c')时，'c'会自动转换为99
//* 模板的目的是为了提高复用性，将类型参数化

//语法：template<typename T> // typename 可用class替代，但容易与类混淆
//函数声明或定义

//交换的函数模板
template<typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T> // 也可以替换成typename
//利用选择排序，进行对数组从大到小的排序
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //如果最大数的下标不是i，交换两者
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void printArray(T arr[], int len) 
{
	for (int i = 0; i < len; i++) 
		cout << arr[i] << " ";
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}

void test02()
{
	//测试int数组
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}

int main()
{
    test01();

    test02();

    return 0;
}
