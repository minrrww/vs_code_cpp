#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    SalesItem book1; //声明变量，并调用无参数构造函数
    //读入ISBN号，售出的册数以及销售价格
    cin >> book1;
    SalesItem book2 = SalesItem(); //调用无参构造函数
    //读入ISBN号，售出的册数以及销售价格
    cin >> book2;
    SalesItem book3("0-201-70353-X");       //调用一个参数构造函数
    SalesItem book4("0-201-70353-X", 2);    //调用二个参数构造函数
    SalesItem book5("0-201-70353-X", 2, 3); //调用三个参数构造函数
    SalesItem book6 = SalesItem(cin);       //读入ISBN号，售出的册数以及销售价格
    SalesItem book7();                      //声明函数，而不是调用无参构造函数
    //写出ISBN号，售出的册数、总销售额以及平均价格
    cout << book6 + book1 + book2 + book3 + book4 + book5 + book7() << endl;
    return 0;
}
SalesItem book7()
{
    SalesItem book;
    cin >> book;
    return book;
}
