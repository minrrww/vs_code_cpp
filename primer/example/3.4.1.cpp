//example-3.4.1-.cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s("some string");
    if (s.begin() != s.end()) //确保s非空
    {
        auto it = s.begin(); //it表示s的第一个字符
        *it = toupper(*it);  //将当前字符改写成大写形式
    }
    cout << s << endl;
    //依次处理s的字符，直至处理完全部字符或遇到空白
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) //!=与<迭代器与下标的区别
        *it = toupper(*it);                                         //将当前字符改写成大写形式
    cout << s << endl;
    //依次处理text的元素，直至处理完全部元素或遇到为空的元素
    vector<string> text = {"Hello world"," ","Some string"};
    for (decltype(text.cbegin()) it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it<< endl;//只读未写可以用cbegin和cend
    return 0;
}
/*
Some string
SOME string
Hello world

Some string
*/
