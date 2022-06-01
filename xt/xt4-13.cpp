#include <iostream>
const float pi = 3.143593;
using namespace std;
class Circle
{
public:
    Circle(double R) : r(R) {}
    Circle(Circle &c):r(c.r){}
    ~Circle(){}
    double getR() { return r; }
    double getArea();

protected:
private:
    double r;
};
double Circle::getArea()
{
    double area = pi * r * r;
    return area;
}
int main()
{
    cout << Circle(5).getArea() << endl;

    return 0;
}
