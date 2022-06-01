#include <iostream>

using namespace std;
class Point
{
public:
    Point(int xx=0,int yy=0)
    {
        x = xx;
        y = yy;
    }
    Point(Point &p);
    int getX() { return x; }
    int getY() { return y; }
    void show();

protected:

private:
    int x, y;
};
Point::Point(Point &p):x(p.x),y(p.y)
{
    cout << "Calling the copy constructor" << endl;
}
void Point::show(){
    cout << getX() << "\t" << getY() <<endl;
}
void fun1(Point &p)
{
    cout << p.getX() << "\t" << p.getY() << endl;
}
Point fun2()
{
    Point a(1, 2);
    return a;
}
int main()
{
    Point a(4, 5);
    Point c(2, 3);
    a.show();
    Point b=a;
    a = c;
    a.show();
    b.show();
    fun1(b);
    b = fun2();
    b.show();
    return 0;
}
