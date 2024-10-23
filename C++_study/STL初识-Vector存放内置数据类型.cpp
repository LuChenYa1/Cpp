#include <iostream>
#include <vector>//容器库
#include <algorithm>//算法库

using namespace std;

void MyPrint(int v)
{
    cout << v << endl;
}

void Test01(void)
{
    //* 创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    //实例化一个容器
    vector<int> v;
    //* 向容器内装入数据
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.pop_back();

	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

    vector<int>::iterator pBegin= v.begin();
    vector<int>::iterator pEnd= v.end();

	//第一种遍历方式
    while(pBegin != pEnd)
    {
        MyPrint(*pBegin);
        pBegin ++;
    }

	//第二种遍历方式
    for(vector<int>::iterator it = v.begin(); it != v.end(); it ++)
    {
        MyPrint(*it);
    }

	//第三种遍历方式：
	//使用STL提供标准遍历算法  头文件 algorithm
    for_each(v.begin(), v.end(), MyPrint);   

}

int main() 
{

	Test01();

	return 0;
}
