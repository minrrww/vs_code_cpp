#include <iostream>
#include <iomanip>//setw setprecision
using namespace std;
int main()
{
    int i = 1;
    cout << i++ << endl;//cout<<i=1,i++,i=2
    cout << ++i << endl;//i++,i=3,cout<<i=3
    char cval = 97;
    short sval =1;
    int ival = 2;
    unsigned uval = 3;
    long lval = 4;
    unsigned long ulval = 5;
    float fval = 6.6;
    double dval = 7.7;
    cout << cval + sval << endl;
    cout << sval + ival << endl;
    cout <<ival + uval << endl;
    cout << uval + lval << endl;
    cout << lval + ulval << endl;
    cout << ulval + fval << endl;
    cout << fval + dval << endl;
    cout << float(dval)<< endl;
    cout << (__int64)dval<< endl;
    cout << setw(5) << setprecision(3) << 3.14159265 << endl<< fval << endl;
    getchar();
    return 0;

}
