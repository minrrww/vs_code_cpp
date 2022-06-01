#include <iostream>
#include "Array.h"
using namespace std;
void read(int*p,int n){
    for (int i = 0; i < n;i++)

        cin >> p[i];
}
int main()
{
    Array<int> a(10);
    read(a, 10);
    return 0;
    return 0;
}
