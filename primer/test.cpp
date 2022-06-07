#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
#include <string>
using namespace std;

int main()
{
    string line; //每次读入一整行，直至到达文件末尾
    getline(cin, line);
    for (char s : line)
        cout << s << endl; // line中不包含换行符，getline函数返回的换行符被丢弃了
}
