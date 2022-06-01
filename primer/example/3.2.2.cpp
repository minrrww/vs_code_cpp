//example-3.2.2-.cpp
#include <iostream>
using namespace std;
int main()
{
    string s, s1, s2;        //默认初始化，s是一个空字符串
    cin >> s1;               //在cin流对象中读取值，赋给s,字符以空格为界，返回cin
    cout << s1 << endl;      //将s写到cout流对象中，返回cout
    while (getline(cin, s2)) //在cin流对象中读取一行赋给s,返回cin,s2中不包括换行符
    {
        bool b = s2.empty();        //s为空返回true,否则返回false
        auto i = s2.size();         //返回s中字符的个数,i为size_type类型的对象
        char c = s2[s2.size() - 1]; //返回s最后一个字符
        cout << s2 << b << i << c << endl;
    }
    s = s1 + s2; //连接
    cout << s << endl;
    //利用字符在字典中的顺序进行比较，且对字母大小写敏感
    cout << (s1 < s2) << (s1 > s2) << (s1 <= s2) << (s1 >= s2) << endl;
    s1 = s2; //用s2副本代替s1原来的值
    cout << s1 << endl;
    cout << s2 << endl;
    if (s1 == s2)
        cout << (s1 != s2) << endl;
    return 0;
}
/*
abc abc
abc
 abc04c
abc abc
0101
 abc
 abc
0
 */
