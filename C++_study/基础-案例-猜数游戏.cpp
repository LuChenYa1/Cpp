#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(void)
{
	int num;
	int guessnum;
	string repeat;
	srand((unsigned int)time(NULL));
	num = rand() % 100 + 1;
	cout << "猜数游戏:范围0 < num <= 100" << endl;
	cout << "是否进入游戏?yes or no" << endl;
	cin >> repeat;
	if (repeat == "no")cout << "期待下次相遇" << endl;

	while (repeat == "yes")
	{
		cout << "请输入您猜的数字" << endl;
		cin >> guessnum;
		if (guessnum > num)
		{
			cout << "大了" << endl;
		}
		else if (guessnum < num)
		{
			cout << "小了" << endl;
		}
		else
		{
			cout << "正确！" << endl;
			cout << "是否继续游玩？" << endl;
			cin >> repeat;
			if (repeat == "yes")num = rand() % 100 + 1;
			else if (repeat == "no")
			{
				cout << "欢迎下次游玩本游戏" << endl;
				break;
			}
		}
	}
	return 0;
}
