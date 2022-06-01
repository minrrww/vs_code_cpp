//example-1.4.1-.cpp
#include <iostream>
using namespace std;
int main()
{
    int sum = 0, value = 0;
    //读取数据直到遇到cin无效，计算所有读入的值得和
    //windows系统文件结束符ctrl+z，enter;linux系统文件结束符ctrl+d
    //返回的cin对象无效指遇到文件结束符（end-of-file）或无效输入
    while (cin >> value)
        sum += value; //将sum+val赋值给sum
    cout << "Sum is: "
         << sum << endl;
    return 0;
}
/*
 *23
 *32
 *^Z
 *Sum is: 55
 */
