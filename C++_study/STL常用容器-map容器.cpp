#include <iostream>
#include <map>

using namespace std;

//* map中所有元素都是pair
//* pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
//* map/multimap属于关联式容器，内部自动排序（默认升序）
//* map不允许容器中有重复key值元素，multimap可以有重复元素
//* 增加元素只能insert

void PrintMap(map<int, int> &m) //* 注意：不能用const 修饰，会报错，原因未知
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key = " << it->first << " value = " << it->second << endl;
	cout << endl;
}

//* 构造和赋值
void test01()
{
    cout << "-----构造和赋值-----" << endl;

	map<int,int> m; //默认构造
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(2, 20));
	PrintMap(m);

	map<int, int> m2(m); //拷贝构造
	PrintMap(m2);

	map<int, int>m3;
	m3 = m2; //赋值
	PrintMap(m3);
}

//* 判断是否为空，获取元素数量
void test02()
{
    cout << "-----判断是否为空，获取元素数量-----" << endl;

	map<int, int> m;
    m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));

	if (m.empty())
		cout << "m为空" << endl;
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为： " << m.size() << endl;//记录键值对的数量
	}
}

//* 交换
void test03()
{
    cout << "-----交换-----" << endl;

	map<int, int> m1;
    m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(1, 10));

	map<int, int> m2;
	m2.insert(pair<int, int>(6, 300));
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));

	cout << "交换前" << endl;
	PrintMap(m1);
	PrintMap(m2);

	cout << "交换后" << endl;
	m1.swap(m2);
	PrintMap(m1);
	PrintMap(m2);
}

//* 插入和删除
void test04()
{
    cout << "-----插入和删除-----" << endl;

	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(4, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	m[4] = 40; //m[key] = value; 
	PrintMap(m);

	//删除
	m.erase(m.begin()); //删除pos迭代器所指的元素，返回下一个元素的迭代器
	PrintMap(m);

	m.erase(3);//通过key键删除
	PrintMap(m);

	//清空
	m.erase(m.begin(),m.end());//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
	m.clear();
	PrintMap(m);
}

//* 查找和统计
void test05()
{
    cout << "-----查找和统计-----" << endl;

	map<int, int> m; 
	m.insert(pair<int, int>(3, 10));
	m.insert(pair<int, int>(1, 20));
	m.insert(pair<int, int>(4, 30));
    m.insert(pair<int, int>(3, 30));

	//查找
	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	else
		cout << "未找到元素" << endl;

	//统计
	int num = m.count(3);
	cout << "num = " << num << endl;//map容器不能有重复的键值对，所以计数结果只能是0/1
}

//* 利用仿函数改变排序规则
//* 对于自定义数据类型，map必须要指定排序规则,同set容器
class MyCompare 
{
public:
	bool operator()(int v1, int v2) 
    {
		return v1 > v2;
	}
};

void test06() 
{
	//默认从小到大排序
	//利用仿函数实现从大到小排序
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) 
		cout << "key:" << it->first << " value:" << it->second << endl;
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
