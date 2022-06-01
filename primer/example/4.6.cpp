//4.6 成员访问运算符
#include <iostream>
using namespace std;
int main()
{
    string s1 = "a string", *p = &s1;
    auto n = s1.size(); //运行string对象s1的size成员
    //因为解引用运算符的优先级低于点运算符，所以执行解引用运算的子表达式两端必须加上括号
    //*p.size();//错误p是指针，没有size()成员
    n = (*p).size(); //运行p所指对象的size成员
    cout << n << endl;
    n = p->size();   //等价于(*p).size()
    cout << n << endl;
    return 0;
    //箭头运算符作用于一个指针类型的运算对象，结果是一个左值
    //点运算符如果成员所属对象是左值，那么结果是左值；反之，如果成员所属的对象是右值，那么结果是右值
}
/*
8
8
*/
