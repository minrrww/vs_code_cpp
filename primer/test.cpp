#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
#include <string>
using namespace std;
int i = 100;
constexpr int j = 100;
int main()
{
    int a1 = 100, &b1 = a1, *c1 = &a1;
    const int a2 = 100, &b2 = a2, *c2 = &a2;
    const int a3 = 100, &b3 = a3, *const c3 = &a3;
    int a4 = 100, a5 = a4;
    const int &b4 = a4, *c4 = &a4, &d4 = b4, *e4 = c4, &b5 = a5, *const c5 = &a5;
    // int &d5 = b5, *e5 = c5;//底层const属性要一直
    const int a6 = 100;
    // int &b6 = a6, *c6 = &a6;
    //错误，a6是常量，b6，c6与却能改变先关联对象的值，矛盾
    /*
    总结：
    1.当涉及给引用或指针初始化时，看能否改变关联对象的值
    2.引用不是对象
    3.声明引用的const是底层const,声明指针的const有顶层const，也有底层const
    4.执行拷贝操作时，顶层const不受影响，底层const则必须类型一致
    */
    constexpr int &k = i;        //绑定固定位置的变量
    const constexpr int &l = i;  //绑定固定位置的变量,其实与上面一句有区别
    const constexpr int &m = j;  //绑定固定位置常量
    const constexpr int *n = &j; //指向固定位置常量，n是常量指针
    /*
    总结：
    1.constexpr只能是顶层const，constexpr只能常量表达式或constexpr函数初始化
    2.constexpr指针只能是空指针或固定位置对象，引用只能绑定固定位置对象
    */
    typedef const char *pstring;     // pstring与char *同义,是指针类型
    pstring cstr = 0;    // cstr是const pstring类型的对象，即指向char类型对象的常量指针，同char *const cstr=0
    pstring *ps = &cstr; // ps是指针，指向的对象是指针，指向的对象是指向char类型对象的常量指针
    /*
    总结，注意用别名与用类型名声明对象相同
    */
}
