#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//* 返回bool类型的仿函数称为谓词
//* 如果operator()接受一个参数，那么叫做一元谓词
//* 如果operator()接受两个参数，那么叫做二元谓词

//* 一元谓词（一般用于指定遍历规则）
struct BiggerThanFive
{
    bool operator()(int Val)
    {
        return Val > 5;
    }
};

//* 二元谓词（一般用于指定比较规则）
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
    //* 自定义寻找要求
    vector<int>::iterator it = find_if(v.begin(), v.end(), BiggerThanFive());//返回第一个符合要求的值的地址
    if(it == v.end())
        cout << "没找到！" << endl;
    else
        cout << "找到了：" << *it << endl; 
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	//* 使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
    test01();
    test02();

    return 0;
}
