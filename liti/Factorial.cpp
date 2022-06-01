#include <iostream>
#include "Factorial.h"
using namespace std;

int main()
{
    const int M = 6;
    Factorial<M> f;
    cout << f.VALUE << endl;
    int array[Factorial<M>::VALUE];
    cout << Factorial<M>::VALUE << endl;
    return 0;
}
