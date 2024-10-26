#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//* 1、拷贝
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) 
		v1.push_back(i + 1);
        
	vector<int> v2;
    //v2 = v1;
	v2.resize(v1.size());//* 需要提前开辟空间
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

//自定义条件
class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 50;
	}
};

//* 2、替换
void test02()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//将容器中的20 替换成 2000
	cout << "按值替换后：" << endl;
	replace(v.begin(), v.end(), 20, 2000);//* 替换所有符合要求的元素
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	cout << "按要求替换后：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//* 3、交换（两容器）
//* 注意：交换的容器要同种类型
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) 
    {
		v1.push_back(i);
		v2.push_back(i+100);
	}

	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}


int main() 
{
	test01();
	test02();
	test03();

	return 0;
}
