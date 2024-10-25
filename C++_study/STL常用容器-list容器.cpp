#include <iostream>
#include <list>

using namespace std;

//! 双向循环链表
//! 不能通过下标访问节点，at()和[]都不能用

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

//* 数量操作
void test04()
{
    cout << "------------数量操作------------" << endl;

	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
		cout << "L1为空" << endl;
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10, 1);//少了不指定就用0补
	printList(L1);

	L1.resize(2);
	printList(L1);
}

//* 插入和删除
void test05()
{
    cout << "------------插入和删除------------" << endl;

	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);

	//移除
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);//移出所有符合要求的节点
	printList(L);
    
    //清空
	L.clear();
	printList(L);
}

//! 数据存取：链表不是数组，不能通过下标访问节点
void test06()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	
	// cout << L1.at(0) << endl;//错误 不支持at访问数据
	// cout << L1[0] << endl; //错误  不支持[]方式访问数据
	cout << "第一个元素为： " << L1.front() << endl;
	cout << "最后一个元素为： " << L1.back() << endl;

	//* list容器的迭代器是双向迭代器，不支持随机访问
	//* list 的迭代器只能进行顺序的增加或减少，不支持直接跳转到某个位置
	list<int>::iterator it = L1.begin();
	// it = it + 2;//错误，不可以跳转访问，即使是+1
	it ++;
}

bool myCompare(int val1 , int val2)
{
	return val1 > val2;
}

//反转和排序
void test06()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//反转容器的元素
	L.reverse();
	printList(L);

	//排序
	L.sort(); //默认的排序规则 从小到大
	printList(L);

	L.sort(myCompare); //* 指定规则，从大到小
	printList(L);
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();

	return 0;
}
