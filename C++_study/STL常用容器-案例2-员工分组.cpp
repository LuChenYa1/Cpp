#include <iostream>
#include <map>
#include <string>

using namespace std;

class Worker
{
public:
    Worker(string Name, int Wage)
    {
        m_name = Name;
        m_wage = Wage;
    }
    string m_name;
    int m_wage;
};

//* 创建员工和员工分组（可以分开来写）
void SetByGourp(multimap<int, Worker> &m)
{
    string Str = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        //这里必须另外找一个字符串进行拼接，不能直接用str[i]
		string Name = "员工";
		Name += Str[i];
        Worker w(Name, rand() % 7000 + 3000);

        int Temp = rand() % 3 + 1;
        m.insert(make_pair(Temp, w));
    }
}

void Print(multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;

    multimap<int, Worker>::iterator it = m.find(1);//记录符合部门要求的第一个键值对的地址
    int Num = m.count(1);//统计部门人数
    int Index = 0;
    for(; it != m.end() && Index < Num; it ++, Index ++)
        cout << "姓名：" << it->second.m_name << "  工资：" << it->second.m_wage << endl;

	cout << "----------------------" << endl;
    cout << "美术部门：" << endl;

    it = m.find(2);
    Num = m.count(2);//统计部门人数
    Index = 0;
    for(; it != m.end() && Index < Num; it ++, Index ++)
        cout << "姓名：" << it->second.m_name << "  工资：" << it->second.m_wage << endl;        
    
	cout << "----------------------" << endl;
    cout << "研发部门：" << endl;

    it = m.find(3);
    Num = m.count(3);//统计部门人数
    Index = 0;
    for(; it != m.end() && Index < Num; it ++, Index ++)
        cout << "姓名：" << it->second.m_name << "  工资：" << it->second.m_wage << endl;   
}

int main(void)
{
	//随机数种子
	srand((unsigned int)time(NULL));

    multimap<int, Worker> m;//部门编号：员工
    
    SetByGourp(m);//分配员工工资和部门

    Print(m);//分部门显示员工信息

    return 0;
}

