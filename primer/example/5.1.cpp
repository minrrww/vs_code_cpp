//5.1 简单语句
/*1.表达式语句（expression statement）:表达式;//执行表达式，并丢弃掉求值结果。
    表达式语句比较普遍的是求值时附带其他效果，给变量赋新值或输出了结果。*/
/*2.空语句（null statement）：;//空语句，语法上需要一条语句，但逻辑上不需要;
    空语句在if,while条件后面可能完全改变程序员的初衷。*/
/*3.复合语句（compound statement）：花括号括起来的语句或声明的序列，也叫块（block）。
    块不以分号结束。
    空块等价于空语句*/
#include <iostream>
using namespace std;
int main()
{
    //1.表达式语句
    int ival = 0, sum = 0;
    ival + 5;             //没用的表达式语句
    cout << ival << endl; //有用的表达式语句
    //2.空语句
    //重复读入数据直至到达文件末尾或某次输入的值等于sought
    int s, sought = 0;
    while (cin >> s && s != sought)
        ; //空语句
    //3.复合语句（块）
    while (ival <= 10)
    {
        sum += ival; //把sum+ival的值赋给sum
        ++ival;      //给ival加1
    }
    cout << sum << " " << ival;
    return 0;
}
/*
0
0
55 11
*/
