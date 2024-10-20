#include <iostream>

using namespace std;

//! const 用于防止误操作

int main(void)
{
    int A = 10;
    int B = 20;
    int C = 30;
    const int * p = &A;//* 常量指针，const 修饰 int ，所以 p 指向的空间不能被修改，但p本身可以修改
    int * const p_1 = &B;//* 指针常量，const 修饰 p_1 ，所以 p本身不能被修改，但 p 指向的空间可以修改
    
    const int * const p_2  = &C;//* const 同时修饰 int 和 p_2, 所以指针本身和其指向的空间都不能被修改

    //举例（反例）
    // *p = 20;
    // p = &B;
    // *p_1 = 30;
    // p_1 = &C;
    // *p_2 = 40;
    // p_2 = &B;

    return 0;
}
