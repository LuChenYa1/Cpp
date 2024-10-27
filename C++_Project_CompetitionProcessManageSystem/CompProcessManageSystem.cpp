#include <iostream>
#include "ProcessManager.h"

//! 进程：开始比赛成员函数添加

int main()
{
    ProcessManager PM;

    while(1)
    {
        PM.Show_Menu();
        int Choice = 0;
        cin >> Choice;//接收用户选择

        switch (Choice)
        {
        case 1://开始比赛
            
            break;
        case 2://查看记录
            
            break;
        case 3://清空记录
            
            break;
        case 0://退出系统
            PM.ExitSyetem();
            break;
        default:
            system("cls");//清屏
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }
}
