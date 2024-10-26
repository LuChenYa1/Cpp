#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>
using namespace std;


void myPrint(int val)
{
	cout << val << " ";
}

//* 1、排序
void test01() 
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//* sort默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//* 指定规则：从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

//* random_shuffle洗牌算法使用时要加随机数种子（没加也可以运行）
//* 2、洗牌，随机排序
void test02()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for(int i = 0 ; i < 10;i++)
		v.push_back(i);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

//* 3、有序合并两个容器的元素，存储到第三个容器中
//* 注意: 两个容器必须是有序的
// 打印结果：0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10 ; i++) 
    {
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int> vtarget;
	//* 目标容器需要提前开辟空间
	vtarget.resize(v1.size() + v2.size());
	//合并  需要两个有序序列
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint);
	cout << endl;
}

//* 4、反转区间内元素
void test04()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "反转后： " << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main() 
{
	test01();
	test02();
	test03();
	test04();

	return 0;
}
