#include <cmath>
#include <iostream>
using namespace std;
double _power(double x, int n);
double _arctan(double x);
double _sin(double x);
double _fabs(double t);
const double TINY_VALUE = 1.0e-15;
const double TINY_VAL = 1.0e-6;
int main()
{
    double Pi;
    Pi = 16.0 * _arctan(1.0 / 5.0) - 4.0 * _arctan(1.0 / 239.0);
    cout << Pi << endl;
    double r, s, k, k1, k2;
    cin >> r >> s;
    k1 = sqrt(_power(_sin(r), 2) + _power(_sin(s), 2));
    k2 = 1 / 2 * _sin(r * s);
    k = (_power(r, 2) <= _power(s, 2)) ? k1 : k2;
    cout << k << endl;
    getchar();
    return 0;
}
double _arctan(double x)
{
    double e, n = 0.0;
    int i = 1;
    do
    {
        e = _power(x, i) / i;
        n = (i % 4 == 1) ? n + e : n - e;
        i += 2;
    } while (e > TINY_VALUE);
    return n;
}
double _power(double x, int n)
{
    double r = 1.0;
    for (int i = 1; i <= n; i++)
    {
        r *= x;
    }
    return r;
}
double _sin(double x)
{
    double g=0.0, t=x;
    int i = 1;
    do
    {
        g += t;
        i++;
        t *= -x * x / (2 * i - 1) / (2 * i - 2);
    } while (_fabs(t) > TINY_VAL);
    return g;
}
double _fabs(double t)
{
    double n;
    n = (t > 0) ? t : (t* -1);
    return n;
}

