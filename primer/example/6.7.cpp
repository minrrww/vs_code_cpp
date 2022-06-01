//6.7 函数指针
/*1.函数指针指向的是函数而非对象。
函数的指针指向某种特定类型。
函数的类型由它的返回类型和形参类型共同决定，与函数名无关。
想要声明一个可以指向该函数的指针，只需要用指针替换函数名即可
2.使用函数指针
当我们把函数名作为一个值食用时，该函数自动地转换成指针。
还能直接使用指向函数的指针调用该函数，无需提前解引用指针
指向不同的函数的指针，不存在转换规则。
但可以为函数指针赋一个nullptr或者值为0的整型常量表达式，表示没有指向任何一个函数。
3.重载寒素的指针
当我们重载函数时，上下文必须清晰地界定到应该选用哪个函数。
如果定义了指向重载函数的指针，编译器通过指针类型决定选用哪个函数。
指针类型必须和重载函数中的某一个精准匹配。
4.函数指针形参
和数组类似，虽然不能定义函数类型的形参，但是形参可以是指向函数的指针。
此时函数形参看起来是函数类型，实际上却是当成指针使用。
可以直接把函数作为实参使用，此时它会自动转换成指针。
直接使用函数指针类型显得冗长而繁琐。
类型别名和decltype能让我们简化使用函数指针的代码。
decltype返回函数类型，不会自动转换成指针类型。
5.返回指向函数的指针
不能返回函数，但是能返回指向函数的指针。
必须把返回类型写成指针形式，编译器不会自动将函数返回类型当成对应的指针类型处理
声明一个返回函数指针的函数，最简单的办法是使用类型别名。
和函数类型的形参不同，返回类型必须显式的转换成指针。
可以使用尾置返回类型的方式。
6.将auto和decltype用于函数指针类型
*/

#include <iostream>

using namespace std;
//比较两个string对象的长度
//函数的类型时bool(cosnt string &,cosnt string &)
bool lengthCompare(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}
string::size_type sumLength(const string &s1, const string &s2)
{
    return s1.size() + s2.size();
}
string::size_type largerLength(const string &, const string &);
//根据其形参的取值，getFcn函数返回指向sumLength或者largerLength的指针
decltype(sumLength) *getFcn(const string &);
bool cstringCompare(const char *, const char *);
void ff(int *);
void ff(unsigned int);

//Func和Func2是函数类型
typedef bool Func(const string &, const string &);
typedef decltype(lengthCompare) Func2; //等价的类型
//Funcp和Funcp2是指向函数的指针
typedef bool (*Funcp)(const string &, const string &);
typedef decltype(lengthCompare) *Funcp2; //等价的类型

//第三个形参是函数类型，它会自动地转换成函数的指针
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
//等价的声明：显式地将形参定义成指向函数的指针
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &))
{
    cout << s1 << s2 << *pf << endl;
}
//等价的声明：使用了类型别名
void useBigger(const string &, const string &, Func); //编译器自动将类型转换为指针
void useBigger(const string &, const string &, Funcp2);

using F = int(int *, int);      //F是函数类型，不是指针
using PF = int (*)(int *, int); //PF是指针类型
PF f1(int);                     //PF是指向函数的指针，f1返回指向函数的指针
//F f1(int);//F是函数类型，f1不能返回函数类型
F *f1(int); //显式地指定返回类型时指向函数的指针
//直接声明
/*  f1有形参列表，是个函数，前面有*，返回的是指针，
返回类型有形参列表，返回指向函数的指针*/
int (*f1(int))(int *, int);
//尾置返回类型方式
auto f1(int) -> int (*)(int *, int);
int main()
{
    //pf指向一个函数，该函数的参数是两个const string的引用，返回值是bool类型
    bool (*pf)(const string &, const string &); //未初始化
    //bool *pf(const string &,const string &);//返回值是bool *类型的函数
    pf = lengthCompare;                          //pf指向名为lengthCompare的函数
    pf = &lengthCompare;                         //等价的赋值语句：取地址符是可选的
    bool b1 = pf("Hello", "goodbye");            //调用lengthCompare函数
    bool b2 = (*pf)("Hello", "goodbye");         //一个等价的调用
    bool b3 = lengthCompare("Hello", "goodbye"); //另一个等价的调用
    pf = 0;                                      //pf不指向任何函数
    //pf = sumLength;                              //返回类型不匹配
    //pf = cstringCompare;                         //形参类型不匹配
    pf = lengthCompare;             //函数和指针的类型精确匹配
    void (*pf1)(unsigned int) = ff; //pf1指向ff(unsigned int)
    //void (*pf2)(int) = ff;          //没有任何一个ff与该形参列表匹配
    //double (*pf3)(int *) = ff;      //ff和pf3的返回类型不匹配

    string s1 = "Hello", s2 = "goodbye";
    //自动将函数lengthCompare转换成指向该函数的指针
    useBigger(s1, s2, lengthCompare);

    return 0;
}
