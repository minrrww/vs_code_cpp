//prime number 素数
//Determine if it is prime  判断是否是素数
#include <cmath>
#include <iostream>
using namespace std;
bool Determine_Prime(int x);
int main()
{
    int x;
    cin >> x;
    if (x <= 1)
    {
        cout << "Please enter integers greater than 0.";
        cin >> x;
    }
    else if (Determine_Prime(x))
        cout << x << " is a prime number." << endl;
    else
        cout << x << " is not a prime number." << endl;
    getchar();
    return 0;
}
bool Determine_Prime(int x)
{
    if (x <= 1)
        return false;
    else
    {
        double a = sqrt(x);
        int j = 0;
        for (int i = 2; i <= (int)a; i++)
        {
            if (x % i == 0)
                j++;
        }
        if (j == 0)
            return true;
        else
            return false;
    }
}
