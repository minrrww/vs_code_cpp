//6.6 函数匹配
/*1.在大多数情况下，我们容易确定某次调用应该选用哪个重载函数。
  2.当几个重载函数形参数量相同以及某些形参的类型可以由其他类型转换得来。
  3.确定候选函数和可行函数
  第一步，选定本次调用对应的重载函数集，集合中的函数称为候选函数（candidate function）。
  候选函数特征：
  与被掉函数同名，声明在调用点可见。
  第二步，考察本次调用提供的实参，然后选出能被这组实参调用的函数。
  选出的函数称为可行函数（viable function）。可行函数两个特征：
  形参数量与本次调用提供的实参数量相等，实参类型与对应的形参类型形同，或者能转换成形参的类型。
  如果函数含有默认实参，则调用该函数时，传入的实参数量可能少于实际使用的实参数量。
  如果没找到可行函数，编译器讲报告无匹配函数的错误。
  第三步，寻找最佳匹配（如果有的话），选用与本次调用最匹配的函数。
  实参类型与形参类型越接近匹配越好。
  4.含有多个形参的函数匹配满足条件：
  该函数每个实参的匹配都不劣于其他可行函数需要对匹配
  至少有一个实参的匹配由于其他可行函数提供的匹配*/
//6.6.1 实参类型的转换
/*1.实参类型到形参类型的转换分几个等级，如下：
    （1）精准匹配，包括以下情况：
    实参类型和形参类型相同
    实参从数组类型或函数类型转换成对应的指针类型
    向实参添加顶层const或从实参中删除顶层const
    （2）通过const转换实现匹配
    （3）通过类型提升实现的匹配
    （4）通过算术类型转换实现的匹配
    （5）通过类类型转换实现的匹配
  2.需要算术提升和算术类型转换的匹配
  一般很小的数也会提升为int，而不是short
  3.函数匹配和const实参
  const 实参只能匹配const 形参，
  非const实参能匹配const形参，但优先非const形参
  指针也类似*/

#include <iostream>

using namespace std;
inline void f()
{
    cout << "无形参" << endl;
}
inline void ff(long s) { cout << s << endl; }
inline void ff(float i) { cout << i << endl; }
inline void f(short s) { cout << s << endl; }
inline void f(int i) { cout << i << endl; }
inline void f(int i, int j) { cout << i << " " << j << endl; }
inline void f(double b, double d = 3.14) { cout << b << " " << d << endl; }
inline const string &shortString(const string &s1, const string &s2)
{
    return s1.size() < s2.size() ? s1 : s2;
}
inline string &shortString(string &s1, string &s2)
{
    auto &str = shortString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(str);
}
//形参为引用和普通变量函数能重载，但出现二义性。
/*inline const string shortString(const string s1, const string s2)
{
    return s1.size() < s2.size() ? s1 : s2;
}*/
int main()
{
    short s = 7;
    f();
    f(5.6);  //调用void f(double, double)
    f(5);    //调用void f(int)
    f(5, 4); //调用void f(int,int)
    f(s);    //调用void f(short)
    f('a');  //调用void f(int)
    ff(3.14f);
    //ff(3.14);//有二义性，即能转换long,又能转换float
    //f(5, 2.3);//有二义性
    const string s1 = "Hello world!",
                 s2 = "0123456789";
    string str1 = "Hello", str2 = "0123456";
    cout << shortString(s1, s2) << endl;     //选择形参时常量的函数
    cout << shortString(str1, str2) << endl; //都可以，但选择不用转换的函数
    //复习引用与指针的区别和联系
    //const变量的引用可以绑定const变量、普通变量和字面值
    int i = 1;
    const int ic = 2, &icr = ic, &icr1 = 3, icr2 = i;
    //普通变量的引用可以绑定普通变量，不能绑定const变量和字面值
    int &ir = i;
    //int &ir1 = ic;
    //int &ir2 = 4;
    //不能通过给const变量的引用赋值改变它绑定的对象
    //icr = i;
    //icr1 = ic;
    //可以通过给普通变量的引用赋值改变它绑定的对象
    ir = ic;
    ir = 3;
    ir = icr1;
    //指向const变量的指针可以指向const变量、普通变量
    const int *icp = &ic, *icp1 = &i;
    //可以通过取地址符赋值给const变量的指针，但不能给常量取地址
    icp = &i;
    icp1 = &ic;
    //icp = &7;
    //指向普通变量的指针可以指向普通变量，不能指向const变量，
    int *ip = &i;
    //int *ip1 = &ic;
    //可以通过取普通变量或其引用地址赋值给普通指针，不能取const变量地址赋值
    ip = &ir;
    ip = &i;
    //ip = &ic;

    double d = 5.5;
    const double cd = 6.6;
    double *const dcp = &d; //顶层const：指针本身是常量，可以通过给解引用赋值改变指向的对象，自身不变,不能指向常量
    *dcp = 7.7;
    *dcp = cd;
    //dcp = &cd;
    const double *cdp = &cd; //底层const：指向常量的指针，不能通过给解引用赋值改变指向的对象，指针本身可以变,可指向常量和变量
    cdp = &cd;
    //*cdp = 8.8;
    const double *const cdcp = &d; //是底层const也是顶层const：指向常量的指针本身是常量指针，自身不能改变，指向的对象也不能改变,可指向常量和变量
    //cdcp = &d;
    //*cdcp = 9.9;
    return 0;
}
