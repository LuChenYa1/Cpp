#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//初始化人数
	this->m_WorkerNum = 0;

	//初始化数组指针
	this->m_WorkerArray = NULL;
}

//显示菜单
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");//这行代码删掉后会运行失败，报错
	exit(0);
}

//增加职工:采用动态数组，堆区数组空间里装着对象的指针，每次增加职工都要重新申请所有空间
void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_WorkerNum + addNum;

		//开辟新空间
		Worker ** newSpace = new Worker*[newSize];//根据要增加的职工数量，创建多个抽象职工类（父类）的指针

		//将原空间下内容存放到新空间下
		if (this->m_WorkerArray != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				newSpace[i] = this->m_WorkerArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_WorkerNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_WorkerArray;

		//更改新空间的指向
		this->m_WorkerArray = newSpace;

		//更新新的个数
		this->m_WorkerNum = newSize;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}

	system("pause");
	system("cls");
}

//保存职工信息到文件中
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		ofs << this->m_WorkerArray[i]->m_Id << " " 
			<< this->m_WorkerArray[i]->m_Name << " " 
			<< this->m_WorkerArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


WorkerManager::~WorkerManager()
{
	if (this->m_WorkerArray != NULL)
	{
		delete[] this->m_WorkerArray;
	}	
}
