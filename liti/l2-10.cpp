#include <iostream>
using namespace std;
int main()
{
    int n, j = 0;
    cout << "Enter a Number:" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            j++;
            cout << "Num " << j << " factor:" << i << endl;
        }
    }
    getchar();
    getchar();
    return 0;
}
