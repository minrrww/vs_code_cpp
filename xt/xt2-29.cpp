#include <iostream>
using namespace std;
int yinnum(int);
int zhishu(int);
int main()
{
    int n;
    cin >> n;
    zhishu(n);
    getchar();
    return 0;
}
int zhishu(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (yinnum(i) == 2)
            cout << i << endl;
    }
    return 0;
}
int yinnum(int n)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            j++;
    }
    return j;
}
