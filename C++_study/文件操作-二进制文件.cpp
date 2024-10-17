#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

char Array[11] = "HelloWorld";

//* 二进制文件  写文件
void test01()
{
	//1、包含头文件

	//2、创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary);
	
	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"张三"  , 18};

	//4、写文件
    //* 指定写入数据类型和字节数
	ofs.write((const char *)&p, sizeof(p));
    ofs.write(Array, 10);

	//5、关闭文件
	ofs.close();
}

//* 读文件
void test02()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p1;
    //* 指定读取字节数和数据存放位置
	ifs.read((char *)&p1, sizeof(p1));

	cout << "姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;
}

int main() 
{
	test01();
	test02();

	return 0;
}