//5.6 try语句块和异常处理
//C++语言中，异常处理包括：
/*1.throw表达式（throw expression），
    异常检测部分使用throw表达式来表示它遇到了无法处理的问题。
    我们说throw引发（raise）了异常。
  2.try语句块（try block），异常处理部分使用try语句块处理异常。
    try语句块以关键字try开始，并以一个或多个catch子句（catch clause）结束。
    try语句块中代码抛出的异常通常会被某个catch子句处理。
    catch也被称作异常处理代码（exception handler）。
  3.一套异常类（exception class），
    用于在throw表达式和相关catch子句之间传递异常的具体信息。*/
//5.6.1 throw 表达式
/*1.程序的异常检测部分使用throw表达式引发一个异常。
    throw表达式包含关键字throw和紧跟其后的一个表达式，
    其中表达式的类型就是抛出的异常类型。紧跟分号，构成语句*/
//5.6.2 try 语句块
/*1.try 语句块语法形式：try {program-statement}
    catch(exception-declaration){handler-statements}
    catch(exception-declaration){handler-statements}//...
    catch子语句包括三部分：关键字catch、括号内一个（可能未命名的）对象的声明
    （称作异常声明，exception declaration）以及一个块。
    当选中了某个catch子句处理异常之后，执行与之对应的块。
    catch一旦完成，程序跳到try语句块最快一个catch子句之后的那条语句继续执行。
    try语句块中的program-statements组成程序的正常逻辑，
    可以包括声明在内的任意c++语句。
    块内声明的变量快外无法访问，特别是catch子句内无法访问。*/
//5.6.3 标准异常
/*1.exception头文件定义类最普通的异常类exception。它只报告异常的发生，不提供任何额外信息。
  2.stdexcept头文件定义类几种常用异常类。
  3.new头文件定义类bad_alloc异常类型。
  4.type_info头文件定义类bad_cast异常类型。*/

/*1.表 5.1：<stdexcept>定义的异常类
  exception          最常见的问题
  runtime_error      只有在运行时才能检测出的问题
  range_error        运行时错误：生成的结果超出了有意义的值域范围
  overflow_error     运行时错误：计算上溢
  underflow_error    运行时错误：计算下溢
  logic_error        程序逻辑错误
  domain_error       逻辑错误：参数对应的结果值不存在
  invalid_argument   逻辑错误：无效参数
  length_error       逻辑错误：试图创建一个超出该类型最大长度的对象
  out_of_range       逻辑错误：使用一个超出有效范围的值*/
/*2.我们只能以默认初始化的方式初始化exception、bad_alloc和bad_cast对象，
    不允许为这些对象提供初始值。
    其他异常类型的行为恰好相反：
    应该使用string对象或者C风格字符串初始化这些类型的对象，
    但不允许使用默认初始化的方式，必须提供初始值，
    初始值含有错误相关信息。
  3.异常类型只定义了一个名为what的成员函数，该函数没有任何参数，
    返回值是一个指向C风格字符串的const char*。
    what函数返回的C风格字符串的内容与异常对象的类型有关。
    如果异常类型有一个字符串初始值，则what返回该字符串。
    对无初始值的异常类型来说，what返回类型的内容由编译器决定。*/

#include <iostream>
#include <stdexcept>
#include "SalesItem.h"
using namespace std;

int main()
{
    SalesItem item1, item2;
    //cin >> item1 >> item2;
    //首先检查item1和item2是否表示同一种书籍
    /*if (item1.sameIsbn(item2))
    {
        cout << item1 + item2 << endl;
        return 0; //表示成功
    }
    else
    {
        cerr << "Data must refer to same ISBN" << endl;
        return -1;//表示失败
    }*/
    while (cin >> item1 >> item2)
    {
        try
        {
            //首先检查两条数据是否关于同一种书籍的
            if (!item1.sameIsbn(item2))
                throw runtime_error("Data must refer to same ISBN");
            //如果程序执行到这里，表示两个ISBN是相同的
            cout << item1 + item2 << endl;
            //执行添加两个SalesItem对象的代码
            //如果添加失败，代码抛出一个runtime_error异常
        }
        catch (runtime_error err)
        {
            //提醒用户两个ISBN必须一致，询问是否重新输入
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            if (!(cin >> c) || (c == 'n'))
                break; //跳出while循环
        }
    }
    return 0;
}
