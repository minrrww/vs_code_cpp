//example-1.4.4-.cpp
#include <iostream>
using namespace std;
int main()
{
    //currVal是我们正在统计的数；我们将读入的新值存入val
    int currVal = 0, val = 0;
    //读取第一个数，并确保实有数据可以处理
    if (cin >> currVal)
    {
        int cnt = 1; //保存我们正在处理的当前值的个数
        while (cin >> val)
        {                       //读取剩余的数
            if (val == currVal) //如果值相同
                ++cnt;          //cnt自加1
            else
            { //否则，打印前一个值得个数
                cout << currVal << " occurs "
                     << cnt << " times" << endl;
                currVal = val; //记住新值
                cnt = 1;       //重置计数器
            }
        } //while循环在这里结束
        //记住打印文件中最后一个值得个数
        cout << currVal << " occurs "
             << cnt << " times" << endl;
    } //最外层的if语句在这里结束
    return 0;
}
/*
 *42 42 42 42 42 55 55 62 100 100 100 42^Z
 *42 occurs 5 times
 *55 occurs 2 times
 *62 occurs 1 times
 *100 occurs 3 times
 *42 occurs 1 times
 */
