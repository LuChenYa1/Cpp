#include <iostream>
#include <string.h>
using namespace std;

// x64系统中，指针是八字节
//整形
//* 1、int_4 (-32768~32767)
//* 2、short_2
//* 3、long_4  注：Windows：4字节；Linux：4字节（32位），8字节（64位）
//* 4、long long_8

int main()
{
	//短整型2
	short range1 = -32768;
	cout << range1 << endl;
	std::cout << "hello C++" << std::endl;
	std::cin.get();//获取一次按键输入

	//* 浮点型4
	float num = 3.1415926f;//! C++里输出小数默认五位，不是六位
	cout << num << "是" << sizeof(num) << "个字节" << endl;

	//字符1
	char num2 = 'a';
	cout << num2 << " " << (int)num2 << endl;

    //只要用到了字符串，就要加头文件
	//字符串C写法,效率更高
	char str[] = "hello world";
	//* 字符串C++写法
	string str1 = "hello world";
	cout << str << endl;
	cout << str1 << endl;

	//布尔类型(1/0)，除了0都是1
	bool flag = true;
	cout << flag << "占" << sizeof(flag) << "个字节" << endl;
	return 0;
}
