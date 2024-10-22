#include <iostream>

#define DAY 7

using namespace std;

//C++ cout endline 换行
int main()
{
	cout << "一周共有" << DAY << "天" << endl;

	const int mouth = 12;  //const 常量不可修改
	//mouth = 14;
	cout << "一年共有" << mouth << "月" << endl;

	int aaa = 100;
	cout << aaa << endl;

	cout << "\n" << aaa << mouth << endl;

	system("pause");
	return 0;
}
