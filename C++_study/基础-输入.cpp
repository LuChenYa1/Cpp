#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	/* out输出<<
	in输入>>

	char ch;
	cout << "请输入ch的值" << endl;
	cin >> ch;只能输入字符，不能是码值
	cout << "ch的值是" << ch << endl;

	string str;
	cout << "请输入str的值" << endl;
	cin >> str;
	cout << "str的值是" << str << endl;
 */
	bool flag = 0;//布尔类型赋值不能输入英文和小数，会被判定为假0
	cout << "请输入flag的值" << endl;
	cin >> flag;
	cout << "flag的值是" << flag << endl;
	return 0;
}
