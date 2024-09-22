#include <iostream>
#include <string>
#include "Multi_Func/Func.h" //! 注意用双引号，在settings.json 文件中增加编译文件

using namespace std;

int main(int argc, char ** argv)
{
	cout << "1 + 2 = " << Func(1, 2) << "\t";
	return 0;
}
