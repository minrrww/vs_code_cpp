//example-3.5.2-.cpp
#include <iostream>

using namespace std;

int main()
{
    unsigned grade;
    unsigned scores[11] = {}; //11个分数段，全部初始化为0
    while (cin >> grade)             //读取成绩
    {
        if (grade <= 100)         //只处理有效成绩
            ++scores[grade / 10]; //将对应的分数段的计数器加1
    }
    for (unsigned s : scores) //对于scores中的每个计数值
        cout << s << " ";     //输出当前的计数值
    cout << endl;
    return 0;
}
/*
12 23 32 43 54 65 76 87 98 100 5
^Z
1 1 1 1 1 1 1 1 1 1 1
*/
