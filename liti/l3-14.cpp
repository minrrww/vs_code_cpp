#include <iostream>

using namespace std;
const double PI = 3.14159265358979;
inline double circleArea(double r)//内联函数，inline 修饰的不一定是内联函数，没修饰的不一定不是内联函数，看函数的简单程度
{
    return r * r * PI;
}
int main()
{
    double r = 25.01;
    cout << circleArea(r);
    getchar();
    return 0;
}

