#include <iostream>

using namespace std;

int main(void)
{
	// \n
	cout << "aaaa\n" << endl;
	cout << "aaa\n";
	cout << "aaaaaaa";
	cout << "aaaa" << endl;
	//综上，结束提示语永远在结尾单独成行，和是否加换行没关系，但光标会随换行移动

	//反斜杠
	cout << "\\" << endl;//要\,则\\；
	cout << "\"" << endl;//以此类推，要输出特殊字符，需要反斜杠
	cout << "\\\\" << endl;
	cout << "\'" << endl;

	//水平制表符
	cout << "hello\tworld" << endl;//垂直对齐
	cout << "aa\tbbbbb" << endl;//一行的第一个\t从行首八个空格占位
	cout << "aaaa\tbbbbbb\tcccccccccccc\tddd" << endl;//超过八个就没用了
	cout << "aaaa\tbbbbbb\tcccc\tddd" << endl;//一行的第二个\t从第一个\t开始占位
	return 0;
}
