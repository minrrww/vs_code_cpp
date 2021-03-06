# <p align="center">primer学习笔记</p>

## 第一章 开始
### 1.1 编写一个简单的C++程序
- C++程序包含一个或多个函数(function)，其中一个必须命名为main。
- 一个函数包括四部分：
   - 返回类型 (return type)
   - 函数名 (function name)
   - 形参列表 (parameter list)
   - 函数体 (function body)
```cpp
int main()
{
    return 0;
}
//返回类型int，函数名main，形参列表()，函数体{}
```
#### 1.1.1 编译、运行程序
##### 程序源文件命名约定
- 常见源文件后缀：.cc .cxx .cpp .cp .C

##### 从命令行运行编译器
- 略，有机会再学习
### 1.2 初识输入输出
- iostream库
  - istream 输入流类型
  - ostream 输出流类型
##### 标准输入输出对象
- cin 标准输入(standard input)
- cout 标准输出 (standard output)
- cerr 标准错误 (standard error) 输出警告和错误信息
- clog 一般信息 输出程序运行时的一般信息
##### 一个使用IO库的程序
```cpp
#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
int main()
{
    std::cout << "Enter two numbers:" << std::endl; //提示用户输入两个数
    int v1 = 0, v2 = 0;                             //保存我们读入的输入数据的变量
    std::cin >> v1 >> v2;                           //读取输入数据
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
```
##### 向流写入数据
- <<运算符（<<operator）输出运算符。
  - 将右侧运算对象的值写到左侧运算对象表示的输出流,输出运算符可以连接
- endl操纵符：结束当前行，并将设备关联的缓冲区中的内容刷到设备中
#####  使用标准库中的名字
- 命名空间名::对象名
  - std::cout
  - std::cin
  - std::endl
##### 从流读取数据
- \>>运算符（>>operator）输入运算符。
  - 从左侧运算对象所指定的输入流读取数据，存入右侧运算对象中,输入运算符可以连接
##### 完成程序（略）
### 1.3 注释
#####  C++注释种类
- 双斜杠//和注释界定符/* */
##### 注释界定符不能嵌套
### 1.4 控制流
#### 1.4.1 while语句
- while statement 重复执行直至特定条件为假。循环体会执行零次或多次，依赖于循环条件求值结果。
```cpp
int sum = 0, val = 1;
while (val <= 10) //重复执行循环体，直至val大于10
{
    sum += val; //将sum+val赋值给sum
    ++val;      //将val+1赋值给val
}
```
#### 1.4.2 for 语句
- for statement 提供重复执行能力。通常用来将一个计算反复执行指定次数。
```cpp
int sum = 0;
for (int val = 1; val <= 10; ++val) //从1加到10
{
    sum += val; //将sum+val赋值给sum
}
```
#### 1.4.3 读取数量不定的输入数据
```cpp
int sum = 0, value = 0;
while (cin >> value)
    sum += value; //将sum+val赋值给sum
// windows系统文件结束符ctrl+z，enter;linux系统文件结束符ctrl+d
//返回的cin对象无效指遇到文件结束符（end-of-file）或无效输入
```
##### *编译器检查程序错误*
- *语法错误（syntax error）*
- *类型错误（type error）*
- *声明错误（declaration error）*
  - *每个名字都要先声明后使用*
#### 1.4.4 if 语句
- if statement 根据一个特定条件的值进行条件执行的语句。如果条件为真，执行if语句体。否则，执行else语句体（如果存在的话）。
```cpp
int currVal = 0, val = 0; // currVal是我们正在统计的数；我们将读入的新值存入val
//读取第一个数，并确保实有数据可以处理
if (cin >> currVal)
{
    int cnt = 1; //保存我们正在处理的当前值的个数
    while (cin >> val)
    {                       //读取剩余的数
        if (val == currVal) //如果值相同
            ++cnt;          // cnt自加1
        else
        { //否则，打印前一个值得个数
            cout << currVal << " occurs "
                 << cnt << " times" << endl;
            currVal = val; //记住新值
            cnt = 1;       //重置计数器
        }
    } // while循环在这里结束
    //记住打印文件中最后一个值得个数
    cout << currVal << " occurs "
         << cnt << " times" << endl;
} //最外层的if语句在这里结束
```
### 1.5 类简介
#### 1.5.1 Sales_item类
##### 读写Sales_item
##### Sales_item对象的加法
```cpp
#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item book1; //声明变量，并调用无参数构造函数
    //读入ISBN号，售出的册数以及销售价格
    cin >> book1;
    Sales_item book2 = Sales_item(); //调用无参构造函数
    //读入ISBN号，售出的册数以及销售价格
    cin >> book2;
    Sales_item book3("0-201-70353-X");       //调用一个参数构造函数
    Sales_item book4("0-201-70353-X", 2);    //调用二个参数构造函数
    Sales_item book5("0-201-70353-X", 2, 3); //调用三个参数构造函数
    Sales_item book6 = Sales_item(cin);       //读入ISBN号，售出的册数以及销售价格
    Sales_item book7();                      //声明函数，而不是调用无参构造函数
    //写出ISBN号，售出的册数、总销售额以及平均价格
    cout << book6 + book1 + book2 + book3 + book4 + book5 + book7() << endl;
    return 0;
}
Sales_item book7()
{
    Sales_item book;
    cin >> book;
    return book;
}
```
```cpp
//Sales_item.h
#ifndef Sales_item_H
#define Sales_item_H
#include <iostream>
#include <string>
using namespace std;
class Sales_item
{
private:                //私有数据成员
    string isbn;        //书的ISBN号
    unsigned unitsSold; //售出数量（本）
    double revenue;     //销售总价
public:                 //外部接口
                        //带默认值的构造函数，相当于4次重载:无参数，1参数，2参数，3参数
    Sales_item(string isbn = "", unsigned unitsSold = 0, double price = 0.0)
        : isbn(isbn), unitsSold(unitsSold)
    {
        revenue = price * unitsSold;
    }
    Sales_item(istream &is) { is >> *this; }                             //重载构造函数，用构造函数读入输入流
    Sales_item &operator+=(const Sales_item &s);                          //重载+=运算符
    friend istream &operator>>(istream &in, Sales_item &s);              //用友元函数重载>>运算符
    friend ostream &operator<<(ostream &is, const Sales_item &s);        //用友元函数重载<<运算符
    friend bool operator==(const Sales_item &lhs, const Sales_item &rhs); //友元函数可以访问私有数据成员
    double avgPrice() const                                             //求平均售价
    {
        if (unitsSold) //如果数量不为0，返回平均值
            return revenue / unitsSold;
        else //如果数量为0,返回0.0
            return 0.0;
    }
    bool sameIsbn(const Sales_item &s) //比较ISBN是否相等
    {
        return isbn == s.isbn;
    }
};
Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs); //声明重载+运算符
istream &operator>>(istream &in, Sales_item &s)                   //实现重载>>运算符，返回左值，返回类型使用引用
{
    double price = 0;                     //定义单价
    in >> s.isbn >> s.unitsSold >> price; //输入流ISBN，数量，单价
    if (in)                               //如果输入流有效，计算总价
        s.revenue = s.unitsSold * price;
    else //否则，将无参数构造函数赋值给s
        s = Sales_item();
    return in; //返回左值
}
ostream &operator<<(ostream &is, const Sales_item &s) //实现重载<<运算符，返回左值，返回类型使用引用
{
    is << s.isbn << "\t" << s.unitsSold << "\t" << s.revenue << "\t" << s.avgPrice(); //输出几个值
    return is;                                                                        //返回左值
}
bool operator==(const Sales_item &lhs, const Sales_item &rhs) //声明并实现重载==运算符
{                                                           //全等为真，否则为假
    return lhs.unitsSold == rhs.unitsSold && lhs.isbn == rhs.isbn && lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_item &lhs, const Sales_item &rhs) //声明并实现重载!=运算符
{
    return !(lhs == rhs); //利用重载的==运算符
}
Sales_item &Sales_item::operator+=(const Sales_item &s) //实现重载+=运算符
{
    unitsSold += s.unitsSold;
    revenue += s.revenue;
    return *this; //返回左值
}
Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs) //实现重载+运算符
{
    Sales_item ret(lhs); //利用构造函数创建对象
    return ret += rhs;  //调用重载的+=运算符
}
#endif
```
#### 1.5.2 初识成员函数
##### 什么是成员函数？
```c++
#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item book1, book2; //声明变量，并调用无参数构造函数
    //读入ISBN号，售出的册数以及销售价格
    cin >> book1 >> book2;
    //检查是否是相同书籍
    if (book1.sameIsbn(book2)) //调用samIsbn函数
    {
        cout << book1 + book2 << endl;
        return 0; //表示成功
    }
    else
    {
        cerr << "Data must refer to same ISBN" << endl;
        return -1; //表示失败
    }
}
```
### 1.6 书店程序
```cpp
#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item total; //保存下一条交易记录点变量
    //读入第一条交易记录，并确保有数据可以处理
    if (cin >> total)
    {
        Sales_item trans; //保存和的变量
        //读入并处理剩余交易记录
        while (cin >> trans)
        {
            //如果我们仍在处理相同的书
            if (total.sameIsbn(trans))
                total += trans; //更新总销售额
            else
            {
                //打印前一本书的结果
                cout << total << endl;
                total = trans; //total现在表示下一本书的销售额
            }
        }
        cout << total << endl; //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告读者
        cerr << "No data?!" << endl;
        return -1; //表示失败
    }
    return 0;
}
```
### 术语表
- `参数（实参，argument`）向函数传递的值。赋值（assignment）抹去一个对象的当前值，用一个新值取代之。
- `程序块（block）`零条或多条语句的序列，用花括号包围。
- `缓冲区（buffer）`一个存储区域，用于保存数据。IO设施通常将输入（或输出）数据保存在一个缓冲区中，读写缓冲区的动作与程序中的动作是无关的。我们可以显式地刷新输出缓冲，以便强制将缓冲区中的数据写入输出设备。默认情况下，读cin会刷新cout；程序非正常终止时也会刷新cout。
- `内置类型（built-in type）`由语言定义的类型，如int。
- `Cerr `一个ostream对象，关联到标准错误，通常写入到与标准输出相同的设备。默认情况下，写到cerr的数据是不缓冲的。cerr通常用于输出错误信息或其他不属于程序正常逻辑的输出内容。
- `字符串字面值常量（character string literal）`术语 string literal的另一种叫法。
- `cin`一个istream对象，用来从标准输入读取数据。
- `类（class）`一种用于定义自己的数据结构及其相关操作的机制。类是C++中最基本的特性之一。标准库类型中，如istream和ostream都是类。
- `类类型（class type`）类定义的类型。类名即为类型名。
- `clog`一个ostream对象，关联到标准错误。默认情况下，写到clog的数据是被缓冲的。c1og通常用于报告程序的执行信息，存入一个日志文件中。
- `注释（comment）`被编译器忽略的程序文本。C++有两种类型的注释：单行注释和界定符对注释。单行注释以//开始，从//
到行尾的所有内容都是注释。界定符对注释以/\*开始，其后的所有内容都是注释，直至遇到\*/为止。
- `条件（condition）`求值结果为真或假的表达式。通常用值0表示假，用非零值表示真。
- `cout`一个 ostream 对象，用于将数据写入标准输出。通常用于程序的正常输出内容。
- `花括号（curly brace）`花括号用于划定程序块边界。左花括号（{）为程序块开始，右花括号（}）为结束。
- `数据结构（data structure）`数据及其上所允许的操作的一种逻辑组合。
- `编辑-编译-调试（edit-compile-debug）`使程序能正确执行的开发过程。
- `文件结束符（end-of-file）`系统特定的标识，指出文件中无更多数据了。
- `表达式（expression）`最小的计算单元。一个表达式包含一个或多个运算对象，通常还包含一个或多个运算符。表达式求值会产生一个结果。例如，假设i和j是int对象，则i+j是一个表达式，它产生两个int值的和。
- `for 语句（for statement）`迭代语句，提供重复执行能力。通常用来将一个计算反复执行指定次数。
- `函数（function`）具名的计算单元。
- `函数体（function body`）语句块，定义了函数所执行的动作。
- `函数名（function name）`函数为人所知的名字，也用来进行函数调用。
- `头文件（header）`使类或其他名字的定义可被多个程序使用的一种机制。程序通过
- `#include`指令使用头文件。
- `if语句（if statement）`根据一个特定条件的值进行条件执行的语句。如果条件为真，执行if语句体。否则，执行else语句体（如果存在的话）。
- `初始化（initialize）`在一个对象创建的时候赋予它一个值。
- `iostream`头文件，提供了面向流的输入输出的标准库类型。
- `istream`提供了面向流的输入的库类型。
- `库类型（library type）`标准库定义的类型，如istream。
- `main`操作系统执行一个C++程序时所调用的函数。每个程序必须有且只有一个命名为main的函数。
- `操纵符（manipulator）`对象，如std:endl，在读写流的时候用来“操纵”流本身。
- `成员函数（member function）`类定义的操作。通常通过调用成员函数来操作特定对方法（method）成员函数的同义术语。
- `命名空间（namespace）`将库定义的名字放在一个单一位置的机制。命名空间可以帮助避免不经意的名字冲突。C++标准库定义的名字在命名空间std中。
- `ostream`标准库类型，提供面向流的输出。
- `形参列表（parameter list）`函数定义的一部分，指出调用函数时可以使用什么样的实参，可能为空列表。
- `返回类型（return type）`函数返回值的类型。
- `源文件（source file）`包含C++程序的文件。标准错误（standard error）输出流，用于报告错误。标准输出和标准错误通常关联到程序执行所在的窗口。
- `标准输入（standard input`）输入流，通常与程序执行所在窗口相关联。
- `标准库（standard library）`一个类型和函数的集合，每个C+编译器都必须支持。标准库提供了支持I0操作的类型。C++程序员倾向于用“库”指代整个标准库，还倾向于用库类型表示标准库的特定部分，例如用“iostream库”表示标准库中定义10类的部分。
- `标准输出（standard output）`输出流，通常与程序执行所在窗口相关联。
- `语句（statement）`程序的一部分，指定了当程序执行时进行什么动作。一个表达式接一个分号就是一条语句；其他类型的语句包括语句块、if语句、for 语句和while语句，所有这些语句内都包含其他语句。
- `std `标准库所使用的命名空间。std:：cout表示我们要使用定义在命名空间std中的名字cout。
- `字符串常量（string literal）`零或多个字符组成的序列，用双引号包围（"a string literal"）。
- `未初始化的变量（uninitialized variable）`未赋予初值的变量。类类型的变量如果未指定初值，则按类定义指定的方式进行初始化。定义在函数内部的内置类型变量默认是不初始化的，除非有显式的初始化语句。试图使用一个未初始化变量的值是错误的。未初始化变量是bug的常见成因。
- `变量（variable）`具名对象。
- `while 语句（while statement）`迭代语句，提供重复执行直至一个特定条件为假的机制。循环体会执行零次或多次，依赖于循环条件求值结果。
- `()运算符（()operator）`调用运算符。跟随在函数名之后的一对括号“0”，起到调用函数的效果。传递给函数的实参放置在括号内。
- `++运算符（++operator）`递增运算符。将运算对象的值加1，++i等价于i=i+1。
- `+=运算符（+=operator）`复合赋值运算符，将右侧运算对象加到左侧运算对象上；a+=b等价于a=a+b。
- `.运算符（.operator）`点运算符。左侧运算对象必须是一个类类型对象，右侧运算对象必须是此对象的一个成员的名字。运算结果即为该对象的这个成员。
- `:运算符（:operator）`作用域运算符。其用处之一是访问命名空间中的名字。例如，std:cout 表示命名空间std中的名字cout。
- `=运算符（=operator）`将右侧运算对象的值赋予左侧运算对象所表示的对象。
- `-运算符（-operator）`递减运算符。将运算对象的值减1，--i等价于i=i-1。
- `<<运算符（<<operator）`输出运算符。将右侧运算对象的值写到左侧运算对象表示的输出流：cout<<"hi"表示将hi写到标准输出。输出运算符可以连接：cout<<"hi"<<"bye"表示将输出hibye。
- `>>运算符（>>operator）`输入运算符。从左侧运算对象所指定的输入流读取数据，存入右侧运算对象中：cin>>i表示从标准输入读取下一个值，存入i中。输入运算符可以连接：cin>>i>>j表示先读取一个值存入i，再读取一个值存入j。
- `#include`头文件包含指令，使头文件中代码可被程序使用。
- `==运算符（==operator）`相等运算符。检测左侧运算对象是否等于右侧运算对象。
- `!=运算符（!=operator）`不等运算符。检测左侧运算对象是否不等于右侧运算对象。
- `<=运算符（<=operator）`小于等于运算符。检测左侧运算对象是否小于等于右侧运算对象。
- `<运算符（<operator）`小于运算符。检测左侧运算对象是否小于右侧运算对象。
- `>=运算符（>=operator）`大于等于运算符。检测左侧运算对象是否大于等于右侧运算对象。
- `>运算符（>operator）`大于运算符。检测左侧运算对象是否大于右侧运算对象。
## 第二章 变量和基本类型
### 2.1 基本内置类型
- 算术类型（arithmetic tyoe）
  - 整型（integral type）
    - 字符
    - 整型数
    - 布尔值
  - 浮点型
- 空类型（void）
#### 2.1.1 算术类型
- C++算术类型

| 类型        | 含义           | 最小尺寸     |
| ----------- | -------------- | ------------ |
| bool        | 布尔类型       | 未定义       |
| char        | 字符           | 8位          |
| wchar_t     | 宽字符         | 16位         |
| char16_t    | Unicode字符    | 16位         |
| char32_t    | Unicode字符    | 32位         |
| short       | 短整型         | 16位         |
| int         | 整型           | 16位         |
| long        | 长整型         | 32位         |
| long long   | 长整型         | 64位         |
| float       | 单精度浮点数   | 6位有效数字  |
| double      | 双精度浮点数   | 10位有效数字 |
| long double | 扩展精度浮点数 | 10位有效数字 |

##### 带符号类型和不带符号类型

| 默认类型 | signed      | unsigned           |
| -------- | ----------- | ------------------ |
| char     | signed char | unsigned char      |
| short    | short       | unsigned short     |
| int      | int         | unsigned int       |
| long     | long        | unsigned long      |
| long     | long        | unsigned long long |


#### 2.1.2 类型转换
- 含有无符号类型的表达式
（略）
#### 2.1.3 字面值常量
#####  整型和浮点型字面值
| 字面值名称 | 字面值例子        |
| ---------- | ----------------- |
| 二进制     | 0b11              |
| 十进制     | 20                |
| 八进制     | 024               |
| 十六进制   | 0x14              |
| 浮点数     | 3.14159 3.14159e0 |

##### 字符和字符串字面值

| 字面值名称 | 字面值例子    |
| ---------- | ------------- |
| 字符       | 'a'           |
| 字符串     | "Hello world" |

#####  转义序列

| 字符常量形式 | 含义       | 十六进制 | 十六进制表示       | 八进制表示       |
| ------------ | ---------- | -------- | ------------------ | ---------------- |
| \a           | 响铃       | 07       | char(0x07) '\x07'  | char(007) '\007' |
| \n           | 换行       | 0A       | char(0x0A) '\x0A'  | char(012) '\012' |
| \t           | 水平制表符 | 09       | char(0x09)  '\x09' | char(011) '\011' |
| \v           | 垂直制表符 | 0B       | char(0x0B)  '\x0B' | char(013) '\013' |
| \b           | 退格       | 08       | char(0x08)  '\x08' | char(010) '\010' |
| \r           | 回车       | 0D       | char(0x0D)  '\x0D' | char(015) '\015' |
| \f           | 换页       | 0C       | char(0x0C)  '\x0C' | char(014) '\014' |
| \\\          | 字符'\\'   | 5C       | char(0x5C)  '\x5C' | char(134) '\134' |
| \"           | 双引号     | 22       | char(0x22)  '\x22' | char(042) '\042' |
| \'           | 单引号     | 27       | char(0x27)  '\x27' | char(047) '\047' |

#####  指定字面值的类型

| 前缀 | 含义          | 类型     |
| ---- | ------------- | -------- |
| u    | Unicode16字符 | char16_t |
| U    | Unicode32字符 | char32_t |
| L    | 宽字符        | wchar_t  |
| u8   | UTF-8         | char     |

| 整型字面值后缀 | 整型字面值最小匹配类型 | 浮点字面值后缀 | 浮点字面值最小匹配类型 |
| -------------- | ---------------------- | -------------- | ---------------------- |
| u or U         | unsigned               | f or F         | float                  |
| l or L         | long                   | l or L         | Long double            |
| ll or LL       | long long              |                |                        |

##### 布尔和指针字面值

| 字面值名称 | 字面值例子 |
| ---------- | ---------- |
| bool       | true false |
| 指针       | nullptr    |

### 2.2 变量

#### 2.2.1 变量定义
##### 初始值
  - 初始化：创建变量并赋初值
  - 赋值：擦出当前值，以新值替代
##### 列表初始化
  - 一组用花括号括起来的初始值
##### 默认初始化
  - 定义于任何函数体外地变量被初始化为0
  - 定义在函数体内部的内置类型变量将不被初始化
#### 2.2.2 声明变量和定义的关系
- 声明非定义
```cpp
extern int i;//extern 只声明不赋值
```
- 声明并定义
```cpp
int j;//声明并定义j
```
- 定义非声明
```cpp
extern double pi=3.1416；//显式初始化的声明不在时声明，是定义
```
- 函数体内部初始化extern标记的变量，将引发错误
- 变量可以被多次声明，能且只能被定义一次

#### 2.2.3 标识符
- C++标识符（identifier）由字母、数字和下划线组成，必须以字母或下划线开头，大小写敏感
##### 变量命名规范
- 标识符要能体现实际含义
- 变量名一般用小写字母
- 用户自定义的类名一般以大写字母开头
- 如果标识符由多个单词组成，则单词间应有明显区分（驼峰命名法：小驼峰法：变量；大驼峰法：类名，命名空间，属性等）

- C++关键字
<table>
<tr><td>alingnas</td><td>continue</td><td>friend</td><td>register</td><td>true</td></tr>
<tr><td>alignof</td><td>decltype</td><td>goto</td><td>reinterpret_cast</td><td>try</td></tr>
<tr><td>asm</td><td>default</td><td>if</td><td>return</td><td>typedef</td></tr>
<tr><td>auto</td><td>delete</td><td>inline</td><td>short</td><td>typeid</td></tr>
<tr><td>bool</td><td>do</td><td>int</td><td>signed</td><td>typename</td></tr>
<tr><td>break</td><td>double</td><td>long</td><td>sizeof</td><td>union</td></tr>
<tr><td>case</td><td>dynamic_cast</td><td>mutable</td><td>static</td><td>unsigned</td></tr>
<tr><td>catch</td><td>else</td><td>namespace</td><td>static_assert</td><td>using</td></tr>
<tr><td>char</td><td>enum</td><td>new</td><td>static_cast</td><td>virtual</td></tr>
<tr><td>char16_t</td><td>explicit</td><td>noexcept</td><td>struct</td><td>void</td></tr>
<tr><td>char32_t</td><td>export</td><td>nullptr</td><td>switch</td><td>volatile</td></tr>
<tr><td>calss</td><td>extern</td><td>operator</td><td>template</td><td>wchar_t</td></tr>
<tr><td>const</td><td>false</td><td>private</td><td>this</td><td>while</td></tr>
<tr><td>constexpr</td><td>float</td><td>protected</td><td>thread_local</td><td></td></tr>
<tr><td>const_cast</td><td>for</td><td>public</td><td>throw</td><td></td></tr>
</table>

- C++操作符替代名
<table><tr><td> and </td><td> bitand </td><td> compl </td><td> not_eq </td><td> or_eq </td><td> xor_eq </td><td> and_eq </td><td> bitor </td><td> not </td><td> or  </td><td> xor </td></tr></table>

#### 2.2.4 名字的作用域
- 作用域scope
  - C++大多数作用域都以{}分隔
  - 同一名字在不同作用域中可能指向不同的实体
  - 名字的有效区域始于声明，结束于作用域末端
  - 全局作用域global scope main和大多数定义在函数体之外的名字具有全局作用域
  - 块作用域block scope，定义在块内的名字，在块外就无法访问

#####  嵌套的作用域
- 被包围的作用域称内层作用域inner scope，相对的为外层作用域outer scope
  - 内层作用域可以访问外层作用域
  - 内层作用域可以重新定义外层作用域的名字

### 2.3 复合类型
- 声明符语句：基本数据类型（base type） 声明符（declarator）
- 简单的声明符就是变量
- 复杂的声明符，基于简单的声明符得到更复杂的类型，并把它指定给变量

#### 2.3.1 引用
- 一般引用指左值引用（lvalue reference），另一种右值引用（rvalue reference）主要用于内置类
##### 引用即别名
- 引用（reference）为对象起别名，引用类型必须引用（refers to）另外一种类型的对象（引用必须被初始化）
引用不是对象
##### 引用的定义
- 每个引用标识符必须紧以&符号开头,引用类型必须与绑定对象严格匹配（两种例外），只能绑定在对象上，不能与字面值或表达式绑定。
```cpp
int i=1024,j=2048;
int &ri=i,&rj=j;
```
- 所以int &可以看成int型的引用类型，ri,rj看成引用变量
- 为了连续声明几个引用，int 和 &ri分开
- 引用不是对象，必须初始化，给引用变量赋值，就是给所引用的对象赋值，可以看成常量指针

#### 2.3.2 指针
- 指针（pointer）是“指向（point to）”另外一种类型的符合类型
- 指针本身是一个对象，可以赋值和拷贝，同一指针可以先后指向不同对象
- 块作用域中定义未初始化的指针，拥有一个不确定的值
```cpp
int *ip1,*ip2;//指向int类型对象的指针
```
- int *看作int型的指针类型，ip1,ip2看作指针对象
##### 获取对象的地址
- 所有指针的类型都要和它所指向的对象严格匹配（两种例外）
```cpp
//取地址符&
int ival = 42;
int *ip = &ival;
```
##### 指针值
- 指向一个对象
- 指向紧邻对象所占空间的下一个位置
- 空指针，指针没有指向任何对象
- 无效指针，上述之外的其他值
  - 拷贝或访问无效指针都将发生错误
##### 利用指针访问对象
```cpp
int i=42;
int &r=i;  //r引用
int *p;    //p指针
p=&i;      //取地址符
*p=i;      //*解引用符，*p 表示指针指向的对象
int &r2=*p;//引用与解引用符
```
- 声明语句中&和*用于组成符合类型，表达式中，转变为运算符

##### 空指针null pointer
```cpp
int *p1=nullptr;  //等同 int *p1=0;
int *p2=0;        //此处0为空指针字面值，类型与整型0不同
#include <cstdlib>//预处理变量NULL在头文件cstdlib中
int *p3=NULL;     //等同 int *p3=0;
```
##### 赋值和指针
- 赋值永远改变的是左值
##### 其他指针操作
- 指针有合法值，当着条件时，空指针为false，其他值为true
- 相同类型的合法指针，可以用==、!=进行比较，当指向的地址相同时为两个指针相等
##### void *指针
- 可以存放任意对象的地址
- 作用：和别的指针比较、作为函数的输入或输出、赋值给另外一个void*指针
- 不能直接操作void *指针所指对象

#### 2.3.3 理解符合类型的声明
##### 定义多个变量
```cpp
//注意区别
int *p1,p2;
int *p1,*p2
```
##### 指向指针的指针
```cpp
int ival=1024;
int *pi=&ival;
int **ppi=&pi;
```
##### 指向指针的引用
```cpp
int i=42;
int *p;
int *&r=p;//指针类型对象的引用
r=&i;//给引用变量赋值改变的是所引用的对象p的值
*r=0;//*r解引用得i,p指向的对象，i的值改为0
```
### 2.4 const 限定符
- const 限定的变量不能改变值，叫做常量，常量只能初始化不能单独赋值
- 被const限定的变量能参与运算，不能改变自身的值
##### 初始化和const
  - 默认情况下，const对象仅在文件内有效
##### 需要在文件外生效，必须声明
```cpp
extern const int bufSize=fcn();//定义并初始化一个常量,可以被外部文件访问，只能出现一次
extern const int bufSize;//声明一个常量，可以被外部文件访问，可以出现多次
```
#### 2.4.1 const 的引用
- 对常量的引用（reference to const）
- 不能修改被绑定的值，不能给对常量的引用赋值
- 普通引用不能引用常量

##### 初始化和对const的引用
- 引用的类型必须与其所引用对象的类型一致，但有两种例外，其中之一
- 在初始化对const的引用时，允许用任意表达式、非常量对象、字面值作为初始值；
- 对变量的引用，可以通过引用改变引用对象的值，不允许表达式；

#### 2.4.2 指针和const
- 指向常量的指针（pointer to const）不能用于改变其所指对象的值
- 想存放常量对象的地址，只能使用指向常量的指针；
- 指针类型必须和所指对象的类型一致，有两个例外，其中之一：
  - 指向常量的指针指向一个非常量的对象，指向常量的指针不能改变指向变量对象的值，但可通过其他方法改变其值；
##### const指针
- 将指针本身定为常量，常量指针（const pointer）必须初始化
```cpp
const double pi=3.14159;
const double *const pip=&pi;//指向常量的常量指针（指针本身是常量，同时指向一个常量对象）
int errNumb=1;
int *const curErr=&errNumb;
*curErr=0;//指向非常量的常量指针，可以改变所指对象的值
```
- *引用与指针的区别*
  - *引用*
    - *引用是对象的别名，必须绑定一个对象且不能改变*
    - *引用必须初始化；*
    - *引用不是对象，没有对引用的引用，指向引用的指针，不存在引用本身是常量的说法，<br>(所谓的“常量引用”是指对常量的引用，而不是引用本身是常量）；*
    - *对非常量的引用，不能用常量，表达式，字面值初始化；*
    - *对常量的引用（常量引用），可以用常量，表达式，字面值，非常量对象初始化.*

  - *指针*
    - *指针是地址，可以指向这个对象，也可以是指向另一个对象*
    - *指针不一定初始化，块作用域中未初始化的指针拥有一个未确定的值，但指向常量的指针必须初始化*
    - *指针是对象，有对指针的引用，指向指针的指针，常量指针*
    - *指针不能指向表达式，字面值，不能用表达式或字面值初始化*
    - *指向非常量的指针不能用常量对象初始化，常量对象只能拥有指向常量的指针*
    - *指向常量的指针可以指向常量，非常量对象*
    - *常量指针自身的值不能改变*
    - *常量指针可以改变其指向的非常量对象的值*
（mmd，绕来绕去的，脑壳痛）


#### 2.4.3 顶层const
- 顶层const（top-level-const）表示指针本身是个常量，底层const（low-level-const）表示指针指向的对象是常量，这是两个相互独立的问题
- 一般地，顶层const可以表示任意的对象是常量，底层const则与指针和引用等符合类型的基本类型部分有关，指针类型即可以是顶层const，<br>也可以是底层const，指针左侧的const是底层const，指针右侧的const是顶层const，用于声明引用的const都是底层const
```cpp
int i=0;
int *const p1=&i;      //不能改变p1的值，顶层const
const int ci=42;       //不能改变ci的值，顶层const
const int *p2=&ci;     //允许改变p2的值，底层const
const int *const p3=p2;//左侧const是底层const，右侧const是顶层const
const int &r=ci;       //用于声明引用的const都是底层const
```
- 执行拷贝操作时，顶层const不受影响，底层const则必须类型一致，或能转换类型
```cpp
i=ci;           //不受影响
p2=p3;          //指向的类型相同，p3的顶层const部分不受影响
//int *p=p3;    //错误，p3含底层const，p没有
p2=&i;          //int*能转换成const int*
//int &r=ci;    //错误，普通的int &不能绑定到int 常量上
const int &r2=i;//const int &可以绑定到一个普通int上
```
#### 2.4.4 constexpr 和常量表达式
- 常量表达式（const expression）是指不会改变并且在编译过程就能得到计算结果的表达式
- 用常量表达式初始化的const对象也是常量表达式
##### constexpr变量
- 允许将变量声明为constexpr类型，以便由编译器来验证变量的值是否是一个常量表达式
- 声明为constexpr的变量一定是一个常量，而且必须用常量表达式或constexpr函数初始化
- constexpr函数，足够简单，编译时就可以计算其结果
##### 字面值类型
- 算术类型、引用、指针、constexpr类型都属于字面值类型

- 指针和引用都能定义成constexpr，constexpr指针必须初始值是nullptr或者0，或者是存储于某固定地址中的对象
- constexpr 引用能绑定固定地址的变量，constexpr指针能指向固定地址的变量

##### 指针和constexpr
- consttexpr 声明中定义类一个指针，限定符constexpr仅对指针有效，与指针指向的对象无关
```cpp
const int *p=nullptr;//指向常量的指针 底层const
constexpr int *q=nullptr;//常量指针 顶层const
int j=0;
constexpr int i=42;//i的类型是整型常量
//i和j必须定义在函数体外（固定地址）
constexpr const int *p=&i;//常量指针p指向整型常量i
constexpr int *p1=&j;//p1是常量指针，指向整数j
```
### 2.5 处理类型
#### 2.5.1 类型别名
- typedef 关键词
```cpp
typedef double wages;//wages 是double的同义词
typedef wages base, *p;//base 是double 的同义词，p是double *的同义词
```
- 别名声明（alias declaration）
```cpp
using SI=SalesItem;//SI是SalesItem的同义词
```
##### 指针、常量和类型别名
```cpp
typedef char *pstring;//pstring与char *同义,是指针类型
const pstring cstr=0; //cstr是const pstring类型的对象，即指向char类型对象的常量指针，同char *const cstr=0
const pstring *ps;    //ps是指针，指向的对象是指针，指向的对象是指向char类型对象的常量指针
```
#### 2.5.2 auto类型说明符
- 把表达式==赋值==给变量，如果不知道表达式的类型，用auto类型说明符，auto定义的变量必须有初始值
- auto在一条语句中声明多个变量，变量的初始基本数据类型必须一样
```cpp
auto i=0,*p=&i;//i是整型，p是整型指针
//auto sz=0,pi=3.14;//错误，sz是整型，pi为浮点型
```
##### 复合类型、常量和auto
- 使用引用作为初始值时，编译器把引用的对象的类型作为auto的类型
- auto 一般会忽略掉顶层const，同时底层const会保留下来
- 希望推断出的auto类型是一个顶层const，需要明确指出
- 可以将引用得类型设为auto
- 设置一个类型为auto的引用时，初始值的顶层常量属性仍然保留，auto紧跟&和*时，理解为初始化
- 在同一条语句中定义多个变量，&和*只从属于某个声明符，而非基本数据类型的一部分
```cpp
int i=0,&r=i;//i是整型，r是i的别名
auto a=r;//将r赋值给a，r绑定的对象是整型，a是整型

const int ci=i,&cr=ci;//ci是整型常量，cr是对整形常量的引用
auto b=ci;//将ci赋值给b，b是整型（常量赋值给变量，ci的顶层const被忽略）
auto c=cr；//将cr引用的对象赋值给c，c是整型（cr是ci的别名）
auto d=&i;//d是一个整型指针
auto e=&ci;//e是一个指向整数常量的指针，对常量取地址是底层const

const auto f=ci;//希望推断出的auto类型是一个顶层const，需要明确指出

auto &g=ci;//g是一个绑定整形常量对象的引用，绑定到ci
//auto &h=42;//错误，不能为非常量引用绑定字面值，能自动识别字面值的类型，不能确定是常量，h为非常量对象引用
const auto &j=42;//可以为常量引用绑定字面值

auto k=ci，&l=i;//k是整数，l是对整型对象的引用
auto &m=ci,*p=&ci;//m是对整型常量对象的引用，p是一个指向整型常量的指针
//auto &n=i,*p2=&ci;//错误：i的类型是int，而p2是指向是const int对象的制作
```
#### 2.5.3 decltype 类型指示符
- 从表达式的类型推断出要定义的变量的类型，但不用该表达式的值初始化变量
- decltype返回该变量的类型（包括顶层const和引用在内）
- 引用都是作为所指对象的同义词出现，用在decltype处例外，表示自己
```cpp
decltype(f()) sum=x;//sum的类型就是函数f()d 返回类型
const int ci=0,&cj=ci;
decltype(ci) x=0;//x的类型是const int
decltype(cj) y=x;//y的类型是const int &,y绑定到变量x
//decltype(cj) z;//错误，z是一个引用，必须初始化
```
##### decltype 和引用
- 如果表达式向decltype返回一个引用类型，意味着表达式的结果对象能作为一条赋值语句的左值：
```cpp
int i=42,*p=&i,&r=i;
decltype(r+0) b;//加法的结果是int,b是一个未初始化的int，右值表达式类型为表达式计算结果的类型
//decltype(*p) c;//错误，解引用指针的类型是引用，而非该指针指向的对象的类型，c类型为int&,必须初始化
```
- decltype的结果类型与表达式形式密切相关。
- 变量名加一对括号，得到的类型与不加括号时会有不同
- 变量是可以作为赋值语句左值的特殊表达式,左值表达式类型为引用
```cpp
//decltype((i)) d;//错误：d是int&,必须初始化
decltype(i) e;//e是未初始化的int
```

### 2.6 自定义数据结构
- 数据结构就是把一组相关的数据元素组织起来然后使用它们的策略和方法。

#### 2.6.1 定义Sakes_data类型
```cpp
struct Sakes_data{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
```
- 类体内部定义名字必须唯一，可以和类外部定义的名字重复。
- 类体结束的花括号后必须写一个分号，因为类体后面可以紧跟变量名以表示对该类型对象的定义。
```cpp
struct Sakes_data{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
} accum,trans,*salesptr;
//等价于
struct Sakes_data{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
Sakes_data accum,trans,*salesptr;
```
##### 类数据成员（data menber）
- 可以为数据成员提供一个类内初始值（in-class initializer）
- 创建对象时，类内初始值将用于初始化数据成员，没有初始值的成员将被默认初始化
- 类内初始值可以放在花括号里，或等号右边，不能用圆括号
- 使用圆括号会被认为是声明函数
```cpp
struct Sakes_data{
    std::string bookNo{};
    unsigned units_sold{0};
    double revenue{0.0;}
};
```
#### 2.6.2 使用Sakes_data类
##### 添加两个Sales_data对象
##### Sales_data对象读入数据
##### 输出两个Sales_data对象的和
```cpp
#include <iostream>
struct Sakes_data
{
    std::string bookNo{};
    unsigned units_sold{0};
    double revenue{0.0};
};
int main()
{
    Sakes_data data1, data2;
    double price = 0; //书的单价，用于计算销售收入
    //读入第1笔交易：ISBN、销售数量、单价
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    //计算销售收入
    data1.revenue = data1.units_sold * price;
    //读入第2笔交易
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        //输出：ISBN、总销售量、总销售额、平均价格
        std::cout << data1.bookNo << " " << totalCnt
                  << " " << totalRevenue << " ";

        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0; //表示成果
    }
    else
    { //两笔交易的ISBN不一样
        std::cerr << "Data must refer to the same ISBN"
                  << std::endl;
        return -1; //表示失败
    }
    return 0;
}
```
#### 2.6.3 编写自己的头文件
- 类可以定义在函数体外部
- 也可以在函数体内定义类，但不推荐
- 确保各个文件总类的定义一致，类通常被定义在头文件中

- 头文件通常包含哪些只能被定义一次的实体
- 头文件也经常用到其他头文件的功能
##### 预处理器概述
- 预处理器：确保头文件多次包含仍能安全工作的常用技术是预处理器（perprocessor）
- 预处理器是编译之前执行的一段程序
- \#include 是一项预处理功能
- 另一种预处理功能：头文件保护符（header guard）
- 预处理变量必须唯一，一般用全大写的头文件名
```cpp
#define 指令把一个名字设定为预处理变量
#ifdef 变量已定义时为真
#ifndef 变量未定义时为真
#endif 一旦检查结果为真，则执行后续操作直到#endif指令为止

#ifndef SALESITEM_H  //SALESITEM_H变量未定义，为真执行后续代码
#define SALESITEM_H  //SALESITEM_H变量已定义，再次包含此文件，不会继续执行后续代码
//……
#endif //执行到此结束
```
### 术语表
- `地址（address）`是一个数字，根据它可以找到内存中的一个字节。
- `别名声明（alias declaration）`为另外一种类型定义一个同义词：使用“名字=类型”的格式将名字作为该类型的同义词。
- `算术类型（arithmetic type`）布尔值、字符、整数、浮点数等内置类型。
- `数组（array）`是一种数据结构，存放着一组未命名的对象，可以通过索引来访问这些对象。3.5节将详细介绍数组的知识。
- `auto` 是一个类型说明符，通过变量的初始值来推断变量的类型。
- `基本类型（base type`）是类型说明符，可用const修饰，在声明语句中位于声明符之前。基本类型提供了最常见的数据类型，以此为基础构建声明符。
- `绑定（bind）`令某个名字与给定的实体关联在一起，使用该名字也就是使用该实体。例如，引用就是将某个名字与某个对象绑定在一起。
- `字节（byte）`内存中可寻址的最小单元，大多数机器的字节占8位。
- `类成员（class member）`类的组成部分。复合类型（compound type）是一种类型，它的定义以其他类型为基础。
- `const`是一种类型修饰符，用于说明永不改变的对象。const对象一旦定义就无法再赋新值，所以必须初始化。
- `常量指针（const pointer）`是一种指针，它的值永不改变。
- `常量引用（const reference）`是一种习惯叫法，含义是指向常量的引用。
- `常量表达式（const expression）`能在编译时计算并获取结果的表达式。
- `constexpr`是一种函数，用于代表一条常量表达式。6.5.2节（第214页）将介绍constexpr函数。
- `转换（conversion）`一种类型的值转变成另外一种类型值的过程。C++语言支持内置类型之间的转换。
- `数据成员（data member）`组成对象的数据元素，类的每个对象都有类的数据成员的一份拷贝。数据成员可以在类内部声明的同时初始化。
- `声明（declaration）`声称存在一个变量、函数或是别处定义的类型。名字必须在定义或声明之后才能使用。
- `声明符（declarator）`是声明的一部分，包括被定义的名字和类型修饰符，其中类型修饰符可以有也可以没有。
- `decltype`是一个类型说明符，从变量或表达式推断得到类型。
- `默认初始化（default initialization）`当对象未被显式地赋予初始值时执行的初始化行为。由类本身负责执行的类对象的初始化行为。全局作用域的内置类型对象初始化为0；局部作用域的对象未被初始化即拥有未定义的值。
- `定义（definition）`为某一特定类型的变量申请存储空间，可以选择初始化该变量。名字必须在定义或声明之后才能使用。
- `转义序列（escape sequence）`字符特别是那些不可打印字符的替代形式。转义以反斜线开头，后面紧跟一个字符，或者不多于3个八进制数字，或者字母x加上1个十六进制数。
- `全局作用域（global scope）`位于其他所有作用域之外的作用域。
- `头文件保护符（header guard）`使用预处理变量以防止头文件被某个文件重复包含。
- `标识符（identifier）`组成名字的字符序列，标识符对大小写敏感。
- `类内初始值（in-class initializer）`在声明类的数据成员时同时提供的初始值，必须置于等号右侧或花括号内。
- `在作用域内（in scope）`名字在当前作用域内可见。
- `被初始化（initialized`）变量在定义的同时被赋予初始值，变量一般都应该被初始化。
- `内层作用域（inner scope）`嵌套在其他作用域之内的作用域。
- `整型（integral type）`参见算术类型。
- `列表初始化（list initialization）`利用花括号把一个或多个初始值放在一起的初始化形式。
- `字面值（literal）`是一个不能改变的值，如数字、字符、字符串等。单引号内的是字符字面值，双引号内的是字符串字面值。
- `局部作用域（local scope）`是块作用域的习惯叫法。
- `底层const（low-level const）`一个不属于顶层的const，类型如果由底层常量定义，则不能被忽略。
- `成员（member）`类的组成部分。
- `不可打印字符（nonprintable character）`不具有可见形式的字符，如控制符、退格、换行符等。
- `空指针（null pointer）`值为0的指针，空指针合法但是不指向任何对象。
- `nullptr`是表示空指针的字面值常量。
- `对象（object）`是内存的一块区域，具有某种类型，变量是命名了的对象。
- `外层作用域（outer scope）`嵌套着别的作用域的作用域。
- `指针（pointer）`是一个对象，存放着某个对象的地址，或者某个对象存储区域之后的下一地址，或者0。
- `指向常量的指针（pointer to const）`是一个指针，存放着某个常量对象的地址。指向常量的指针不能用来改变它所指对象的值。
- `预处理器（preprocessor）`在C++编译过程中执行的一段程序。
- `预处理变量（preprocessor variable）`由预处理器管理的变量。在程序编译之前，预处理器负责将程序中的预处理变量替换成它的真实值。
- `引用（reference）`是某个对象的别名。
- `对常量的引用（reference to const）`是一个引用，不能用来改变它所绑定对象的值。对常量的引用可以绑定常量对象，或者非常量对象，或者表达式的结果。
- `作用域（scope）`是程序的一部分，在其中某些名字有意义。C++有几级作用域：
- `全局（global）`——名字定义在所有其他作用域之外。
- `类（class）`——名字定义在类内部。
- `命名空间（namespace）`——名字定义在命名空间内部。
- `块（block）`——名字定义在块内部。名字从声明位置开始直至声明语句所在的作用域末端为止都是可用的。
- `分离式编译（separate compilation）`把程序分割为多个单独文件的能力。
- `带符号类型（signed）`保存正数、负数或0的整型。
- `字符串（string`）是一种库类型，表示可变长字符序列。
- `struct`是一个关键字，用于定义类。
- `临时值（temporary`）编译器在计算表达式结果时创建的无名对象。为某表达式创建了一个临时值，则此临时值将一直存在直到包含有该表达式的最大的表达式计算完成为止。
- `顶层const（top-level const）`是一个const，规定某对象的值不能改变。
- `类型别名（type alias）`是个名字，是另外一个类型的同义词，通过关键宁typedef或别名声明语句来定义。
- `类型检查（type checking）`是一个过程，编译器检查程序使用某给定类型对象的方式与该类型的定义是否一致。
- `类型说明符（type specifier）`类型的名字。
- `typedef`为某类型定义一个别名。当关键字typedef作为声明的基本类型出现时，声明中定义的名字就是类型名。
- `未定义（undefined）`即C++语言没有明确规定的情况。不论是否有意为之，未定义行为都可能引发难以追踪的运行时错误、安全问题和可移植性问题。
- `未初始化（uninitialized）`变量已定义但未被赋予初始值。一般来说，试图访问未初始化变量的值将引发未定义行为无符号类型（unsigned）保存大于等于0的整型。
- `变量（variable）`命名的对象或引用。C++语言要求变量要先声明后使用。
- `void*`可以指向任意非常量的指针类型，不能执行解引用操作。
- `void类型`是一种有特殊用处的类型，既无操作也无值。不能定义一个void类型的变量。
- `字（word）`在指定机器上进行整数运算的自然单位。一般来说，字的空间足够存放地址。32位机器上的字通常占据4个字节。
- `&运算符（&operator）`取地址运算符。
- `*运算符（*operator）`解引用运算符。解引用一个指针将返回该指针所指的对象，为解引用的结果赋值也就是为指针所指的对象赋值。
- `#define`是一条预处理指令，用于定义一个预处理变量。
- `#endif`是一条预处理指令，用于结束一个#ifdef或#ifndef区域。
- `#ifdef`是一条预处理指令，用于判断给定的变量是否已经定义。
- `#ifndef`是一条预处理指令，用于判断给定的变量是否尚未定义。
## 第三章 字符串、向量和数组
### 3.1 命名空间的using声明
- 使用命名空间的形式
  - 命名空间名::对象名（std::cin）
  - using 命名空间名::对象名（using std::cin）
  - using namespace::命名空间名（using namespace::std）
- 作用域操纵符（::）的含义：使用命名空间中的对象

##### 每个名字都需要独立的using声明
```cpp
using std::cin;
using std::cout;
using std::endl;
```
- 无需每个名字独立声明
```cpp
using namespace std;
```
##### 头文件中不应包含using声明
- 如果头文件中有了using声明，每个使用了头文件的文件就都会有using声明，容易产生始料未及的名字冲突
### 3.2 标准库类型 string
- 使用string前，要包含string
```cpp
#include <string>
using std::string;
```
#### 3.2.1 定义和初始化string对象
- 一个类可以定义很多种初始化对象的方式：或者初始值数量不同，或者初始值的类型不同
```cpp
    string s1;                  //默认初始化，s1是一个空字符串
    string s2 = s1;             //s2是s1的副本
    string s3(s2);              //等价于s3=s2
    string s4 = "hiya";         //s4是该字符串字面值的副本，除最后的空字符外
    string s5("hiya");          //等同于s5="hiya"
    string s6(n, 'c');          //把s6初始化为由连续n个字符c组成都字符串
```
##### 直接初始化和拷贝初始化
```
  string s4 = "hiya";         //拷贝初始化
  string s5("hiya");          //直接初始化
  string s6 = string(10,'c'); //拷贝初始化
```
- 可以用字符串变量、字符串字面值、圆括号、花括号、string()通过拷贝初始化“=”或直接初始化
- 圆括号必须带参数，否则会被当函数声明
- 花括号读取第一个字面值字符串或字符否则为空字符串
```cpp
string s7{15, 'b'};         //s7的内容是b;
string s8 = {"15", "cdf"};  //s8的内容是15;
string s9{"15", "cdf"};     //s9的内容是15;
string s10 = string("ABC"); //s9的内容是ABC;
```
#### 3.2.2 string对象上的操作
- string的操作
<table>
<tr><td>os<<s</td><td>将s写到输出流os当中，返回os</td></tr>
<tr><td>is>>s</td><td>从is中读取字符串赋给s，字符串以空白分隔，返回is</td></tr>
<tr><td>getline(is,s)</td><td>从is中读取一行赋给s，返回is</td></tr>
<tr><td>s.empty()</td><td>s为空返回true，否则返回false</td></tr>
<tr><td>s.size()</td><td>返回s中字符的个数</td></tr>
<tr><td>s[n]</td><td>返回s中第n个字符的引用，位置n从0计起</td></tr>
<tr><td>s1+s2</td><td>返回s1和s2连接后的结果</td></tr>
<tr><td>s1=s2</td><td>用s2的副本代替s1中原来的字符</td></tr>
<tr><td>s1==s2</td><td>如果s1和s2中所含的字符完全一样，则它们相等，</td></tr>
<tr><td>s1!=s2</td><td>string对象的相等性判断对字母的大小写敏感</td></tr>
<tr><td><,<=,>,>=</td><td>利用字符在字典中的顺序进行比较，且对字母的大小写敏感</td></tr>
</table>

##### 读写string对象
```cpp
string s;//空字符串
cin>>s;//将string对象读入s，遇到空白停止
cout<<s<<endl;//输出s，如输入"   Hello World!   ",输出"Hello"

string s1,s2;//空字符串s1,s2
cin>>s1>>s2;//将string对象读入s1,s2，遇到空白停止
cout<<s1<<s2<<endl;//输出两个string对象，如输入"   Hello World!   ",输出"HelloWorld"
```
##### 读取未知数量的string对象
```cpp
string word;
while(cin>>word)//反复读取，知道文件末尾
cout<<word<<endl;//输出单词，每个单词后紧跟一个换行符
```
##### 使用getline读取一整行
```cpp
string line;//每次读入一整行，直至到达文件末尾
while(getline(cin,line));
cout<<line<<endl;//line中不包含换行符，getline函数返回的换行符被丢弃了
```
##### string的empty和size操作
```cpp
bool b = s2.empty(); //s为空返回true,否则返回false
auto i = s2.size();  //返回s中字符的个数,i为size_type类型的对象
```
##### string::size_type类型
- size函数返回的是一个string::size_type类型，该类型在类string中定义的，是一个无符号整型
##### 比较string对象
- 关系运算符<、<=、>、>=分别检验一个string对象是否小于、小于等于、大于、大于等于另外一个string对象。上述这些运算符都依照（大小写敏感的）字典顺序：
  - 如果两个string对象的长度不同，而且较短string对象的每个字符都与较长string对象对应位置上的字符相同，就说较短string对象小于较长string对象。
  - 如果两个string对象在某些对应的位置上不一致，则string对象比较的结果其实是string对象中第一对相异字符比较的结果。
```cpp
string str="Hello";
string phrase="Hello World";
string slang="Hiya";
//str<phrase<slang
```
##### 为string对象赋值
##### 两个string对象相加
```cpp
string s1="hello，",s2="world\n";
string s3=s1+s2;//s3的内容是hello，world\n
s1+=s2;//等价于s1=s1+s2
```
##### 字面值和string对象相加
- 当把string对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符（+）的两侧的运算对象至少有一个是string：
```cpp
string s4=s1+"，";//正确：把一个string对象和一个字面值相加
string s5="hello"+"，";//错误：两个运算对象都不是string
string s6=s1+"，"+"world";//正确：每个加法运算符都有一个运算对象是string
string s7="hello"+"，"+s2;//错误：不能把字面值直接相加
```
- 字符串字面值和string对象相加：字符串字面值不能直接相加
- 字符串字面值和string对象不是同一类型

---
#### 3.2.3 处理string对象中的字符
- 在cctype头文件中定义了一组标准库函数
##### cctype头文件中的函数
<table>
<tr><td>isalnum(c)</td><td>当c是字母或数字时为真</td></tr>
<tr><td>isalpha(c)</td><td>当c是字母时为真</td></tr>
<tr><td>iscntrl(c)</td><td>当c是控制符时为真</td></tr>
<tr><td>isdigit(c)</td><td>当c是数字时为真</td></tr>
<tr><td>isgraph(c)</td><td>当c是不是空格但可以打印时为真</td></tr>
<tr><td>islower(c)</td><td>当c是小写字母时为真</td></tr>
<tr><td>isprint(c)</td><td>当c是可打印字符时为真（即c是空格或具有可视形式）</td></tr>
<tr><td>ispunct(c)</td><td>当c是标点符号时为真</td></tr>
<tr><td>isspace(c)</td><td>当c是空白时为真（即c使空格、横向纵向制表符、回车符、换行符、进纸符中的一种）</td></tr>
<tr><td>isupper(c)</td><td>当c是十六进制数字时为真</td></tr>
<tr><td>isxdigit(c)</td><td>当c是字母或数字时为真</td></tr>
<tr><td>tolower(c)</td><td>如果c是大写字母，输出对应的小写字母；否则原样输出c</td></tr>
<tr><td>toupper(c)</td><td>如果c是小写字母，输出对应的大写字母；否则原样输出c</td></tr>
</table>

##### 处理每个字符？使用基于范围的for语句
- for (declaration:expression)statement
```cpp
#include <iostream>
using namespace std;
int main()
{
    string s("Hello World!!!");
    //punct_cnt的类型和s.size的返回类型一样；
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s)//s中的每一个字符
        if (ispunct(c))//如果该字符是标点符号
            ++punct_cnt;//将标点符号的计数值加1
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
    return 0;
}
```
##### 使用范围for语句改变字符串中的字符
```cpp
#include <iostream>
using namespace std;
int main()
{
    string s("Hello World!!!");
    //punct_cnt的类型和s.size的返回类型一样；
    decltype(s.size()) punct_cnt = 0;
    for (auto &c : s) //s中的每一个字符(c是引用，复制将改变s中的字符)
    {
        c = toupper(c);  //c是引用，复制将改变s中的字符
        if (ispunct(c))  //如果该字符是标点符号
            ++punct_cnt; //将标点符号的计数值加1
    }
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
    return 0;
}
```
##### 只处理一部分字符？
  - 使用下标
  - 使用迭代器
##### 使用下标执行迭代
```cpp
#include <iostream>
using namespace std;
int main()
{
    string s("Hello World!!!");
    //punct_cnt的类型和s.size的返回类型一样；
    decltype(s.size()) punct_cnt = 0;
    for (auto &c : s) //s中的每一个字符(c是引用，复制将改变s中的字符)
    {
        c = toupper(c);  //c是引用，复制将改变s中的字符
        if (ispunct(c))  //如果该字符是标点符号
            ++punct_cnt; //将标点符号的计数值加1
    }
    cout << punct_cnt
         << " punctuation characters in " << s << endl;
    string s1("some string");
    if (!s1.empty())            //确保s[0]位置有字符
        s1[0] = toupper(s1[0]); //第一字符大写
    cout << s1 << endl;
    //依次处理s中的字符直到处理完全部字符或遇到一个空白
    for (decltype(s1.size()) index = 0; index < s1.size() && !isspace(s1[index]); ++index)
        s1[index] = toupper(s1[index]); //当前字符大写
    cout << s1 << endl;
    return 0;
}
```
##### 使用下标执行随机访问
```cpp
#include <iostream>
using namespace std;
int main()
{
    const string hexdigits = "0123456789ABCDEF"; //可能的十六进制数字
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    string result;       //用于保存十六进制字符串
    string::size_type n; //用于保存从输入流读取的数
    while (cin >> n)
        if (n < hexdigits.size())   //忽略无效输入
            result += hexdigits[n]; //得到对应的十六进制数字
    cout << "Your hex number is: " << result << endl;
    return 0;
}
```
### 3.3 标准库类型vector
- 标准库类型vector表示对象的集合，其中所有对象的类型都相同，也被称为容器（container）
```cpp
#include <vector>
using namespace std;
```
- c++既有类模板（class template），也有函数模板
- vector是一个类模板 模板不是类或函数，可看作编译器生成类或函数编写的一份说明
- 编译器根据模板创建类或函数的过程称为实例化（istantiation）
```cpp
vector<int> ivec;//ivec保存int 类型的对象
vector<SalesItem> salesVec;//salesVec保存SalesItem类型的对象
vector<vector<stirng>> file;//该向量的元素是vector<string>类型的对象
```
- 引用不是对象，vector不保护引用

#### 3.3.1 定义和初始化vector对象
- 初始化vector对象的方法
- 不能使用字符串字面值创建vector对象
```cpp
vector<T>v1             //v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
vector<T>v2(v1)         //v2中包含有v1所有元素的副本
vector<T>v2=v1          //等价于v2（v1），v2中包含有v1所有元素的副本
vector<T>v3(n，val )    //v3包含了n个重复的元素，每个元素的值都是va1
vector<T>v4(n)          //v4包含了n个重复地执行了值初始化的对象
vector<T>v5{a，b，c...} //v5包含了初始值个数的元素，每个元素被赋予相应的初始值
vector<T>v5={a，b，c...}//等价于v5{a，b，c...}
```
##### 列表初始化vector对象
##### 创建指定数量的元素
##### 值初始化
##### 列表初始值还是元素数量？
```cpp
vector<int> v1;      //v1是一个空vector，int类型
vector<int> v2(v1);  //v2包含v1所有元素副本
vector<int> v3 = v1; //v3包含v1所有元素副本
int n = 5, val = 5;
vector<int> v4(n, val);//v4包含5个5
//vector<string> v5('5');//不能使用字符串字面值创建vector 对象
vector<int> v5{1, 2, 3, 4, 5, 6};    //v5包含1, 2, 3, 4, 5, 6
vector<int> v6 = {9, 8, 7, 6, 5, 4}; //v6包含9, 8, 7, 6, 5, 4
vector<int> v7 = vector<int>(v6);    //v7包含v6全部副本
vector<int> v8(10);                  //10个元素，都是0
vector<string> v9(10);               //10个元素，都是""
```
#### 3.3.2 向vector对象中添加元素

- vector的成员函数push_back()，向vector对象的尾端添加元素
##### 想vector对象添加元素蕴含的编程假定
- 范围for语句体内不应改变其所遍历序列的大小
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1, v2; //空vector对象
    for (int i = 0; i != 100; i++)
        v2.push_back(i); //依次把整数值放到v2尾端
    //循环结束后v2有100个元素，值丛0-99

    //从标准库中读取单词，将其作为vector对象的元素
    /*string word;
    vector<string> text; //空vector对象
    while (cin >> word)
    {
        text.push_back(word); //把word添加到text后面
    }*/
    if (!v2.empty())
        cout << v2.size() << v2[v2.size() - 1] << endl;
    v1 = v2;
    if (!(v1 != v2))
        cout << (v1 == v2) << (v1 < v2) << (v1 > v2) << (v1 <= v2) << (v1 >= v2) << endl;

    for (auto &i : v2)
        i *= i;

    //decltype(v2.size())可以用vector<int>::size_type代替
    for (decltype(v2.size()) i = 0; i < v2.size(); i++)
    {
        if ((i + 1) % 10)
            cout << v2[i] << "\t";
        else
            cout << v2[i] << endl;
    }
    cout << endl;
    //以10分为一个分数段统计成绩单数量：0~9，……，100
    unsigned grade;
    vector<unsigned> scores(11, 0); //11个分数段，全部初始值为0
    while (cin >> grade)            //读取成绩
    {
        if (grade <= 100)         //只处理有效成绩
            ++scores[grade / 10]; //将对应的分数段的计数器加1
    }
    for (unsigned s : scores)
        cout << s << " ";
    cout << endl;
    return 0;
}
```
#### 3.3.3 其他vector操作
- 与string类型相应运算符功能一致，只有当元素的值可以比较时，vector对象才能被比较
##### vector支持的操作
<table>
<tr><td>v.empty()</td><td>//如果v不含有任何元素，返回真；否则返回假</td></tr>
<tr><td>v.size()</td><td>//返回v中元素的个数</td></tr>
<tr><td>v.push_back(t)</td><td>//向v的尾端添加一个值为t的元素</td></tr>
<tr><td>v[n]</td><td>//返回v中第n个位置上元素的引用</td></tr>
<tr><td>v1=v2</td><td>//用v2中元素的拷贝替换v1中的元素</td></tr>
<tr><td>v1={a，b，c...}</td><td>//用列表中元素的拷贝替换v1中的元素</td></tr>
<tr><td>v1==v2</td><td>//v1和v2相等当且仅当它们的元素数量相同且对应位置的元素值都相同</td></tr>
<tr><td>v1!=v2</td><td></td></tr>
<tr><td><，<=，>，>=</td><td>//顾名思义，以字典顺序进行比较</td></tr>
</table>

- vector对象的size_size类型：vector\<T>::size_type
##### 计算vector内对象的索引
##### 不能以下标添加元素
### 3.4 迭代器介绍
- 通用的访问string对象的字符或vector对象的元素的方法，就是迭代器（iterator）
- string对象不属于容器，但和vector及其他几种容器，支持迭代器
- 迭代器类似于指针

#### 3.4.1 使用迭代器
- 获取迭代器不用取地址符，迭代器类型有返回迭代器的成员
- begin 返回指向第一个元素或第一个字符的迭代器
- end 返回容器或string对象尾元素的下一位置，称为尾后迭代器（off-the-end iterator）
- 如果容器为空，begin和end返回的都是尾后迭代器
- 不知道迭代器的类型，用auto类型
##### 迭代器运算符
```cpp
*iter        //返回迭代器iter所指元素的引用
iter->mem    //解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem
++iter       //令iter指向容器中的下一个元素
--iter       //令iter指向容器中的上一个元素
iter1==iter2 //迭代器是否相等，如果两个迭代器指向的是同一个元素或者它们是同一个容器的尾后迭代器
iter1!=iter2 //和上面相反
```
##### 将迭代器从一个元素移动到另一个元素
```cpp
include <iostream>
using namespace std;
int main()
{
    string s("some string");
    if (s.begin() != s.end()) //确保s非空
    {
        auto it = s.begin(); //it表示s的第一个字符
        *it = toupper(*it);  //将当前字符改写成大写形式
    }
    cout << s << endl;
    //依次处理s的字符，直至处理完全部字符或遇到空白
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); //将当前字符改写成大写形式
    cout << s << endl;
    return 0;
}
```
##### 迭代器类型
- 迭代器的类型拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器类型
```cpp
vector<int>::itertor it;       //it能读写vector<int>对象的元素
string::itertor it2;           //it2能读写string对象中的字符
vector<int>::const_itertor it3;//it3只能读，不能写vector<int>对象的元素
string::const_itertor it4;     //it4只能读不能写string对象中的字符
```
*迭代器三种不同含义：迭代器概念本身，容器定义的迭代器类型，某个迭代器对象*
##### begin和end运算符
- cbegin和cend运算符
```cpp
vector<int> v;
const vector<int> cv;
auto it1=v.begin(); //it1对象类型是vector<int>::iterator
auto it2=cv.begin();//it2对象类型是vector<int>::const_iterator
auto it3=v.cbegin();//it3对象类型是vector<int>::const_iterator
```
##### 结合解引用和成员访问操作
- 解引用迭代器可以获得迭代器所指的对象
- 先对迭代器解引用，在访问成员：(*it).empty()
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s("some string");
    if (s.begin() != s.end()) //确保s非空
    {
        auto it = s.begin(); //it表示s的第一个字符
        *it = toupper(*it);  //将当前字符改写成大写形式
    }
    cout << s << endl;
    //依次处理s的字符，直至处理完全部字符或遇到空白
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) //!=与<迭代器与下标的区别
        *it = toupper(*it);                                         //将当前字符改写成大写形式
    cout << s << endl;
    //依次处理text的元素，直至处理完全部元素或遇到为空的元素
    vector<string> text = {"Hello world"," ","Some string"};
    for (decltype(text.cbegin()) it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it<< endl;//只读未写可以用cbegin和cend
    return 0;
}
```
##### 某些对vector对象的操作会使迭代器失效
- 不能在范围for循环中添加元素
- 任何一种可能改变vector对象容量的操作
#### 3.4.2 迭代器运算
vector和string迭代器支持的运算
<table>
<tr><td>iter+n</td><td>迭代器加上一个整数值仍得一个迭代器，迭代器指示的新位置与原来相比向前移动了若干个元素。<br/>结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置</td></tr>
<tr><td>iter-n</td><td>迭代器减去一个整数值仍得一个迭代器，迭代器指示的新位置与原来相比向后移动了若干个元素。<br/>结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置</td></tr>
<tr><td>iter1+=n</td><td>迭代器加法的复合赋值语句，将iter1加n的结果赋给iter1</td></tr>
<tr><td>iter1-=n</td><td>迭代器减法的复合赋值语句，将iter1减n的结果赋给iter1</td></tr>
<tr><td>iter1-iter2</td><td>两个迭代器相减的结果是它们之间的距离，也就是说，将运算符右侧的迭代器向前移动差值个元素后将得到左侧的迭代器。<br/>参与运算的两个迭代器必须指向的是同一个容器中的元素或者尾元素的下一位置</td></tr>
<tr><td>\>、>=、<、<=</td><td>迭代器的关系运算符，如果某迭代器指向的容器位置在另一个迭代器所指位置之前，则说前者小于后者。<br/>参与运算的两个迭代器必须指向的是同一个容器中的元素或者尾元素的下一位置</td></tr>
</table>

##### 迭代器的算术运算
- 迭代器的距离，同一个vector对象迭代器相减，类型为difference_type,带符号整型，可正可负
##### 使用迭代器运算
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> text = {"Hello world", " ", "Some string", "Minrrww", "just for you"};
    //text必须是有序的
    //beg和end表示我们搜索范围
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2; //初始状态下的中间点
    //当还有元素尚未检查并且我们还没找到sought时执行循环
    string sought = "Minrrww";
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)           //我们要找的元素在前半部分吗？
            end = mid;               //如果是，调整搜索范围使得忽略掉后半部分
        else                         //我们要找到元素在后半部分吗？
            beg = mid + 1;           //在mid之后寻找
        mid = beg + (end - beg) / 2; //新的中间点
    }
    cout << *++beg << endl;
    cout << *++mid << endl;
    cout << *++end << endl;
}
```

### 3.5 数组
- 数组是一种类似标准类型vector的数据结构
- 相似：数组也是存放类型相同的对象的容器，这些对象本身没有名字，需要通过其所在位置访问
- 不同：数组的大小确定不变，不能随意向数组中增加元素

#### 3.5.1 定义和初始化内置数组
- 数组是一种符合类型
- 声明形如a[d]，a是数组的名字，d是数组的维度，说明数组中元素的个数，必须大于0
- 数组的维度，编译的时候维度应该是已知的
```cpp
unsigned cnt=42;          //不是常量表达式
constexpr unsigned sz=42; //常量表达式
int arr[10];              //含有10个整数的数组
int *parr[sz];            //含有42个整型指针的数组
//string bad[cnt];        //错误：cnt不是常量表达式
string strs[get_size()];  //当get_size是constexpr时正确；否则错误
```
- 数组的元素被默认初始化
- 函数内部定义内置数组，默认初始化数组含有未定义的值

- 定义数组时必须指定数组的类型，不能用auto关键字
- 数组元素应为对象，不存在引用的数组

##### 显式初始化数组元素
- 显示初始化数组，可以忽略数组的维度
- 初始值的总数量应该比维度小
```cpp
const unsigned sz=3;
int ia1[sz]={0,1,2};      //含有三个元素的数组，元素值分别是0,1，2
int a2[]={0,1,2};         //维度是3的数组
int a3[5]={0,1,2};        //等价于a3[]={0,1,2,0,0}
string a4[3]={"hi","bye"};//等价于a4[]={"hi","bye",""}
int a5[2]={0,1,2};        //错误，初始值过多
```
##### 字符数组的特殊性
- 字符串字面值 默认 结尾处还有一个空字符
```cpp
char a1[]={'C','+',"+'};     //列表初始化，没有空字符
char a2[]={'C','+',"+','\0'};//列表初始化，含显式的空字符
char a3[]="C++";             //自动添加表示字符串结束的空字符
//const char a4[6]="Daniel"; //错误，没有空间可存放空字符
```
##### 不允许拷贝和赋值
- 不能将数组的内容拷贝给其他数组作为初始值，也不能用数组为其他数组赋值

##### 理解复杂的数组声明
- 数组能存放大多数类型的对象
- 数组本身也是对象，允许定义数组的指针及数组的引用
```cpp
int *ptrs[10];         //ptrs是含有10个整型指针元素的数组
//int &refs[10];       //错误：不存在元素是引用的数组
int (*parray)[10]=&arr;//parray 指向一个含有10个整数的数组
int (&arrRef)[10]=arr; //arrRef引用一个含有10个整数的数组
int *(&arry)[10]=ptrs; //arry是数组的引用，该数组含有10个指针
```
- 要理解数组声明的含义，最好的办法是从数组的名字开始按照由内向外的顺序阅读

#### 3.5.2 访问数组的元素
- 与vector和string一样，使用范围for语句或下标运算符来访问
- 数组下标类型：size_t，无符号类型，在cstddef头文件中定义
```cpp
unsigned grade;
unsigned scores[11] = {};     //11个分数段，全部初始化为0
while (cin >> grade)          //读取成绩
{
    if (grade <= 100)         //只处理有效成绩
        ++scores[grade / 10]; //将对应的分数段的计数器加1
}
for (unsigned s : scores)     //对于scores中的每个计数值
    cout << s << " ";         //输出当前的计数值
cout << endl;
```

##### 检查下标的值
- 下标值范围(0,size()]
#### 3.5.3 指针和数组
- 数组名为指向数组第一个元素的指针
- 使用数组名作为auto变量的初始值时，推断出的类型是指针而不是数组
```cpp
string nums[] = {"one", "two", "three"}; //数组的元素是string对象
string *pstr1 = &nums[0];                // pstr1指向nums的第一个元素
string *pstr2 = nums;                    //等价于*pstr2=&nums[0]
cout << *pstr1 << " " << *pstr2 << endl; //输出pstr1,pstr2指向的对象
cout << (pstr1 == pstr2) << endl;        //输出两个指针是否相等

int ia1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia是一个含有10个整数的数组
auto ia2(ia1);                              // ia2是一个整型指针，指向ia的第一个元素。等价于auto ia2(&ia[0])
// ia2 = 43;                                 //错误：ia2是一个指针，不能用int值给指针赋值
cout << ia1[5] << " " << *(ia2 + 5) << endl; //输出ia[5]和ia2+5指针指向的对象
```
- 使用decltype关键字，返回的类型是由10个整数够成的数组
```cpp
//ia3是一个含有10个整数的数组
decltype(ia1) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//ia3 = p;    //错误，不能用整型指针给数组赋值
int i = 10;
ia3[4] = i;   //正确：把i的值付给ia3的一个元素
cout << ia1[4] << " " << *(ia3 + 4) << endl; //对比ia[4]和ia3+4指向的对象
```
##### 指针也是迭代器
- 数组的指针和迭代器一样支持运算
```cpp
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *ip = arr; //ip指向arr的第一个元素
cout << *ip << " ";
++ip; //p指向arr[1];
cout << *ip << endl;
```
- 尾后指针
```cpp
int *e1 = &arr[10]; //指向arr尾元素的下一个位置的指针
cout << e1 << endl; //输出尾后指针
```
- 尾后指针不能解引用或递增操作
##### 标准库函数begin和end
```cpp
int *beg = begin(ia1);                 //指向ia首元素的指针
int *last = end(ia1);                  //指向ia尾元素的下一位置的指针
cout << end(ia1) - begin(ia1) << endl; //输出尾后指针和首指针之间的距离
```
##### 指针运算
- 包括：解引用，递增，比较，与整数相加，两个指针相见等
```cpp
constexpr size_t sz = 5;
int arr1[sz] = {1, 2, 3, 4, 5};
int *ip1 = arr1;                     //等价于int *ip1=&arr[0]
int *ip2 = ip1 + 4;                  //ip2指向arr的尾元素arr[4]
cout << *ip1 << " " << *ip2 << endl; //指针加法

int *ip3 = arr1 + sz; //不能解引用
//int *p2 = arr1 + 10; //错误，arr只有5个元素，p2的值未定义
```
- 两个指针相减的值时它们之间的距离
```cpp
auto n = end(arr1) - begin(arr1); //n的值是5，也是arr中元素的数量
```
- 类型为ptrdiff_t的标准库类型，带符号的类型
- 遍历数组中的元素：
```cpp
int *b = arr1, *e = arr1 + sz;
while (b < e)
{
    cout << *b; //使用*b;
    ++b;
}
cout << endl;
```
##### 解引用和指针运算的交互
```cpp
int ia[] = {0, 2, 4, 6, 8}; //含有5个整数的数组
int last1 = *(ia + 4);      //相当于把ia[4]初始化给last
int last2 = *ia + 4;        //相当于把ia[0]+4初始化给l
cout << last1 << " " << last2 << endl;
```
##### 下标和指针
- 内置的下标运算符所用的索引值不是无符号类型,与vector和string不同
```cpp
int a = ia[2];  //ia转换成指向数组首元素的指针
                //ia[2]得到(ia+2)所指的元素
int *ap = ia;   //ap指向ia的首元素
a = *(ap + 2);  //等价于i=ia[2]
ap = &ia[2];    //ap指向索引为2的元素
int j = ap[1];  //ap[1]等价于*(p+1),就是ia[3]表示的那个元素
int k = ap[-2]; //ap[-2]等价于*(ap-2),就是ia[0]表示的那个元素
cout << a << " " << j << " " << k << endl;
```
#### 3.5.4 C风格字符串
- C风格字符串（C-style character string）
- 尽量不用C风格字符串，不方便，极易引发程序漏洞
- C风格字符串 不是一种类型
- 字符串字面值 此字符串存放字符数组并以空字符结束（null terminated）
##### C标准库String函数
- 定义在cstring头文件中
<table>
<tr><td>strlen(p)</td><td>返回p的长度，空字符不计算在内</td></tr>
<tr><td>strcmp(p1,p2)</td><td>比较p1和p2的相等性。如果p1 == p2，返回0；<br/>如果p1 > p2，返回一个正值；如果p1 < p2，返回一个负值</td></tr>
<tr><td>strcat(p1,p2)</td><td>将p2附加到p1之后，返回p1</td></tr>
<tr><td>strcpy(p1,p2)</td><td>将p2拷贝给p1,返回p1</td></tr>
</table>

- 上述函数不负责验证其字符串参数
- 此类函数的指针必须指向以空字符作为结束的数组
```cpp
char ca[]={'C','+','+'};//不以空字符结束
cout<<strlen(ca)<<endl;//错误，ca没有以空字符结束
```
##### 比较字符串
```cpp
string s1="A string example";
string s2="A different string";
if(s1<s2)//false:s2<s1
```
- C风格字符串比较，实际比较的将是指针而非字符串本身
```cpp
const char ca1[]="A string example";
const char ca2[]="A different string";
if(ca1<ca2)//未定义的：试图比较两个无关地址
```
- 调用strcmp函数，两个字符串相等，strcmp返回0；前面字符串较大，返回正值
- 后面字符串较大，返回负值
```cpp
if(strcmp(ca1,ca2)<0)//和if(s1<s2)效果一样
```
##### 目标字符串的大小由调用者指定
```cpp
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    string s1 = "A string example"; //声明并定义一个string类型s1
    cout << ++n;                    //1
    //用下标输出s1每一个字符
    for (decltype(s1.size()) i = 0; i != s1.size(); i++)
    {
        s1[i] = char(s1[i] + 1); //使用下标修改字符
        cout << s1[i];           //用下标输出s1每一个字符
    }
    cout << endl;

    vector<char> vc(s1.begin(), s1.end());
    //用下标输出vc每一个字符
    for (decltype(vc.size()) i = 0; i != vc.size(); i++)
    {
        vc[i] = char(vc[i] + 1); //使用下标修改字符
        cout << vc[i];           //用下标输出s1每一个字符
    }
    cout << endl;

    //范文for循环修改字符
    for (auto &st1 : s1)
        st1 = st1 + 1;
    cout << ++n; //2
    //用迭代器输出重s1新赋值后d的每一个字符
    for (auto i = s1.begin(); i != s1.end(); i++)
        cout << *i;
    cout << endl;

    string s2 = "A different string";    //声明并定义一个string类型s2
    cout << ++n;                         //3
    cout << s1 << " " << s2 << endl;     //用输出流连接s1,s2
    cout << ++n;                         //4
    cout << (s1 < s2 ? s1 : s2) << endl; //比较s1,s2大小,因s1>s2,输出s2
    string largeStr = s1 + " " + s2;     //string对象相加
    cout << ++n;                         //5
    cout << largeStr << endl;

    //指针不能指向表达式和字面值，但是可以指向字符串字面值，把字符串字面值看着字符数组
    char *const cap1 = "A string example"; //定义一个指针cap1，指向字符串字面值
    //不能改变cap1的值，只能看着指向常量字符数组
    cout << ++n; //6
    //用下标输出cap1每一个字符，用sizeof运算符不能全部输出，用strlen
    //strlen不包括字符串末尾的空字符'\0'
    for (decltype(strlen(cap1)) i = 0; i != strlen(cap1); i++)
        cout << cap1[i];
    /*不支持范围for循环，迭代器
    for (auto st1 : cap1)
        cout << st1;
    cout << endl;
    for (auto i = begin(cap1); i != end(cap1); i++)
        cout << cap1[i];
    cout << endl;
    */
    cout << endl;
    cout << ++n;                         //7
    cout << cap1 << endl;                //直接输出指针，输出字符数组
    cout << ++n;                         //
    cout << *cap1 << endl;               //输出解引用，输出指针指向的首字符
    cout << ++n;                         //9
    cout << cap1 + 1 << endl;            //支持指针运算，输出还是字符数组
    cout << ++n << endl;                 //10
    cout << cap1 + strlen(cap1) << endl; //输出最后一个字符，即'\0'
    cout << ++n << endl;                 //11
    cout << cap1 + 17 << endl;           //超范围输出看紧邻定义的常量，字符串字面值在同一内存区域？
    cout << ++n << endl;                 //12
    cout << *(cap1 + 17) << endl;        //超范围输出指针解引用？不知道输出为空？

    char *const cap2 = "A different string"; //定义一个指针cap2，指向字符串字面值
    char largetCap[37];                      //定义一个字符数组，它的大小会影响输出结果
    strcpy(largetCap, cap1);                 //将cap1拷贝给largetCap
    strcat(largetCap, " ");                  //将largetCap末尾加上一个空格
    strcat(largetCap, cap2);                 //将cap2连接到largetCap后面
    cout << ++n;                             //13
    cout << largetCap << endl;               //largetCap的长度影响输出结果
    cout << ++n;                             //14
    //比较指针，不管怎么理解编译器，只能说无意义
    cout << (cap1 < cap2 ? cap1 : cap2) << endl;
    cout << ++n; //15
    //比较字符串大小，'s'>'d',所以cap1指向的数组大于cap2指向的数组
    //strcmp(cap1,cap2)返回正值，条件为假，输出cap2
    cout << (strcmp(cap1, cap2) < 0 ? cap1 : cap2) << endl;

    char ca1[] = "A string example"; //声明并定义一个字符数组ca1
    cout << ++n;                     //16
    //用下标输出s1每一个字符
    for (decltype(strlen(ca1)) i = 0; i != strlen(ca1); i++)
        cout << ca1[i];
    cout << endl;

    //范文for循环为每一字符赋值
    for (auto &st1 : ca1)
        st1 = st1 + 1;
    cout << ++n; //17
    //用迭代器输出重s1新赋值后d的每一个字符
    for (auto i = begin(ca1); i != end(ca1); i++)
        cout << *i;
    cout << endl;

    const char ca2[] = "A different string"; //声明并定义一个字符数组ca2
    char largetCh[36];                       //定义一个空字符数组
    strcpy(largetCh, ca1);                   //将ca1拷贝给largetCh
    strcat(largetCh, " ");                   //将largetCh末尾加上一个空格
    strcat(largetCh, ca2);                   //将ca2连接到largetCh后面
    cout << ++n;                             //18
    cout << largetCh << endl;
    cout << ++n;                               //19
    cout << ca1 + 7 << " " << ca2 + 7 << endl; //支持指针运算
    cout << ++n;                               //20
    //比较指针，比较两个不同对象的指针无意义
    cout << (ca1 > ca2 ? ca1 : ca2) << endl;
    cout << ++n; //21
    //比较字符串大小，'B'>'A',所以cap1指向的数组大于cap2指向的数组
    //strcmp(cap1,cap2)返回正值，条件为假，输出cap2
    cout << (strcmp(ca1, ca2) < 0 ? ca1 : ca2) << endl;
    return 0;
}
/*输出结果很奇怪，所以尽量不用C风格字符串
```
#### 3.5.5 与旧代码的接口
##### 混用string对象和C风格字符串
- 允许使用以空字符结束的字符数组来初始化string对象或为string对象赋值
- 在string对象的加法运算中允许使用以空字符结束的字符数组作为其中一个运算对象<br/>（不能两个对象都是）；在string对象的复合赋值运算中允许使用以空字符结束的字<br/>符数组作为右侧的运算对象。

- 不能将string对象直接赋值给指向字符的指针，需要通过c_str的成员函数
```cpp
char *str=s;//错误：不能用string对象初始化char*
const char *str=s.c_str();//正确
```
##### 使用数组初始化vector对象
```cpp
int int_arr[]={0,1,2,3,4,5};
vector<int> ivec(begin(int_arr),end(int_arr));//数组的全部初始化vector对象
vector<int> subVec(int_arr+1,int_arr+4);//数组的部分初始化vector对象
```
### 3.6 多维数组
- 多维数组是数组的数组
- 理解多维数组，按照由内而外的顺序阅读
```cpp
int ia[3][4];//大小为3的数组，每个元素是含有4个整数的数组
```
#### 多维数组的初始化
```cpp
ia[3][4]={
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
};
//等同于
ia[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};

//显式地初始化每行的首元素
ia[3][4]={{0}, {4},{8}};
//与下面的初始化完全不同
ia[3][4]={0,4,8};

//显式地初始化第一行
ia[3][4]={0,1,2,4};
```
##### 多维数组的下标引用
```cpp
ia[2][3] = arr[8][9][10]; //赋值
int (&row)[4]=ia[1]//把引用row绑定到ia的第二个数组上
```
##### 使用范围for语句处理多维数组
##### 指针和多维数组
##### 类型别名简化多维数组的指针
```cpp
// p是指针，指向维度是4的数组，数组的元素类型是整数
// p指向第一层数组ia[],p=&ia[]
int (*p)[4] = ia; // p指向含有4个整数的数组,用ia数组的首地址初始化auto p=ia;
p = &ia[2];       // p指向ia的尾元素
cout << *(*p) << endl;

//指针遍历多维数组
for (int (*p)[4] = ia; p != ia + (end(ia) - begin(ia)); p++)
{
    for (auto q = *p; q != *p + (end(*p) - begin(*p)); q++) //数组迭代器距离的数据类型ptrdiff_t
    {
        cout << *q << " ";
    }
}
cout << endl;

using int_array = int[4]; //新标准下类型别名声明
typedef int intArray;     //等价的typedef 类型别名声明
for (int_array *p = ia; p != ia + (end(ia) - begin(ia)); p++)
{
    for (intArray *q = *p; q != *p + (end(*p) - begin(*p)); q++) //数组迭代器距离的数据类型ptrdiff_t
    {
        cout << *q << " ";
    }
}
cout << endl;
```
- 几种遍历数组的方法比较
```cpp
#include <iostream>
using namespace std;
int main()
{
    //大小为3的数组，每个元素是含有4个整数的数组
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //大小为10的数组，每个元素都是大小为20的数组
    //这些数组的元素是含有30个整数的数组
    int arr[10][20][30] = {11};                 //将所有元素初始化为0
    cout << ia[2][3] << endl;                   //下标输出
    cout << *(*(ia + 2) + 3) << endl;           //解引用输出
    cout << *(end(*(end(ia) - 1)) - 1) << endl; //迭代器解引用
    ia[2][3] = arr[0][0][0];                    //赋值
    cout << ia[2][3] << endl;                   //下标输出
    cout << *(*(ia + 2) + 3) << endl;           //解引用输出
    cout << *(end(*(end(ia) - 1)) - 1) << endl; //迭代器解引用
    //把引用row绑定到ia的第二个数组上,引用的是一个数组名(指针变量)
    int(&row)[4] = ia[1];
    cout << *row << endl;
    //迭代器给多维数组赋值

    for (auto i = begin(ia); i != end(ia); i++)
    {
        for (auto j = begin(*i); j != end(*i); j++)
        {
            *j = *j * *j; //赋值
            cout << *j << " ";
        }
    }
    cout << endl;

    //下标遍历多维数组
    for (decltype(end(ia) - begin(ia)) i = 0; i != end(ia) - begin(ia); i++)
    {
        for (ptrdiff_t j = 0; j != end(ia[i]) - begin(ia[i]); j++) //数组迭代器距离的数据类型ptrdiff_t
        {
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;

    //范围for语句遍历多维数组
    //改变数组元素的值，row、col需要定义为引用
    //不改变数组元素的值，row需要定义为引用，避免数组被自动转成指针
    //如果row不定义为引用，row会被认为是指向首元素int *类型的指针
    //内循环就不合法了
    for (const auto &row : ia)
        for (auto col : row)
            cout << col << " ";
    cout << endl;

    //p是指针，指向维度是4的数组，数组的元素类型是整数
    //p指向第一层数组ia[],p=&ia[]
    //int(*p)[4] = ia; //p指向含有4个整数的数组,用ia数组的首地址初始化auto p=ia;
    //p = &ia[2];//p指向ia的尾元素
    //cout << *(*p) << endl;
    //指针遍历多维数组
    for (int(*p)[4] = ia; p != ia + (end(ia) - begin(ia)); p++)
    {
        for (auto q = *p; q != *p + (end(*p) - begin(*p)); q++) //数组迭代器距离的数据类型ptrdiff_t
        {
            cout << *q << " ";
        }
    }
    cout << endl;

    //类型别名简化多维数组的指针
    using int_array = int[4]; //新标准下类型别名声明
    typedef int intArray;     //等价的typedef 类型别名声明
    for (int_array *p = ia; p != ia + (end(ia) - begin(ia)); p++)
    {
        for (intArray *q = *p; q != *p + (end(*p) - begin(*p)); q++) //数组迭代器距离的数据类型ptrdiff_t
        {
            cout << *q << " ";
        }
    }
    cout << endl;

    return 0;
}
```
### 术语表
- `begin` 是string和vector的成员，返回指向第一个元素的迭代器。也是一个标准库函数，输入一个数组，返回指向该数组首元素的指针。
- `缓冲区溢出（buffer overflow）`一种严重的程序故障，主要的原因是试图通过一个越界的索引访问容器内容，容器类型包括string、vector和数组等。
- `C风格字符串（C-style string）`以空字符结束的字符数组。字符串字面值是C风格字符串，C风格字符串容易出错。
- `类模板（class template）`用于创建具体类类型的模板。要想使用类模板，必须提供关于类型的辅助信息。例如，要定义一个vector对象需要指定元素的类型：
- `vector<int>`包含int类型的元素。
- `编译器扩展（compiler extension）`某个特定的编译器为C++语言额外增加的特性。基于编译器扩展编写的程序不易移植到其他编译器上。
- `容器（container）`是一种类型，其对象容纳了一组给定类型的对象。vector是一种容器类型。
- `拷贝初始化（copy initialization）`使用赋值号（=）的初始化形式。新创建的对象是初始值的一个副本。
- `difference_type`由 string 和vector定义的一种带符号整数类型，表示两个迭代器之间的距离。
- `直接初始化（direct initialization）`不使用赋值号（=）的初始化形式。
- `empty`是string和vector的成员，返回一个布尔值。当对象的大小为0时返回真，否则返回假。
- `end`是string和vector的成员，返回一个尾后迭代器。也是一个标准库函数，输入一个数组，返回指向该数组尾元素的下一位置的指针。
- `getline`在string头文件中定义的一个函数，以一个istream对象和一个string对象为输入参数。该函数首先读取输入流的内容直到遇到换行符停止，然后将读入的数据存入string对象，最后返回istream对象。其中换行符读入但是不保留。
- `索引（index）`是下标运算符使用的值。表示要在string对象、vector对象或者数组中访问的一个位置。
- `实例化（instantiation）`编译器生成一个指定的模板类或函数的过程。
- `迭代器（iterator）`是一种类型，用于访问容器中的元素或者在元素之间移动。
- `迭代器运算（iterator arithmetic）`是string 或vector的迭代器的运算：迭代器与整数相加或相减得到一个新的迭代器，与原来的迭代器相比，新迭代器向前或向后移动了若干个位置。两个迭代器相减得到它们之间的距离，此时它们必须指向同一个容器的元素或该容器尾元素的下一位置。
- `以空字符结束的字符串（null-terminated string）`是一个字符串，它的最后一个字符后面还跟着一个空字符（\0）。
- `尾后迭代器（off-the-end iterator）`end函数返回的迭代器，指向一个并不存在的元素，该元素位于容器尾元素的下一位置。
- `指针运算（pointer arithmetic）`是指针类型支持的算术运算。指向数组的指针所支持的运算种类与迭代器运算一样。
- `prtdiff_t`是cstddef头文件中定义的一种与机器实现有关的带符号整数类型，它的空间足够大，能够表示数组中任意两个指针之间的距离。
- `push_back`是vector的成员，向vector对象的末尾添加元素。
- `范围for 语句（range for）`一种控制语句，可以在值的一个特定集合内迭代。
- `size`是string和vector的成员，分别返回字符的数量或元素的数量。返回值的类型是size type。
- `size_t`是cstddef头文件中定义的一种与机器实现有关的无符号整数类型，它的空间足够大，能够表示任意数组的大小。
- `size_type`是string和vector定义的类型的名字，能存放下任意string对象或vector对象的大小。在标准库中，size type被定义为无符号类型。
- `string`是一种标准库类型，表示字符的序列。
- `using 声明（using declaration）`令命名空间中的某个名字可被程序直接使用。using 命名空间::名字；上述语句的作用是令程序可以直接使用名字，而无须写它的前缀部分命名空间::。
- `值初始化（value initialization）`是一种初始化过程。内置类型初始化为0，类类型由类的默认构造函数初始化。只有当类包含默认构造函数时，该类的对象才会被值初始化。对于容器的初始化来说，如果只说明了容器的大小而没有指定初始值的话，就会执行值初始化。此时编译器会生成个值，而容器的元素被初始化为该值。
- `vector`是一种标准库类型，容纳某指定类型的一组元素。
- `++运算符（++operator）`是迭代器和指针定义的递增运算符。执行“加1”操作使得迭代器指向下一个元素。
- `[]运算符（[]operator）`下标运算符。obj[j]得到容器对象obj中位置的那个元素。索引从0开始，第一个元素的索引是0，尾元素的索引是obj.size（）-1。下标运算符的返回值是一个对象。如果p是指针、n是整数，则p[n]与*（p+n）等价。
- `->运算符（->operator）`箭头运算符，该运算符综合了解引用操作和点操作。a->b等价于（*a）.b。
- `<<运算符（<<operator）`标准库类型string定义的输出运算符，负责输出string对象中的字符。
- `>>运算符（>>operator）`标准库类型string定义的输入运算符，负责读入一组字符，遇到空白停止，读入的内容赋给运算符右侧的运算对象，该运算对象应该是一个string对象。
- `!运算符（!operator）`逻辑非运算符，将它的运算对象的布尔值取反。如果运算对象是假，则结果为真，如果运算对象是真，则结果为假。
- `&&运算符（&&operator）`逻辑与运算符，如果两个运算对象都是真，结果为真。只有当左侧运算对象为真时才会检查右侧运算对象。
- `||运算符（|| operator）`逻辑或运算符，任何一个运算对象是真，结果就为真。只有当左侧运算对象为假时才会检查右侧运算对象。
