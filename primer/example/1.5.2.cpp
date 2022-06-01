//example-1.5.2-.cpp
#include <iostream>
#include "SalesItem.h"
using namespace std;
int main()
{
    SalesItem book1, book2; //声明变量，并调用无参数构造函数
    //读入ISBN号，售出的册数以及销售价格
    cin >> book1 >> book2;
    //检查是否是相同书籍
    if (book1.sameIsbn(book2)) //调用samIsbn函数
    {
        cout << book1 + book2 << endl;
        return 0; //表示成功
    }
    else
    {
        cerr << "Data must refer to same ISBN" << endl;
        return -1; //表示失败
    }
}
/*失败
 *0-201-70353-X 4 3
 *0-203-70353-X 5 3
 *Data must refer to same ISBN
*/
/*成功
 *0-201-70353-X 3 3
 *0-201-70353-X 4 3
 *0-201-70353-X   7       21      3
 */
