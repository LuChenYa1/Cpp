#include <iostream>
//* 1、包含头文件  
#include <fstream>  // ofstream ifstream

using namespace std;

//* 文件打开方式
// ios:: in     为读文件而打开文件
// ios::out     为写文件而打开文件
// ios::ate     初始位置：文件尾
// ios::app     追加方式写文件
// ios::trunc   如果文件存在先删除，再创建
// ios::binaray 二进制方式

// 注意：文件打开方式可以配合使用，利用|操作符
// 例如：用二进制方式写文件 ios::binary |  ios:: out

//* 写文件
void test01()
{
    // //* 2、创建流对象
	// ofstream ofs;
    // //* 3、打开文件
	// ofs.open("test.txt", ios::out);
    // 可合并
    ofstream ofs("test.txt", ios::out);

    //* 4、写数据
	ofs << "姓名：张三" << endl;
	ofs << "性别：女" << endl;
	ofs << "年龄：20" << endl;

    //* 5、关闭文件
	ofs.close();
}

//* 读文件
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

    //* 利用is_open函数可以判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
	// char buf[1024] = { 0 };
	// while (ifs >> buf)
	// {
	// 	cout << buf << endl;
	// }

	//第二种
	// char buf[1024] = { 0 };
	// while (ifs.getline(buf,sizeof(buf)))
	// {
	// 	cout << buf << endl;
	// }

	//第三种
	// string buf;
	// while (getline(ifs, buf))
	// {
	// 	cout << buf << endl;
	// }

	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();
}


int main() 
{
	test01();
    test02();

	return 0;
}