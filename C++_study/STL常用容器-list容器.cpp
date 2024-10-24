#include <iostream>
#include <list>

using namespace std;

//! 双向循环链表

// List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的，原因是list是链表，vector是动态数组

void printList(const list<int> &L) 
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) 
		cout << *it << " ";//只指向数据域
	cout << endl;
}

//* 四种构造函数
void test01()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	list<int> L2(L1.begin(),L1.end());
	printList(L2);

	list<int> L3(L2);
	printList(L3);

	list<int> L4(10, 1000);
	printList(L4);
}

//* 赋值
void test02()
{
    cout << "------------赋值------------" << endl;
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	//赋值
	list<int> L2;
	L2 = L1;
	printList(L2);

	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int> L4;
	L4.assign(10, 100);
	printList(L4);

}

//* 交换
void test03()
{
    cout << "------------交换------------" << endl;

	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int> L2;
	L2.assign(10, 100);

	cout << "交换前： " << endl;
	printList(L1);
	printList(L2);
	cout << endl;

	L1.swap(L2);

	cout << "交换后： " << endl;
	printList(L1);
	printList(L2);
}


int main() 
{
	test01();
	test02();
	test03();

	return 0;
}
