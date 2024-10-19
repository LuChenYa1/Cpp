#include <iostream>

using namespace std;

//* 只要是在模板类声明外出现这个模板类，都认为是调用这个模板类，包括子类继承父类的情况

template<typename T>
class Base
{
	T m;
};

//* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定父类中T的类型
//class Son:public Base  //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son :public Base<int> //必须指定一个类型
{
};

//* 如果想灵活指定出父类中T的类型，子类也需变为类模板
//* 类模板继承类模板 ,可以用T2指定父类中的T类型
template<typename T2>
//父类是模板类，其被子类调用，需遵循调用模板类规则，即指定父类中存在的泛型的类型
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << typeid(T2).name() << endl;
	}
};

int main() 
{
    Son c;

	Son2<int> child1;

	return 0;
}
