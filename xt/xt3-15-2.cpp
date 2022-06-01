//求算术平方根的方法
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double sqrt0(double number);           //二分法
double sqrt1(double number, double x); //牛顿迭代法
float sqrt2(float x);                  //卡马克快速平方根
double sqrt3(double number);           //double版
int main()
{
    freopen("in.txt", "r", stdin);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(7);
    double number = 2.0, once, twice, others;
    cout << "测试数据：" << number << endl;
    cout << "标准库求平方根：" << sqrt(number) << endl;
    cout << "二分法求平方根：" << sqrt0(number) << endl;
    cout << "迭代法求平方根: " << sqrt1(number, number / 2) << endl;
    others = sqrt0(number);
    once = 1 / sqrt3(number);  //卡马克法得出的是平方根倒数
    twice = 1 / sqrt2(number); //在一定数据范围内float和double相互转化可以不损失精度
    cout << "一次迭代卡马克法求平方根: " << once << "  相差比" << fabs(once - others) / others << endl;
    cout << "二次迭代卡马克法求平方根: " << twice << "  相差比" << fabs(twice - others) / others << endl;
    return 0;
}
double sqrt0(double number)
{
    double low = 0.0, high = number > 1 ? number : 1;
    double mid = 0, last = 0;
    do
    {
        last = mid;
        mid = (low + high) / 2;
        if (mid * mid > number)
            high = mid;
        else
            low = mid;
    } while (fabs(mid - last) > 1e-5);
    return mid;
}
double sqrt1(double number, double x)
{
    double y = (x + number / x) / 2;
    return fabs(y - x) < 0.001 ? y : sqrt1(number, y);
}
float sqrt2(float x)
{
    float xhalf = 0.5 * x;
    int i = *(int *)&x;        // get bits for floating value
    i = 0x5f3759df - (i >> 1); // gives initial guess
    //现在float最优魔值是0x5f375a86 所以上面的代码可以用  i = 0x5f375a86 - (i >> 1); 替换
    x = *(float *)&i;              // convert bits back to float
    x = x * (1.5 - xhalf * x * x); // 1st Newton step
    x = x * (1.5 - xhalf * x * x); // 2nd Newton step
    return x;
}
double sqrt3(double number)
{
    __int64 i;
    double x2, y;
    const double threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(__int64 *)&y;
    i = 0x5fe6ec85e7de30da - (i >> 1);
    y = *(double *)&i;
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration
    //y  = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration
    return y;
}
