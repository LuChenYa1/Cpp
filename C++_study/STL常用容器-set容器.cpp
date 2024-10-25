#include <iostream>
#include <set>

using namespace std;

//* 所有元素都会在插入时自动被排序
//* set/multiset属于关联式容器，底层结构是用二叉树实现

//* 增加元素只能用 insert
//! set和multiset区别：
//* set不允许容器中有重复的元素
//* multiset允许容器中有重复的元素

void printSet(set<int> &s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}

//* 构造和赋值
void test01()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//拷贝构造
	set<int> s2(s1);
	printSet(s2);

	//赋值
	set<int> s3;
	s3 = s2;
	printSet(s3);
}

//* 容器元素数量
void test02()
{
	set<int> s1;
	
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty())
		cout << "s1为空" << endl;
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s1.size() << endl;
	}
}

//* 交换两个容器内容
void test03()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << endl;

	cout << "交换后" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

//* 插入和删除
void test04()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//删除
	s1.erase(s1.begin());//删除pos迭代器所指的元素，返回下一个元素的迭代器
	printSet(s1);

	s1.erase(30);//删除容器中值为elem的元素
	printSet(s1);

	//清空
	//s1.erase(s1.begin(), s1.end()); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
	s1.clear();
	printSet(s1);
}

//* 查找和统计（内置函数）
void test05()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(30);
	s1.insert(40);
	
	//查找
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
		cout << "找到了元素 ： " << *pos << endl;
	else
		cout << "未找到元素" << endl;

    printSet(s1);//10 30 40

	//统计
	int num = s1.count(30);//对于set容器，结果为0/1
	cout << "num = " << num << endl;
}

//* set和multiset区别
void test06()
{
	set<int> s;
	pair<set<int>::iterator, bool>  ret = s.insert(10);//返回插入位置和是否插入成功标志位
	if (ret.second) 
		cout << "第一次插入成功!" << endl;
	else 
		cout << "第一次插入失败!" << endl;

	ret = s.insert(10);
	if (ret.second) 
		cout << "第二次插入成功!" << endl;
	else 
		cout << "第二次插入失败!" << endl;
    
	//* multiset
    // multiset不会检测插入数据是否和原有数据相同，因此可以插入重复数据
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) 
		cout << *it << " ";
	cout << endl;
}

//* 对组创建的两种方式
void test07()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " <<  p.first << " 年龄： " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};

//* 仿函数-小括号重载-自定义排序规则
class MyCompare 
{
public:
    //C++11特性，要加const，否则会报错
	bool operator()(const Person &p1, const Person &p2) const
	{
		//按照年龄进行排序  降序
		return p1.m_Age > p2.m_Age;
	}
};

void test08() 
{   
    //使用默认排序规则 
	set<Person> s1;
    Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person>::iterator it = s1.begin(); it != s1.end(); it++) 
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	cout << endl;

	//* 利用仿函数重新指定排序规则
	set<Person, MyCompare> s2;

	s2.insert(p1);
	s2.insert(p2);
	s2.insert(p3);
	s2.insert(p4);

	for (set<Person, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
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
