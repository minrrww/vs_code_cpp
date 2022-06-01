//4.7 条件运算符
/*1.当条件运算符的两个表达式都是左值或者都能转换成同一种左值类型时，
    运算结果是左值；否则运算结果是右值。*/
/*2.允许条件运算符的内部嵌套另外一个条件运算符。*/
/*3.条件运算符满足右结合律。*/
/*4.条件运算符优先级非常低，被嵌套时通常加括号。*/
#include <iostream>
#include <string>
using namespace std;
struct student
{
    string name;
    string num;
    unsigned grade;
};
int main()
{
    student s1 = {"Lilei", "20052958", 91};
    student s2 = {"Hanmeimei", "20052961", 59};
    //嵌套条件运算符
    cout << ((s1.grade > 90)   ? "hign pass"s
             : (s1.grade < 60) ? "fail": "pass");
    cout << endl;
    //在输出表达式中食用条件运算符
    cout << ((s2.grade < 60) ? "fail" : "pass");
    cout << endl;
    cout << (s2.grade < 60) ? "fail" : "pass";
    cout << endl;
    //cout << s2.grade < 60 ? "fail" : "pass";//错误
    return 0;
}
/*
hign pass
fail
1
*/
