//example-1.6-.cpp
#include <iostream>
#include "SalesItem.h"
using namespace std;
int main()
{
    SalesItem total; //保存下一条交易记录点变量
    //读入第一条交易记录，并确保有数据可以处理
    if (cin >> total)
    {
        SalesItem trans; //保存和的变量
        //读入并处理剩余交易记录
        while (cin >> trans)
        {
            //如果我们扔在处理相同的书
            if (total.sameIsbn(trans))
                total += trans; //更新总销售额
            else
            {
                //打印前一本书的结果
                cout << total << endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        cout << total << endl; //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告读者
        cerr << "No data?!" << endl;
        return -1; //表示失败
    }
    return 0;
}
/*成功
0-201-70353-X 3 3
0-201-70353-X 4 3
0-201-70353-X 6 3
0-203-70353-X 5 3
0-201-70353-X   13      39      3
0-203-70353-X 4 3
0-203-70353-X 3 3
0-207-70353-X 7 3
0-203-70353-X   12      36      3
0-207-70353-X 4 3
0-207-70353-X 3 3
^Z
0-207-70353-X   14      42      3
 */
/*失败
0-207-70353-X a 3
No data?!
 */
