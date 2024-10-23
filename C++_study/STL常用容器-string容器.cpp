#include <iostream>
#include <string>

using namespace std;

//* string的四种构造方式
void test01()
{
	string s1; //创建空字符串，调用无参构造函数
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str); //把c_string转换成了string

	cout << "str2 = " << s2 << endl;

	string s3(s2); //调用拷贝构造函数
	cout << "str3 = " << s3 << endl;

	string s4(10, 'a');//使用n个字符c初始化 
	cout << "str3 = " << s3 << endl;

    cout << endl;
}

//* 赋值
void test02()
{
    //* 前三种赋值方式的原理：‘=’运算符重载
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;

    cout << endl;
}

//* 字符串拼接
void test03()
{
	string str1 = "我";
    //前三个重载+=
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;
	
	str1 += ':';
	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";

	str3.append(" love ");

	str3.append("game abcde", 4);

	//str3.append(str2);
	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;

    cout << endl;
}

//* 查找
void test04()
{
    // int find(const char* s, int pos, int n) :从pos位置查找s的前n个字符第一次位置
    // int find(const char* s, int pos = 0) :查找s第一次出现位置,从pos开始查找
	string str1 = "abcdefgde";

	int pos = str1.find("de");
	if (pos == -1)
		cout << "未找到" << endl;
	else
		cout << "pos = " << pos << endl;
    //* r:Right，意即从右往左查找
    // int rfind(const char* s, int pos, int n) :从pos查找s的前n个字符最后一次位置
    // int rfind(const char* s, int pos = npos) :查找s最后一次出现的位置,从pos开始查找
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;

    cout << endl;
}

//* 替换
void test05()
{
    // string& replace(int pos, int n, const string& str) :替换从pos开始n个字符为字符串str
    // string& replace(int pos, int n,const char* s) :替换从pos开始的n个字符为字符串s
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;

    cout << endl;
}

//* 字符串比较
void test06()
{
	string s1 = "hello";
	string s2 = "heLlo";

	int ret = s1.compare(s2);

	if (ret == 0) 
		cout << "s1 等于 s2" << endl;
	else if (ret > 0)
		cout << "s1 大于 s2" << endl;
	else
		cout << "s1 小于 s2" << endl;
}

//* 获取字符
void test07()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
		cout << str[i] << " ";
	cout << endl;

	for (int i = 0; i < str.size(); i++)
		cout << str.at(i) << " ";
	cout << endl;

	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

//* 字符串插入和删除
void test08()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);  //从1号位置开始3个字符
	cout << str << endl;
}

//* 子串
void test09()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

    //* 灵活的运用求子串功能，可以在实际开发中获取有效的信息
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();

	return 0;
}
