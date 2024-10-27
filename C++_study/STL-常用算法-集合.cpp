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

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个里面较小的值给目标容器开辟空间
	vTarget.resize(min(v1.size(), v2.size()));

    //* 1、求两个容器的交集
    //* 两个容器的元素必须是有序序列
	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

    //* 2、求并集
	//取两个容器的和给目标容器开辟空间
    //* 两个容器的元素必须是有序序列
	//返回目标容器的最后一个元素的迭代器地址
	vTarget.resize(v1.size() + v2.size());

    itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

    //* 3、求差集：容器1相对于容器2所独有的元素
    //* 两个容器的元素必须是有序序列
	//返回目标容器的最后一个元素的迭代器地址

    //取两个里面较大的值给目标容器开辟空间
	vTarget.resize(max(v1.size() , v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	cout << "v1与v2的差集为： " << endl;
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;

	cout << "v2与v1的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main() 
{
	test01();

	return 0;
}
