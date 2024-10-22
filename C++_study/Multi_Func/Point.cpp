#include "Point.h"

void Point::SetX(int S_X)//! 函数是成员函数，不是全局函数
{
    X = S_X;
}

int Point::ReadX(void)
{
    return X;
}

void Point::SetY(int S_Y)
{
    Y = S_Y;
}

int Point::ReadY(void)
{
    return Y;
}
