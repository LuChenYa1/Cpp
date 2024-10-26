#include <iostream>
#include <functional>//模板类，成员函数重载小括号
#include <algorithm>

using namespace std;

//* negate是一元运算，其他都是二元运算
// minus         减法
// multiplies    乘法
// divides       除法
// modulus       取余

//* 全是二元谓词，可以用于写入算法比较规则
// equal         等于
// not_equal     不等
// greater       大于
// greater_equal 大于等于
// less          小于
// less_equal    小于等于

//* 逻辑仿函数
// logical_and  逻辑与
// logical_or  逻辑或
// logical_not  逻辑非

//* negate（取反）
void test01()
{
	negate<int> n;
	cout << n(50) << endl;
}

//* plus（求和）
void test02()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}

//* modulus（取余）
void test03()
{
	modulus<int> m;
	cout << m(23, 20) << endl;//23除20余3
}

void test04()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
		cout << *it << " ";
	cout << endl;

	//自己实现仿函数
	//sort(v.begin(), v.end(), MyCompare());
	//STL内建仿函数  大于仿函数
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
		cout << *it << " ";
	cout << endl;
}

void test05()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();

	return 0;
}
