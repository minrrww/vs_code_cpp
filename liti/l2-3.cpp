#include <iostream>
using namespace std;
int main()
{
    for (int i = 33; i <= 126; i++)
    {
        if ((i - 32) % 10)
        {
            cout << char(i) << "  ";              //调用构造函数转换类型
            cout << (char)(i) << "  ";            //显示转换
            cout << static_cast<char>(i) << "  "; //显示转换类型
            printf("%c  ", i);                    //c语言打印函数
        }                                         //
        else
        {
            cout << char(i) << "  ";              //调用构造函数转换类型
            cout << (char)(i) << "  ";            //显示转换
            cout << static_cast<char>(i) << "  "; //显示转换类型
            printf("%c\n", i);                    //c语言打印函数
        }
    }
    cout.precision(4);
    cout.flags(ios::fixed);
    cout << 3.1415926;
    cout.precision(3); // 保留 3 位小数
    cout.setf(ios::fixed);
    cout << 3.1415926;
    cout << endl;
    return 0;
}
