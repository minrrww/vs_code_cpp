#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
#include <string>
using namespace std;

int main()
{
    string s1{15, 'b'},s2(s1);         // s7的内容是b;
    int i = 6;
    string s3( i+"" );
}
