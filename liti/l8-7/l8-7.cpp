#include <iostream>
#include "Trapzint.h"
#include <iomanip>
using namespace std;

int main()
{
    MyFunction f;
    Trapz trapz(f);
    cout << "TRAPZ Int:" << setprecision(8) << trapz(0, 2, 1e-7) << endl;
    return 0;
}
