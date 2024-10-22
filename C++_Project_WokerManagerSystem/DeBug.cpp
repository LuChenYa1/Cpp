#include<iostream>
#include "workerManager.h"
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main() 
{
	WorkerManager wm;
	int choice = 0;
	while (1)
	{
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Worker();
			 
			break;
		case 3: //删除职工
			wm.Del_Worker();
			break;
		case 4: //修改职工
			wm.Mod_Worker();
			break;
		case 5: //查找职工
			wm.Find_Worker();
			break;
		case 6: //排序职工
			wm.Sort_Worker();
			break;
		case 7: //清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	// wm.Mod_Worker();

	return 0;
}
