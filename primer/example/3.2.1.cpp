//example-3.2.1-.cpp
#include <iostream>
using namespace std;
int main()
{
    string s1;                  //默认初始化，s1是一个空字符串
    string s2 = s1;             //s2是s1的副本
    string s3(s2);              //s3是s1的副本
    string s4 = "hiya";         //s4是改字符串字面值（除最后的空字符外）的副本
    string s5("hiya");          //s5是改字符串字面值（除最后的空字符外）的副本
    string s6(10, 'c');         //s6的内容是cccccccccc;
    string s7{15, 'b'};         //s7的内容是b;
    string s8 = {"15", "cdf"};  //s8的内容是15;
    string s9{"15", "cdf"};     //s9的内容是15;
    string s10 = string("ABC"); //s9的内容是ABC;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    cout << s8 << endl;
    cout << s9 << endl;
    cout << s10 << endl;
    return 0;
}
/*



hiya
hiya
cccccccccc
b
15
15
ABC
 */
