#include <cmath>
#include <iostream>
using namespace std;
class Point
{
public:
    Point(int xx, int yy) : x(xx), y(yy) {}
    Point(int xx) : x(xx), y(0) {}
    Point() : x(0), y(0) {}
    Point(const Point &p) : x(p.x), y(p.y) {}
    int getX() { return x; }
    int getY() { return y; }

private:
    int x;
    int y;
};
class Rectangle
{
private:
    Point a;
    Point b;
    double area;

public:
    Rectangle(Point A, Point B) : a(A), b(B)
    {
        area = fabs((B.getX() - A.getX()) * (B.getY() - A.getY()));
    }
    Rectangle(Rectangle const &R) : a(R.a), b(R.b), area(R.area) {}
    Point getA() { return a; }
    Point getB() { return b; }
    double getArea() { return area; }
};
int main()
{
    Point a;
    Point b;
    a = Point(1, 3);
    b = Point(6);
    Rectangle rect(a, b);
    cout << Rectangle(Point(), Point(4, 8)).getArea() << endl;
    cout << Rectangle(a, b).getArea() << endl;
    cout << rect.getArea() << endl;
    cout << Point(1, 3).getX() << endl;
    return 0;
}
