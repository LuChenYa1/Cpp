#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_WorkerNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_WorkerArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_WorkerNum = 0;
		this->m_FileIsEmpty = true;
		this->m_WorkerArray = NULL;
		ifs.close();
		return;
	}
	//文件存在，且不空
	//读取文件从而更新职工人数
	this->m_FileIsEmpty = false;
	int num =  this->get_WorkerNum();
	cout << "您好，当前职工个数为：" << num << endl;  //测试代码
	this->m_WorkerNum = num;  //更新成员属性 

	//读取文件从而更新存储职工对象指针的数组
	//根据职工数创建数组
	this->m_WorkerArray = new Worker *[this->m_WorkerNum];
	//初始化职工
	init_Worker();

	//测试代码
	for (int i = 0; i < m_WorkerNum; i++)
	{
		cout << "职工号： " << this->m_WorkerArray[i]->m_Id
			<< " 职工姓名： " << this->m_WorkerArray[i]->m_Name
			<< " 部门编号： " << this->m_WorkerArray[i]->m_DeptId << endl;
	}
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

		//更新职工不为空标志
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "输入错误" << endl;
	}

	save();

	system("pause");//程序中断，按任意键继续运行
	system("cls");//这个命令用于清除命令行界面（即终端或命令提示符窗口）的屏幕
}

//保存职工信息到文件中
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	cout << "打开文件..." << endl;
	
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		ofs << this->m_WorkerArray[i]->m_Id << " " 
			<< this->m_WorkerArray[i]->m_Name << " " 
			<< this->m_WorkerArray[i]->m_DeptId << endl;
	}
	ofs.close();
	cout << "职工信息已录入文件！" <<endl;
}

int WorkerManager::get_WorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
        //记录人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::init_Worker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_WorkerArray[index] = worker;
		index++;
	}

	ifs.close();
}

//显示职工
void WorkerManager::Show_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_WorkerNum; i++)
		{
			//利用多态调用接口
			this->m_WorkerArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		if (this->m_WorkerArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::Del_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)  //说明index上位置数据需要删除
		{
			Worker * DelWorker = m_WorkerArray[index];
			delete DelWorker;
			for (int i = index; i < this->m_WorkerNum - 1; i++)
			{
				this->m_WorkerArray[i] = this->m_WorkerArray[i + 1];
			}
			this->m_WorkerNum--;

			this->save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{ 
			//查找到编号的职工
			delete this->m_WorkerArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;

			switch (dSelect)
			{
				case 1:
					worker = new Employee(newId, newName, dSelect);
					break;
				case 2:
					worker = new Manager(newId, newName, dSelect);
					break;
				case 3:
					worker = new Boss(newId, newName, dSelect);
					// Boss* pBoss = static_cast<Boss*>(worker);
					break;
				default:
					break;
			}
			
			//更改数据 到数组中
			this->m_WorkerArray[ret]= worker;
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_WorkerArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if(select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_WorkerNum; i++)
			{
				if (m_WorkerArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为："
                           << m_WorkerArray[i]->m_Id
                           << " 号的信息如下：" << endl;
					
					flag = true;
					this->m_WorkerArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}

	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_WorkerNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_WorkerNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_WorkerArray[minOrMax]->m_Id > m_WorkerArray[j]->m_Id)
					{
						minOrMax = j;//指极小值
					}
				}
				else  //降序
				{
					if (m_WorkerArray[minOrMax]->m_Id < m_WorkerArray[j]->m_Id)
					{
						minOrMax = j;//指极大值
					}
				}
			}

			if (i != minOrMax)
			{
				Worker * temp = m_WorkerArray[i];
				m_WorkerArray[i] = m_WorkerArray[minOrMax];
				m_WorkerArray[minOrMax] = temp;
			}
		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Worker();
	}

}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_WorkerArray != NULL)
		{
            for (int i = 0; i < this->m_WorkerNum; i++)
			{
				if (this->m_WorkerArray[i] != NULL)
				{
					delete this->m_WorkerArray[i];
				}
			}
			this->m_WorkerNum = 0;
			delete[] this->m_WorkerArray;
			this->m_WorkerArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_WorkerArray != NULL)
	{
		delete[] this->m_WorkerArray;
	}	
}
