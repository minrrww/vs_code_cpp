//函数重载
#include <iostream>
using namespace std;
int quadratic_sum(int x, int y);
double quadratic_sum(double x, double y);//函数重载
int main()
{
    int a=3, b=4;
    double m=3.3, n=4.4;
    cout << "The integer sum of squares :" << quadratic_sum(a, b) << endl;
    cout << "The double  sum of squares :" << quadratic_sum(m, n) << endl;
    getchar();
    return 0;
}
int quadratic_sum(int x, int y)
{
    return x * x + y * y;
}
double quadratic_sum(double x, double y)
{
    return x * x + y * y;
}
