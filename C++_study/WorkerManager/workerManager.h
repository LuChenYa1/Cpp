#pragma once
#include <iostream>
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define  FILENAME "WorkerFile.txt"

using namespace std;

//* 职工管理类
class WorkerManager
{
public:

	//构造函数
	WorkerManager();

    //展示菜单
    void Show_Menu();

	//退出功能
	void exitSystem();

	//增加职工
	void Add_Emp();	

	//保存文件
	void save();


	
	//析构函数
	~WorkerManager();

	//记录文件中的人数个数
	int m_WorkerNum;

	//员工数组的指针
	Worker ** m_WorkerArray;
};
