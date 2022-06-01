//4.11 类型转换
//1.如果两种类型可以相互转换（conversion），那么它们是相互关联的。
//2.如果运算的对象类型不同，根据类型转换规则将运算对象类型统一后，在求值。
//3.无需程序员介入的，称作隐式转换（implicit conversion）。
//4.算术类型之间的隐式转换被设计得尽可能避免损失精度。
/*5.发生隐式转换的情形：
  1.在大多数表达式中，比int类型小的整型值首先提升为较大的整数类型。
  2.在条件中，非布尔值转换成布尔类型。
  3.在初始化过程中，初始值转换成变量的类型；
    在赋值语句中，右侧运算对象转换成左侧运算对象的类型。
  4.函数调用时也会发生类型转换*/

//4.11.1 算术转换（arithmetic conversion）
/*1.整型提升（integral promotion）
    1.小整数类型转换策成较大的整数类型
    bool、char、signed char、unsigned char、short和unsigned short等类型来说，
    只要它们所有可能的值都能存在int里，就会被提升成int类型；
    否则，提升成unsigned int类型。
    2.较大的char类型（wchar_t、char16_t、char32_t）提升成int、unsigned int、
    long、unsigned long、long long和unsigned long lomg中最小的一种类型*/
/*2.无符号类型的运算对象
    1.整数提升，提升后都是无符号或都是带符号的，小类型转换成大类型。
    2.提升后一个带符号，一个无符号，无符号类型不小于带符号类型*，
      带符号类型转换成无符号类型。
    3.带符号类型大于无符号类型，如果无符号类型所有值都能存在带符号类型中，
      无符号类型转换成带符号类型。
    4.如果不能，带符号类型转换成无符号类型。*/

//4.11.2 其他隐式类型转换
/*1.数组转换成指针：
    1.大多数表达式中，数组自动转换成指向数组首元素的指针。
    2.作为decltype的参数，&、sizeof及typeid等运算符的对象时，不发生转换。
    3.用引用来初始化数组，转换也不会发生。
    4.表达式中使用函数类型时会发生类似的指针转换。*/
/*2.指针的转换：
    0或者字面值nullptr转换成任意指针;
    指向任意非常量的指针能转换成void*;
    指向任意对象的指针能转换成const void*;
    在有继承关系的类型间还有另一种指针转换的方式。*/
/*3.转换成布尔类型
    指针或算术类型值为0，转换成false；否则转换成true。*/
/*4.转换成常量
    允许将指向非常量类型的指针转换成指向相应的常量类型的指针，对引用也是这样。
    相反，则不行。*/
/*5.类类型定义的转换
    类类型能定义由编译器自动执行的转换，不过编译器每次只能执行一种类类型的转换*/
//4.11.3 显式转换
//1.强制类型转换（cast），这种方法本质上是非常危险的，尽量避免强制类型转换。
/*2.命名的强制类型转换：cast-name<type>(expession)。
    1.static_cast 只要不包含底层const,都可以使用；
    对编译器无法执行的类型转换也非常有用。
    2.const_cast 只能改变运算对象的底层const。
    如果对象本身不是一个常量，使用强制类型转换获得写权限是合法的行为；
    如果对象是一个常量，使用const_cast执行写操作就会产生未定义的后果；
    const_cast能改变表达式的常量属性，但不能改变表达式的类型；
    const_cast常常用于有函数重载的上下文中。
    3.reinterpret_cast 用于进行各种不同类型的指针之间、
    不同类型的引用之间以及指针和能容纳指针的整数类型之间的转换。
    转换时，执行的是逐个比特复制的操作。
    reinterpret_cast本质上依赖于机器，
    想安全地使用reinterpret_cast必须对涉及的类型和和编译器实现转换的过程非常了解。
    4.dynamic_cast专门用于将多态基类的指针或引用强制转换为派生类的指针或引用，
    而且能够检查转换的安全性。对于不安全的指针转换，转换结果返回 NULL 指针。
    reinterpret_cast 可以将多态基类（包含虚函数的基类）的指针强制转换为派生类的指针，
    但是这种转换不检查安全性，即不检查转换后的指针是否确实指向一个派生类对象。*/
/*3.旧式的强制类型转换
    type(expr);//函数形式的强制类型转换；
    (type)expr;//C语言分割的强制类型转换；
    旧式强制类型转换可用2中的方式替换*/
#include <iostream>
using namespace std;

int main()
{
    //4.11
    int val = 3.541 + 3; //int-->double
    //4.11.1
    bool flag = true;
    char cval = 'a';
    short sval = -100;
    unsigned short usval = 100;
    int ival = -200;
    unsigned int uival = 200;
    long lval = -300;
    unsigned long ulval = 300;
    float fval = 3.14159;
    double dval = 3.14159265;
    cout << 3.14159L + cval << endl; //char-->int-->long double
    cout << dval + ival << endl;     //int-->double
    cout << dval + fval << endl;     //float-->double
    cout << (ival = dval) << endl;   //double-->int
    cout << (flag = dval) << endl;   //double-->bool
    cout << cval + fval << endl;     //char-->int-->float
    cout << sval + cval << endl;     //short-->int,char-->int
    cout << cval + lval << endl;     //char-->long
    cout << ival + ulval << endl;    //int-->unsigned long
    cout << usval + ival << endl;    //根据unsigned short和int所占空间大小提升
    cout << uival + lval << endl;    //根据unsigned int和long所占空间大小转换
    //4.11.2
    int ia[10];   //含有10个元素的数组
    int *ip = ia; //ia转换成指向数组首元素的指针

    int i;
    const int &j = i;  //非常量转换成const int的引用
    const int *p = &i; //非常量转换成const 的地址
    //int &r = j, *q = p;//错误，不允许const转换成非常量

    string s, t = "a value";              //字符串字面值转换成string类型
    cout << ((cin >> s) ? s : t) << endl; //条件运算符，把cin转换成bool值

    //4.11.3
    int m = 5, n = 3;
    double slope = m / n; //结果是1
    cout << slope << endl;
    //进行强制类型转换以便执行浮点数除法
    slope = static_cast<double>(m) / n; //结果是1.66667
    cout << slope << endl;

    double d = 123.0;
    void *vp = &d; //正确：任何非常量对象都能存入void*
    //将void*转换回初始的指针类型
    double *dp = static_cast<double *>(vp);
    cout << *dp << endl;

    char ch = 'b';
    const char *chp = &ch;
    char *chq = const_cast<char *>(chp);                   //去底层const
    cout << static_cast<string>(chp) << endl;              //const char *类型强制转换成string类型
    cout << reinterpret_cast<const string *>(chp) << endl; //const char*强行转换const string *类型
    cout << static_cast<int>(*chp) << endl;                //const char类型转换成int 类型
    cout << (*chq = 's') << endl;                          //给接引用赋值，也改变了ch的值
    cout << ch << endl;

    int in = 98, *inp = &in;
    char *pc = reinterpret_cast<char *>(inp);
    char *pch = (char *)inp;
    string str(pc);
    cout << str << endl;
    return 0;
}
/*
100.142
-196.858
6.28318
3
1
100.142
-3
-203
303
103
4294967196
^Z
a value
1
1.66667
123
b�n
0x62fe0f
98
s
s
b
*/
