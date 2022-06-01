//Fibonacci 级数
#include <iostream>

using namespace std;
int Fib(int n);
int main()
{
    int n;
    cin >> n;
    cout << Fib(n) << endl;
    for (int i = 1; i <= n;i++)
        {
            cout << Fib(i) <<"\t";
            }
            cout << endl;
            getchar();
            return 0;
}
int Fib(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2);
}
