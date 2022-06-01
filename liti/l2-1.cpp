//例2——1.cpp
#include <iostream>//#include预处理指令，cout,<<等在iostream文件中声明。
using namespace std;//命名空间。
int main()//主函数，int表示主函数返回值类型
{
    cout <<"Hello!" << endl;
    cout <<"Welcome to c++!" << endl;
    getchar();//getchar有一个int型的返回值。当程序调用getchar时，程序就等着用户按键。
    //用户输入的字符被存放在键盘缓冲区中。直到用户按回车为止（回车字符也放在缓冲区中）。
    system("pause");//system("PAUSE")  是暂停的意思，等待用户信号；不然控制台程序会一闪即过，
    //你来不及看到执行结果。
    return 0;
}
