#include <iostream>
#include <string.h>

using namespace std;

//* 顺序、选择、循环
int main(void)
{
	int a = 10;
	float b = 11;
	int c = 5;
	 
	// 证明不同数据类型可以比较大小
	if (a < b)
	{
		cout << "是的a<b" << endl;
	}
	else if (a == b)
	{
		cout << "emmmm" << endl;
	}
	else
	{
		cout << "啥呀这是" << endl;
	}

	switch (a)//只能是整型或者字符型
	{
        case 1:break;
        case 2:break;
        case 3:break;
        default:break;
	}
	
	while (a--)
	{
		cout << "a" << endl;
	}
 
	do
    {
		a++;
    }while(a < 20);
    
	return 0;
}
