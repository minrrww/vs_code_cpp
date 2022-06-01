#include <iostream>
#include "point.h"
using namespace std;
int Point::count = 0;
Point::Point(int x = 0, int y = 0) : x(x), y(y) { count++; }
Point::Point(Point &p) : x(p.x), y(p.y) { count++; }
void Point::showCount()
{
    cout << "   Object count=" << count << endl;
}
