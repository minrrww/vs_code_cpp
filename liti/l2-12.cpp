#include <iostream>
using namespace std;
int main()
{
    int n = 0, m = 0, x;
    cout << "Enter some integers please:" << endl;
    cin >> x;
    while (x != 0)
    {
        if (x > 0)
            n++;
        else
            m++;
        cin >> x;
    }
    cout << "Cout of positive integers:" << n << endl;
    cout << "Cout of negative integers:" << m << endl;
    getchar();
    return 0;
}
