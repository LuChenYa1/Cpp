#pragma once

#include <iostream>
#include "Speaker.h"
#include <vector>
#include <map>
using namespace std;

//演讲管理类
class ProcessManager
{
public:

	//构造函数
	ProcessManager();

    //初始化演讲者容器为空
    void InitSpeaker(void);

	//初始化创建12名选手
	void CreateSpeaker();

    //显示菜单
    void Show_Menu();

    //退出功能
    void ExitSyetem();

	//析构函数
	~ProcessManager();

	//比赛选手 容器  12人
	vector<int> v1;

	//第一轮晋级容器  6人
	vector<int> v2;

	//胜利前三名容器  3人
	vector<int> vVictory;

	//存放编号 以及对应的具体选手 
	map<int, Speaker> m_Speaker;

    //比赛轮数
	int m_Index;
};
