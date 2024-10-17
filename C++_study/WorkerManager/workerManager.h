#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define  FILENAME "WorkerFile.txt"

using namespace std;

//* 职工管理类
class WorkerManager
{
public:

	//* 构造函数
	WorkerManager();

    //* 展示菜单
    void Show_Menu();

	//* 退出功能
	void exitSystem();

	//* 增加职工
	void Add_Emp();	

	//* 保存文件
	void save();

	//* 读取文件统计人数
	int get_WorkerNum();
	
	//* 初始化员工数组
	void init_Worker();

	//* 显示职工
	void Show_Worker();

	//* 删除职工
	void Del_Worker();

	//* 按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);

	//* 修改职工
	void Mod_Worker();

	//* 析构函数
	~WorkerManager();

	//* 记录文件中的人数个数
	int m_WorkerNum;

	//* 员工数组的指针
	Worker ** m_WorkerArray;

	//* 标志文件是否为空
	bool m_FileIsEmpty;
};
