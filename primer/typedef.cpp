#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    char a = '57';
    char *p = &a;
    const char a1 = '63';
    typedef char *pstring;  // pstring与char *同义,是指针类型

    const pstring cstr = p; // cstr是const pstring类型的对象，即指向char类型对象的常量指针，同char *const cstr=0
    const pstring *ps=&p;      // ps是指针，指向的对象是指针，指向的对象是指向char类型对象的常量指针


    const char *p1 =&a1;
    pstring *cstr1 = &p; //pstring *cstr1 = &p1;错误，p1指向的对象是常量，pstring *cstr1是顶层const
    return 0;
}
