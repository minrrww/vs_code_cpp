#include <iostream>
using namespace std;
int main()
{
    for (int n = 100; n <= 200; n += 2)
    {
        cout << n << endl;
    }
    int n = 100;
    while (n <= 200)
    {
        cout << n << endl;
        n += 2;
    }
    n = 100;
    do
    {
        cout << n << endl;
        n += 2;
    } while (n <= 200);
    getchar();
    return 0;
}
