#include <iostream>
using namespace std;
double getPower(int a, int m);
double getPower(double b, int m);
int main()
{
    int a, m;
    double b;
    cin >> a >> b >> m;
    cout << getPower(a, m) << endl;
    cout << getPower(b, m) << endl;
    return 0;
}
double getPower(int a, int m)
{
    if (m == 0)
        return 1;
    else if (a == 0)
        return 0;
    else if (m > 0)
        return a * getPower(a, m - 1);
    else
        return 1 / getPower(a, -m);
}
double getPower(double a, int m)
{
    if (m == 0)
        return 1;
    else if (a == 0)
        return 0;
    else if (m > 0)
        return a * getPower(a, m - 1);
    else
        return 1 / getPower(a, -m);
}
