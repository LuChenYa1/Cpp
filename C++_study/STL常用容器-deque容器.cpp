#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


//! deque没有容量的概念
//* deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//* 中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) 
		cout << *it << " ";
	cout << endl;
}

//* deque构造
void test01() 
{
	cout << "----------构造函数----------" << endl;
	deque<int> d1; //无参构造函数
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);
     
	deque<int> d3(10,100);
	printDeque(d3);

	deque<int> d4 = d3;
	printDeque(d4);
}

//* 赋值操作
void test02()
{
	cout << "----------赋值操作----------" << endl;
	deque<int> d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);

	deque<int> d2;
	d2 = d1;
	printDeque(d2);

	deque<int> d3;
	d3.assign(d1.begin(), d1.end());//全部重新赋值，不是追加
	printDeque(d3);

	deque<int> d4;
	d4.assign(10, 100);
	printDeque(d4);
}

//* 大小操作
void test03()
{
	cout << "----------大小操作----------" << endl;
	deque<int> d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);

	//判断容器是否为空
	if (d1.empty()) 
		cout << "d1为空!" << endl;
	else 
	{
		cout << "d1不为空!" << endl;
		//统计大小
		cout << "d1的元素个数为：" << d1.size() << endl;
	}

	//重新指定大小
	d1.resize(15, 1);//15个元素，原来的元素不够就用1补充，超过就舍弃
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

//* 两端增加和删除
void test04()
{
	cout << "----------双端增加和删除----------" << endl;
	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);

	printDeque(d);

	//尾删
	d.pop_back();
	//头删
	d.pop_front();

	printDeque(d);
}

//* 指定位置插入
void test05()
{
	cout << "----------指定位置插入----------" << endl;

	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.insert(d.begin(), 1000);//返回新数据的位置
	printDeque(d);

	d.insert(d.begin(), 2,10000);//没有返回值
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());//没有返回值
	printDeque(d);
}

//* 指定位置删除
void test06()
{
	cout << "----------指定位置删除----------" << endl;
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.erase(d.begin());//返回下一个数据的位置
	printDeque(d);

	d.erase(d.begin(), d.end());//返回下一个数据的位置
	// d.clear();
	printDeque(d);
}

//* 数据访问（[]、at()、首尾元素）
void test07()
{
	cout << "----------数据访问（[]、at()、首尾元素）----------" << endl;
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	for (int i = 0; i < d.size(); i++) 
		cout << d[i] << " ";
	cout << endl;

	for (int i = 0; i < d.size(); i++) 
		cout << d.at(i) << " ";
	cout << endl;

	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
}

//* 从小到大排序
void test08()
{
	cout << "----------deque容器应用排序算法----------" << endl;
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	sort(d.begin(), d.end());
	printDeque(d);
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();

	return 0;
}
