#include <cmath>
#include <iostream>
using namespace std;
class Point
{
public:
    Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
    Point(int xx) : x(xx), y(0) {}
    Point() : x(0), y(0) {}
    Point(const Point &p);
    int getX() { return x; }
    int getY() { return y; }

protected:
private:
    int x, y;
};
Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    cout << "Caling the copy constructor of Point" << endl;
}
class Line
{
public:
    Line(Point xp1, Point xp2);
    Line(const Line &l);
    double getLen() { return len; }

protected:
private:
    Point p1, p2;
    double len;
};
Line::Line(Point xp1, Point xp2):p1(xp1),p2(xp2)
{
    cout << "Calling constructor of Line" << endl;
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x * x + y * y);
}
Line::Line(const Line &l) : p1(l.p1), p2(l.p2), len(l.len)
{
    cout << "Calling the copy constructor of Line" << endl;
}
int main()
{
    Point myp1(1, 1), myp2(4, 5);
    Line line(myp1, myp2);
    Line line2(line);
    cout << Line(Point(2, 3), Point(3, 5)).getLen() << endl;
    cout << "The length of the line is:";
    cout << line.getLen() << endl;
    cout << "The length of th line2 is:";
    cout << line2.getLen() << endl;
    getchar();
    return 0;
}
