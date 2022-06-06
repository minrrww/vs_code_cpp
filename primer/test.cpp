#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
using namespace std;
int main()
{
    int currVal = 0, val = 0; // currVal是我们正在统计的数；我们将读入的新值存入val
    //读取第一个数，并确保实有数据可以处理
    if (cin >> currVal)
    {
        int cnt = 1; //保存我们正在处理的当前值的个数
        while (cin >> val)
        {                       //读取剩余的数
            if (val == currVal) //如果值相同
                ++cnt;          // cnt自加1
            else
            { //否则，打印前一个值得个数
                cout << currVal << " occurs "
                     << cnt << " times" << endl;
                currVal = val; //记住新值
                cnt = 1;       //重置计数器
            }
        } // while循环在这里结束
        //记住打印文件中最后一个值得个数
        cout << currVal << " occurs "
             << cnt << " times" << endl;
    } //最外层的if语句在这里结束
    return 0;
}
