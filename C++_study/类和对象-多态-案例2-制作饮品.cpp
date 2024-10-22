#include <iostream>

using namespace std;

//! 纯虚函数  virtual 返回值 函数名 (形参) = 0; 
//! 用途：这个类本身的内容不会被调用，只是作为一个桥梁存在，因此可以直接写成抽象类，无需写函数体
//! 类中只要有一个纯虚函数就称为抽象类
//* 抽象类特点：
//! 抽象类无法实例化对象
//! 子类必须重写父类中的纯虚函数，否则也属于抽象类

//* 纯虚析构和虚析构的语法和普通成员函数一样，用于子类存在成员指针指向堆区空间时进行释放（但父类不存在）（使用多态时）

//! 纯虚函数与虚函数的区别：
//* 纯虚函数使类成为抽象类，无法实例化对象，但虚函数不影响类

//* 抽象制作饮品(父类)
class AbstractDrinking 
{
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//规定流程
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//* 制作咖啡（子类-对父类进行细化）
class Coffee : public AbstractDrinking 
{
public:
	//烧水
	virtual void Boil() {
		cout << "煮农夫山泉!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将咖啡倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入牛奶!" << endl;
	}
};

//* 制作茶水（子类-对父类进行细化）
class Tea : public AbstractDrinking 
{
public:
	//烧水
	virtual void Boil() {
		cout << "煮自来水!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将茶水倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入枸杞!" << endl;
	}
};

//* 业务函数
void DoWork(AbstractDrinking* drink) 
{
	drink->MakeDrink();
	delete drink;
}

int main() 
{
	DoWork(new Coffee);
	cout << "--------------" << endl;
	DoWork(new Tea);

	return 0;
}