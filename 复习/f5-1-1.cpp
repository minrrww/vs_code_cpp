//circle

#include <iostream>

using namespace std;
class Point
{
private:
    int x, y;
public:
 Point(int x=0,int y=0):x(x),y(y){}
 Point(const Point &p):x(p.x),y(p.y){}
 ~Point(){}
 int getX() const { return x; }
 int getY() const { return y; }
 void show()const{
     cout << "(" << x << "," << y << ")" << endl;
 }
};

class Circle
{
private:
    Point centerPoint;
    float r;
    static float PI;
public:
    Circle(Point c, float r = 1) : centerPoint(c), r(r){}
    Circle(const Circle &c):centerPoint(c.centerPoint),r(c.r){}
    ~Circle(){}
    double areaCircle();
    double (*a)();
    double perimeterCircle();
    void show(){
        cout << "centerPoint:\t";
        centerPoint.show();
        cout << "R:\t\t" << r << endl;
        cout << "Area:\t\t" << areaCircle() << endl;
        cout << "Perimeter:\t" << perimeterCircle() << endl;
    }
};
double Circle::areaCircle(){
    double R = static_cast<double>(r);
    return PI * R * R;
}
double Circle::perimeterCircle(){
    double R=static_cast<double>(r);
    return 2 * PI * R;
}
float Circle::PI = 3.141593;
int main()
{
    Point centerP(3, 5);
    Point *ptr =& centerP;
    double (Circle::*a)() =& Circle::areaCircle;
    float R = 5;
    Circle c(*ptr, R);
    cout<<(c.*a)()<<endl;
    c.show();
    return 0;
}
