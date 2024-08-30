#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	//算数：/+、-、*、/、%、
	//++、--（前置正常、后置延后）
	//赋值：+=、-=、/=、%=、=
	//比较：==、<、>、<=、>=、输出时需要小括号，否则优先级会让程序出错
	//逻辑：！、&&、||

	int a = 10;
	int b = 3;
	int c = 2;
	cout << a * b << endl;
	cout << a / c << endl;//对于双方都是整数而言，是取整除

	double d = 5.50;
	float e = 0.510f;
	cout << a / e << endl;//只要有浮点数，不论double还是float，表达式的类型就会变为浮点型
	cout << d / e << endl;//浮点数相除正好整除时，输出值为整数

	cout << ( a >= b ) << endl;

	cout << (!a) << endl;
	cout << (!!a) << endl;//10取反是假0，再次取反是真1
 
    //三目运算符
    a = (b > c ? b : c);
    cout << ( a = (b < c ? 3 : 4 )) << endl; 
	//当三目运算符返回变量时，可对其赋值
    ( a > b ? a : b ) = 100;//对a和b较大的数赋值100，C++特殊写法
	return 0;
}
