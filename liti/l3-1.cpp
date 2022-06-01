#include <iostream>
using namespace std;
double power(double x,int n)
{
    double val = 1.0;
    while(n--)val *= x;
    return val;
}
int main()
{
    int value=0;
    cout << "5 to the power 2 is " << power(5.0, 2) << endl;
    cout << "Enter a 8 bit binary number:";
    for (int i = 1; i <= 8;i++)
    {
        char ch;
        cin >> ch;
        if(ch=='1')
            value += static_cast<int>(power(2, 8 - i));
    }
    cout << "Decimal value is " << value << endl;
    getchar();
    return 0;
}
