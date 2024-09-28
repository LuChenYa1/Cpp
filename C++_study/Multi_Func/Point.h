#pragma once //* ·ÀÖ¹ÖØ¸´°üº¬
#include <iostream>

using namespace std;

class Point
{
public:
    void SetX(int S_X);
    int ReadX(void);
    void SetY(int S_Y);
    int ReadY(void);
private:
    int X;
    int Y;
};
