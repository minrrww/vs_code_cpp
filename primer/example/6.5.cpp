//6.5 特殊用途语言特性
//三种函数的语言特性：默认实参、内联函数和constexpr函数。
//6.5.1 默认实参
/*1.函数多次调用中被赋予一个相同的值，这个值称为默认实参（default argument）
  2.使用默认实参调用函数，只要在调用函数时省略该实参。
  默认实参负责填补函数调用缺少的尾部实参。
  3.默认实参声明，为没有默认值的形参添加默认实参，
  该形参右侧所有形参必须都有默认值。
  一个函数只声明一次，但多次声明时合法的。给定作用域中一个形参只能赋予一次默认实参。
  应该在函数声明中指定默认实参，并将声明放在合适的头文件中。
  4.默认实参初始值
  局部变量不能作为默认实参。只要表达式类型能转换成所需类型，就能作为默认实参。*/
//6.5.2 内联函数和constexpr函数
/*1.把规模较小的操作定义成函数有很多好处
  阅读理解函数调用比读懂等价的条件表达式容易得多。
  函数可以确保行为的统一，每次相关操作都保证按照同样的方式进行。
  如果需要修改，修改函数要比先找到等价表达式所有出现的地方再逐一修改更容易。
  函数可以被其他应用重复利用，省去程序员重新编写的代价。
  2.缺点，调用函数比求等价表达式要慢。
  3.内联函数可以避免函数调用的开销
  内联说明是向编译器发出的一个请求，编译器可以忽略这个请求。
  4.constexpr函数（constexpr function）
  是指用于常量表达式的函数。
  函数返回值类型及所有形参的类型都得是字面值类型。
  编译时，把函数的调用替换成其结果值。
  常被隐式指定为内联函数
  允许constexpr函数的返回值并非一个常量：
  //如果arg是常量表达式，则scale(arg)也是常量表达式
  constexpr size_t scale(size_t cnt){return new_sz()*cnt;}
  5.内联函数和constexpr函数可以多次定义，但多次定义必须完全一致。
  通常将内联函数和constexpr函数定义在头文件中。*/
//6.5.3 调试帮助
/*类似头文件保护的技术，以便有选择地执行调试代码。
基本思路：程序可以包含一些用于调试的代码，只在开发程序时使用，
程序发布时，先屏蔽掉调试代码。
用到两项预处理功能：assert和NDENUG
1.assert预处理宏
assert是一种预处理宏（perprocessor marco）。
预处理宏是一个预处理变量，类似内联函数。
assert用一个表达式作为它的条件：assert(expr);
对expr求值，值为假0，assert输出信息并终止程序的运行。
如果值为真非0，assert什么也不做。
assert宏定义在cassert中，预处理名字由预处理器管理，
可以直接使用预处理名字而无需提供using声明
宏名字必须唯一。含有cassert头文件的程序不能再定义名为assert的变量、函数或者其他实体。
2.NDENUG预处理变量
如果定义类NDRBUG，assert什么也不做。
默认情况下没有定义NDEBUG，从而assert将执行运行时检查。
用#define语句丁iNDEBUG，从而关闭调试状态。
很多编译器偷工命令行选项是我们可以定义预处理变量。
定义NDEBUG能避免检查各种条件所需的运行时开销。
编写自己的调试代码：
void print(string word, size_t threshold)
{
#ifndef NDEBUG
  //_ _func_ _事编译器定义的一个局部静态变量，用于存放函数的名字
  if (word.size() < threshold)
    cerr << "Error: " << _ _FILE_ _
         << " : in function "_ _func_ _
         << " at line " << _ _LINE_ _ << endl
         << "    Compiled on " << _ _DATE_ _
         << " at " << _ _TIME_ _ << endl
         << "    Word read was\"" << word
         << "\": Length too short" << endl;
#endif
  //...
}
  变量_ _func_ _输出当前调试函数的名字。是const char 的静态数组。
  _ _FILE_ _存放文件名的字符串字面值
  _ _LILE_ _存放当前行号的整型字面值
  _ _TIME_ _存放文件编译时间的字符串字面值
  _ _DATE_ _存放文件编译日期的字符串字面值
  */

#include <iostream>
using namespace std;
typedef string::size_type sz;
char backgrnd = '#';
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ')
{
  string h = "Hight: " + to_string(ht);
  string w = "Wight: " + to_string(wid);
  string b = "Backround: " + to_string(backgrnd);
  return h + "," + w + "," + b;
}
inline const string *const shortString(const string *s1, const string *s2)
{
  return s1->size() < s2->size() ? s1 : s2;
}
inline string *shortString(string *s1, string *s2)
{
  auto *str = shortString(const_cast<const string *>(s1), const_cast<const string *>(s2));
  return const_cast<string *>(str);
}
inline const string &shortString(const string &s1, const string &s2)
{
  return s1.size() < s2.size() ? s1 : s2;
}
inline string &shortString(string &s1, string &s2)
{
  auto &str = shortString(const_cast<const string &>(s1), const_cast<const string &>(s2));
  return const_cast<string &>(str);
}
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz(); //正确：foo是一个常量表达式
//如果arg是常量表达式，则scale(arg)也是常量表达式
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
int main()
{

  struct
  {
  public:
    void f()
    {
      backgrnd = '*';           //改变静态变量的值
      sz ht = 100, wid = 120;   //重新声明可以屏蔽外部变量，与默认实参无关
      string window = screen(); //调用默认实参
      cout << window << endl;
      cout << screen(ht, wid, backgrnd) << endl; //与调用有关
    }
  } inner;
  string window;
  window = screen();             //等价于screen(24,80,' ')
  window = screen(66);           //等价于screen(66,80,' ')
  window = screen(66, 256);      //等价于screen(66,256,' ')
  window = screen(66, 256, '#'); //等价于screen(66,256,'#')
  cout << window << endl;
  inner.f(); //普通调用不影响外层window的值
  cout << window << endl;

  string s1 = "Hello world!", s2 = "1234567890";
  string *const str1 = &s1, *const str2 = &s2;
  cout << shortString(s1, s2) << endl;
  cout << *shortString(str1, str2) << endl;

  cout << scale(2) << endl; //scale(2)是常量表达式
  int i = 2;
  cout << scale(i) << endl; //scale(i)不是常量表达式，看编译器
  return 0;
}
