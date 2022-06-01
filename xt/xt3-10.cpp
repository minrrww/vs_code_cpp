//greatest common divisor(gcd) 最大公约数
//lowest common multiple (LCM) 最小公倍数
//divisor除数  dividend 被除数
#include <cmath>
#include <iostream>
using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
    getchar();
    return 0;
}
int gcd(int a, int b)
{
    int divisor = (a <= b) ? a : b, dividend = (a <= b) ? b : a;
    if (dividend % divisor == 0)
        return divisor;
    else
        return gcd(divisor, dividend % divisor);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
