#include <bitset>
#include <iostream>
using namespace std;
int main()
{
    cout << "35的8进制:" << std::oct << 35<< endl;  //oct 八进制
    cout << "35的10进制:" << std::dec <<-0b01110000000000000000000000000001<< endl;  //dec 十进制
    cout << "35的16进制:" << std::hex << 35 << endl;  //hex 十六进制
    cout << "35的2进制:" << bitset<17>(-49540) << endl; //<8>：表示保留8位输出
    getchar();//getchar有一个int型的返回值。当程序调用getchar时，程序就等着用户按键。
    //用户输入的字符被存放在键盘缓冲区中。直到用户按回车为止（回车字符也放在缓冲区中）。
    return 0;
}

