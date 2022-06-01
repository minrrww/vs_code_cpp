#include <iostream>

using namespace std;
const float PI = 3.141593;       //π值
float const FENCE_PRICE = 35;    //栅栏单价
const float CONCRETE_PRICE = 20; //混领土单价
const int AISLE_WIDTH = 3;       //过道宽
class Circle
{
public:
    Circle(float r);
    float area();
    float perimeter();

protected:
private:
    float radius;
};
Circle::Circle(float r):radius(r){}
float Circle::area()
{
    return PI * radius * radius;
}
float Circle::perimeter()
{
    return 2 * PI * radius;
}
int main()
{
    float radius;
    cout << "Enter the radius of the pool:" << endl;
    cin >> radius;
    Circle pool(radius);
    Circle poolRim(radius + AISLE_WIDTH);
    float fenceCost = poolRim.perimeter() * FENCE_PRICE;
    cout << "Fencing Cost is $" << fenceCost << endl;
    float concreteCost = (poolRim.area() - pool.area()) * CONCRETE_PRICE;
    cout << "Concrete Cost is $" << concreteCost << endl;
    return 0;
}
