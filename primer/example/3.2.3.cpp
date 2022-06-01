#include <iostream>
using namespace std;
int main()
{
    string s("Hello World!!!");
    //punct_cnt的类型和s.size的返回类型一样；
    decltype(s.size()) punct_cnt = 0;
    for (auto &c : s) //s中的每一个字符(c是引用，复制将改变s中的字符)
    {
        c = toupper(c);  //c是引用，复制将改变s中的字符
        if (ispunct(c))  //如果该字符是标点符号
            ++punct_cnt; //将标点符号的计数值加1
    }
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
    string s1("some string");
    if (!s1.empty())            //确保s[0]位置有字符
        s1[0] = toupper(s1[0]); //第一字符大写
    cout << s1 << endl;
    //依次处理s中的字符直到处理完全部字符或遇到一个空白
    for (decltype(s1.size()) index = 0; index < s1.size() && !isspace(s1[index]); ++index)
        s1[index] = toupper(s1[index]); //当前字符大写
    cout << s1 << endl;
    return 0;
}
/*
3 punctuation characters in HELLO WORLD!!!
Some string
SOME string
*/
