#include <iostream>
#include <algorithm>
#include <numeric> //体积很小，只包括几个在序列上面进行简单数学运算的模板函数
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

//* 1、对容器内的元素的值进行求和
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) 
		v.push_back(i);

	int total = accumulate(v.begin(), v.end(), 0);

	cout << "total = " << total << endl;
}

//* 2、填充
void test02()
{
	vector<int> v;
	v.resize(10);
	//填充
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main()
{
    test01();
    test02();

    return 0;
}
