#pragma
#include <iostream>
#include "Point.h"

using namespace std;

class Circle 
{
public:
    void SetR(int S_R);
    int ReadR(void);
    void SetCenter(Point S_Center);
    Point ReadCenter();
private:
    int R;
    Point Center;
};
