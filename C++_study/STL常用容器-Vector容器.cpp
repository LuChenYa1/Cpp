#include <iostream>
#include <vector>

using namespace std;

//! 单端动态数组，数量可随时扩展，每次增加数据，如果容量不够，都要重新申请一块更大的空间，释放原空间
void printVector(vector<int> &v) 
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
	cout << endl;
}

//  vector 或数组的迭代器属于随机访问迭代器（Random Access Iterator），它们支持所有的指针运算符，包括随机访问和指针算术

//* 四种构造方式
void test01()
{
    cout << "----------测试构造函数----------" << endl;

	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());//将v[begin(), end())区间中的元素拷贝给对象本身
	printVector(v2);

	vector<int> v3(10, 100);//n, elem: 将n个elem拷贝给对象本身
	printVector(v3);
	
	vector<int> v4(v3);//拷贝构造
	printVector(v4);
}

//* 赋值操作
void test02()
{
    cout << "----------测试赋值操作----------" << endl;

	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	vector<int> v2;
	v2 = v1;//重载等号操作符
	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	v3.assign(9, 99);//* 注意：assign是全部重新赋值，不是追加
	printVector(v3);

	vector<int> v4;
	v4.assign(10, 100);//10个100
	printVector(v4);
}

//* 对vector容器的容量和大小操作
void test03()
{
    cout << "----------访问容器的容量和元素个数----------" << endl;

	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	if (v1.empty())
		cout << "v1为空" << endl;
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl; //容器的容量
		cout << "v1的大小 = " << v1.size() << endl;     //容器中元素的个数
	}

    //重新指定容器的长度为num，若容器变长，则以elem值填充新位置，注意只改变元素个数，不改变容量
	//如果容器变短，则末尾超出容器长度的元素被删除
	v1.resize(15,10);//resize(int num, elem);
    cout << "v1的容量 = " << v1.capacity() << endl; //容器的容量
	printVector(v1);

	//resize 重新指定元素个数，若指定的更小，超出部分元素被删除，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
	v1.resize(5);
    cout << "v1的容量 = " << v1.capacity() << endl; //容器的容量
	printVector(v1);
}

//* 插入和删除
void test04()
{
    cout << "----------测试插入和删除----------" << endl;

	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);
    //插入指定数量指定值的元素
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	//清空
	// v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}

//* 除了迭代器，at()成员函数和重载的运算符[]也可以访问容器内元素
void test05()
{
    cout << "----------访问容器内的元素----------" << endl;

	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
		cout << v1.at(i) << " ";
	
	cout << endl;

	cout << "v1的第一个元素为： " << v1.front() << endl;
	cout << "v1的最后一个元素为： " << v1.back() << endl;
}

//* 实现两个容器内元素进行互换
void test06()
{
    cout << "--------互换两容器内元素--------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--)
		v2.push_back(i);
	printVector(v2);

	cout << "互换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

void test07()
{
    cout << "-------使容量和元素个数相同-------" << endl;
	vector<int> v;

	for (int i = 0; i < 100000; i++) 
		v.push_back(i);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//收缩内存,防止内存浪费
	vector<int> (v).swap(v); //匿名对象

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

//* 容器预留len个元素长度，预留位置如果不初始化，元素不可访问
void test08()
{
    cout << "---减少vector在动态扩展容量时的扩展次数---" << endl;
	vector<int> v;

	//预留空间
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) 
    {
		v.push_back(i);
		if (p != &v[0]) 
        {
            //只要重新开辟了空间，动态数组的首元素地址就会变，由此记录整个过程重新开辟空间的次数
			p = &v[0];
			num++;//结果是1次，证明预留空间后，元素个数小于预留空间则不会重新开辟空间
		}
	}
	cout << "num:" << num << endl;
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

