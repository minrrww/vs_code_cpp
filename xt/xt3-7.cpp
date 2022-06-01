#include <iostream>

using namespace std;
int fun(unsigned short a, unsigned short b);
int main()
{
    unsigned short a, b;
    cin >> a >> b;
    cout << fun(a, b) << endl;
    getchar();
    return 0;
}
int fun(unsigned short a, unsigned short b)
{
    int r;
    if (b == 0)
        return -1;
    else
    {
        r = a / b;
        return r;
    }
}
