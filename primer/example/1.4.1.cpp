//example-1.4.1-.cpp
#include <iostream>
using namespace std;
int main()
{
    int sum = 0, val = 1;
    //只要val的值小于等于10，while循环就会持续执行
    while (val <= 10)
    {
        sum += val; //将sum+val赋值给sum
        ++val;      //将val+1赋值给val
    }
    cout << "Sum of 1 to 10 inclusive is "
         << sum << endl;
    return 0;
}
/*
 *Sum of 1 to 10 inclusive is 55
 */
