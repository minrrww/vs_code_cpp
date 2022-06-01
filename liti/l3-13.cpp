#include <iostream>
#include <iomanip>
using namespace std;
void fiddle(int in1,int &in2)
{
    in1 += 100;
    in2 += 100;
    cout << "The values are:" << endl;
    cout << setw(5) << in1 << endl;
    cout << setw(5) << in2 << endl;
}
int main()
{
    int a = 7, b = 12;
    cout << "The values are:" << endl;
    cout << setw(5) << a << endl;
    cout << setw(5) << b << endl;
    fiddle(a, b);
    cout << "The values are:" << endl;
    cout << setw(5) << a << endl;
    cout << setw(5) << b << endl;
    getchar();
    return 0;
}
