//example-1.4.2-.cpp
#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    //从1加到10
    for (int val = 1; val <= 10; ++val)
    {
        sum += val; //将sum+val赋值给sum
    }
    cout << "Sum of 1 to 10 inclusive is "
         << sum << endl;
    return 0;
}
/*
 *Sum of 1 to 10 inclusive is 55
 */
