#include <iostream>
using namespace std;
int comm(int n, int k)
{
    if (k > n)
        return 0;
    else if (k == n || k == 0)
        return 1;
    else
        return comm(n - 1, k) + comm(n - 1, k - 1);
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << comm(n, k) << endl;
}
