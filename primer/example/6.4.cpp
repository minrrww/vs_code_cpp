//6.4函数重载
//同一作用域内的几个函数名字信啊通但形参列表不同，
//称为重载（overloaded）函数
/*1.定义重载函数
  创建几个不同的函数分别根据名字、电话、账户号码等信息查找记录。
  Record lookup(const Account&);//根据Account查找记录
  Record lookup(const Phone&);//根据Phone查找记录
  Record lookup(const Name&);//根据Name查找记录
  Account acct;
  Phone phone;
  Record r1=lookup(acct);//调用接受Account的版本
  Record r2=lookup(phone);//调用接受Phone的版本
  不允许两个函数除了返回类型外其他所有的要素都相同。
  2.判断两个形参的类型是否相异。
  有时候两个形参列表看起来不一样，实际相同：
  //每队声明的是同一个函数
  Record lookup(const Account &acct);
  Record lookup(const Account &);//省略了形参的名字

  typedef Phone Telno;
  Record lookup(const Phone&);
  Record lookup(const Telno&);//Telno和Phone的类型相同
  3.重载和const形参
  顶层const不影响传入函数的对象。
  一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来
  Record lookup(Phone);
  Record lookuo(const Phone);//重复声明了Record lookup(Phone)
  Record lookup(&Phone);以及Record lookup(const &Phone);与上面两个声明具有二义性，但不同

  Record lookup(Phone *);
  Record lookup(Phone *const);//重复声明了Record lookup(Phone *)

  //对于接受引用或指针的函数来说，对象是常量还是非常量对应的形参不同
  //定义类4个独立的重载函数
  Record lookup(Account&);//函数作用于Account的引用
  Record lookup(const Account &);//新函数，作用于常量的引用
  Record lookup(Account *);//新函数，作用于指向Account的指针
  Record lookup(const Account *);//新函数，作用域指向常量的指针

  最好只重载哪些确实非常相似的操作。

  4.const_cast和重载
  5.调用重载的函数
  函数匹配（function matching）是指一个过程，
  过程中把函数调用与一组重载函数中的某一个关联起来，
  函数匹配也叫重载确定（overload resolution）。
  最佳匹配（best match）
  无匹配（no match）
  二义性调用（ambiguous call)*/
//6.4.1 重载与作用域
/*1.在不同的作用域中无法重载函数名。*/
#include <iostream>
#include <cstring>
using namespace std;
void print(const char cp[])
{
    if (cp)                //若cp不是一个空指针
        while (*cp)        //只要指针所指的字符不是空字符
            cout << *cp++; //输出当前字符并将指针向前移动一个位置
    cout << endl;
}
void print(const int *beg, const int *end)
{
    for (beg; beg != end; ++beg)
        cout << *beg << " ";
    cout << endl;
}
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << " ";
    cout << endl;
}
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}
string read()
{
    string read = "read";
    return read;
}
void print(const string &str)
{
    for (auto s : str)
        cout << s;
    cout << endl;
}
void print(double d) { cout << d << endl; } //重载print函数
void print(int i) { cout << i << endl; }    //重载print函数
void fooBar(int ival)
{
    //bool read=false;//新作用域：隐藏了外层read
    string s = read();
    //不好的习惯，局部作用域中声明函数不是一个好的选择
    //void print(int);//新作用域，隐藏了之前的print
    print(s);         //调用print(const string &)
    print("Value: "); //调用print(const char *)
    print(ival);      //调用print(int)
    print(3.14);      //调用print(double)
}
int main()
{
    int j[] = {
        0,
        13,
        4,
        6,
        6};
    print("Hello World");        //调用void print(const char *cp)
    print(j, end(j) - begin(j)); //调用void print(const int ia[], size_t size)
    print(begin(j), end(j));     //调用void print(const int *beg, const int *end)
    int ival = 4;
    fooBar(ival);
    return 0;
}
