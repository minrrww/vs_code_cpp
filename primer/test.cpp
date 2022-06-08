#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
#include <string>
using namespace std;
int main()
{
    string s("Hello world!");
    for (decltype(s.size()) i = 0; i < s.size(); ++i)
        cout << s[i] << endl;
}
