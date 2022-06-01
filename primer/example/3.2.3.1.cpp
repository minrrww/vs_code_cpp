#include <iostream>
using namespace std;
int main()
{
    const string hexdigits = "0123456789ABCDEF"; //可能的十六进制数字
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    string result;       //用于保存十六进制字符串
    string::size_type n; //用于保存从输入流读取的数
    while (cin >> n)
        if (n < hexdigits.size())   //忽略无效输入
            result += hexdigits[n]; //得到对应的十六进制数字
    cout << "Your hex number is: " << result << endl;
    return 0;
}
/*
Enter a series of numbers between 0 and 15 separated by spaces. Hit ENTER when finished:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15^Z
Your hex number is: 123456789ABCDEF
*/
