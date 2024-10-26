#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//* 查找算法，需要遍历容器的每一个元素，将其与要找的元素进行 == 逻辑运算
//* 注意：如果元素是自定义数据类型，需要重载 == 运算符，自定义判断规则

class Person 
{
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//* 重载==
	bool operator==(const Person& p) 
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) 
		{
			return true;
		}
		return false;
	}

public:
	string m_Name;
	int m_Age;
};

// 对要找的值的要求(自定义数据类型)
class GreaterThanValue
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 25;
	}
};

// 对要找的值的要求（内置数据类型）
class greater_equal_count
{
public:
	bool operator()(int Val)
	{
		return Val >= 5;
	}
};

void test01()
{
	vector<Person> v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

    //* 1、查找指定值
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end()) 
		cout << "没有找到!" << endl;
	else 
		cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;

    //* 2、按照要求查找符合要求的元素
    it = find_if(v.begin(), v.end(), GreaterThanValue());
    if(it == v.end())
        cout << "没有找到!" << endl;
    else
        cout << "找到了，姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;

    //* 3、查找相邻重复元素，返回找到的第一个元素的地址
    it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) 
		cout << "找不到!" << endl;
	else 
		cout << "找到相邻重复元素为:" << it->m_Age << "  " << it->m_Name << endl;

	//* 4、二分查找指定值，存在该值就返回true,不存在就返回false
    //* 容器内的元素必须有序
    vector<int> v2;
	for (int i = 0; i < 10; i++)
		v2.push_back(i);
	bool ret = binary_search(v2.begin(), v2.end(), 7);
	if (ret)
		cout << "找到了" << endl;
	else
		cout << "未找到" << endl;

    //* 5、统计某元素出现次数
    int Num = count(v2.begin(), v2.end(), 4);
    cout << "4的个数为： " << Num << endl;

    //* 6、统计符合要求的元素个数
    int Count = count_if(v2.begin(), v2.end(), greater_equal_count());
    cout << "大于等于5的个数为： " << Count << endl;
}

int main()
{
    test01();

    return 0;
}
