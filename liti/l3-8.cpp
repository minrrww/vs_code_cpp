#include <iostream>
using namespace std;
unsigned fac(unsigned n)
{
    unsigned f;
    if (n == 1)
        f = 1;
    else
        f = fac(n - 1)*n;
    return f;
}
int main()
{
    unsigned n, y;
    cin >> n;
    y = fac(n);
    cout << y << endl;
    getchar();
    return 0;
}
