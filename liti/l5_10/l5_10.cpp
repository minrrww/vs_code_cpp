#include <iostream>
#include "point.h"
using namespace std;

int main()
{
    Point a(5, 6);
    cout << "Point A:" << a.getX() << "," << a.getY() << endl;
    Point::showCount();
    Point b(a);
    cout << "Point B:" << b.getX() << "," << b.getY() << endl;
    Point::showCount();
    Point c(3, 2);
    cout << "Point C:" << c.getX() << "," << c.getY() << endl;
    Point::showCount();
    return 0;
}
