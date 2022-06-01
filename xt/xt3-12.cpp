#include <iostream>

using namespace std;
int sum(int n);
int main()
{
    int n;
    cin >> n;
    cout << sum(n) << endl;

    getchar();
    return 0;
}
int sum(int n)
{
    if (n == 1)
        return n;
    else
        return n + sum(n - 1);
}
