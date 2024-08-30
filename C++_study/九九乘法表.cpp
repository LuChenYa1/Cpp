#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "= " << i*j << "\t";
			//break;无论break还是continue，都只能针对当前所在的最近的循环进行跳出或者中止循环
		}
		cout << "\n";
	}
	return 0;
}
