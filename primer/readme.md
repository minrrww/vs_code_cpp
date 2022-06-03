#primer学习笔记

##==第一章 开始==
###1.2 iostream库

<table>
  <tr >
    <td align="center">库</td>
    <td align="center">类型</td>
    <td align="center">对象</td>
  </tr>
  <tr>
    <td rowspan=4>iostream</td>
    <td>istream 输入流</td>
    <td>cin 标准输入 </td>
  </tr>
  <tr>
    <td rowspan=3>istream 输入流</td>
    <td>cout 标准输出对象</td>
  </tr>
  <tr>
    <td>err 输出警告和错误信息</td>
  </tr>
  <tr>
    <td>clog 输出程序运行时的一般信息 </td>
  </tr>
</table>

**例1.2 输入两个数，求它们的和**
``````
#include <iostream> //#include 指令:告诉编译器，需要用iostream库
int main()
{
    //提示用户输入两个数
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;   //保存我们读入的输入数据的变量
    std::cin >> v1 >> v2; //读取输入数据
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
``````
- << 输出运算符
  - ostream类型的对象<<右值
    - 将右值写入ostream类型的对象中，返回ostream类型的对象作为计算结果
- \>> 输入运算符
  - istream类型的对象>>右值
    - 将读取的值存入右值，写入istream类型的对象中，并返回istream类型的对象作为计算结果
---
- endl操纵符
  - 结束当前行，并将设备关联的缓冲区中的内容刷到设备中
---
- std 命名空间
  - cout endl cin等对象是定义在命名空间std中的
  - :: 作用域运算符

---
### 1.4 控制流
#### 1.4.1 while语句
- while (condition) statement；【*while(条件)循环体；*】
  - 检测condition条件，为真时执行statement，为假时停止。
  - condition条件为一个真或假的表达式。

**例1.4.1 计算1~10的和**
``````
#include <iostream>
using namespace std;
int main()
{
    int sum = 0, val = 1;
    //只要val的值小于等于10，while循环就会持续执行
    while (val <= 10)
    {
        sum += val; //将sum+val赋值给sum
        ++val;      //将val+1赋值给val
    }
    cout << "Sum of 1 to 10 inclusive is "
         << sum << endl;
    return 0;
}
``````
---
#### 1.4.2 for 语句
  - for(init-statement,condition,expression)statement； 【*for(初始化语句,条件,表达式)循环体；*】
    - 检测condition条件，为真时执行statement，为假时停止。

**例1.4.2 计算1到10的和**
``````
#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    //从1加到10
    for (int val = 1; val <= 10; ++val)
    {
        sum += val; //将sum+val赋值给sum
    }
    cout << "Sum of 1 to 10 inclusive is "
         << sum << endl;
    return 0;
}
``````
---
#### 1.4.3 读取数量不定的输入数据
**例1.4.3 读取数据直到遇到cin无效，计算所有读入的值得和**
``````
#include <iostream>
using namespace std;
int main()
{
    int sum = 0, value = 0;
    //windows系统文件结束符ctrl+z，enter;linux系统文件结束符ctrl+d
    //返回的cin对象无效指遇到文件结束符（end-of-file）或无效输入
    while (cin >> value)
        sum += value; //将sum+val赋值给sum
    cout << "Sum is: "
         << sum << endl;
    return 0;
}
``````
---
#### 1.4.4 if 语句
  - if(condition) statement1; else statemnt2; 【*if(条件) 循环体1; else 循环体2;*】
    - 条件为真，执行循环体1，否则，执行循环体2

**例1.4.4 统计连续输入相同数的个数**

``````
#include <iostream>
using namespace std;
int main()
{
    //currVal是我们正在统计的数；我们将读入的新值存入val
    int currVal = 0, val = 0;
    //读取第一个数，并确保实有数据可以处理
    if (cin >> currVal)
    {
        int cnt = 1; //保存我们正在处理的当前值的个数
        while (cin >> val)
        {                       //读取剩余的数
            if (val == currVal) //如果值相同
                ++cnt;          //cnt自加1
            else
            { //否则，打印前一个值得个数
                cout << currVal << " occurs "
                     << cnt << " times" << endl;
                currVal = val; //记住新值
                cnt = 1;       //重置计数器
            }
        } //while循环在这里结束
        //记住打印文件中最后一个值得个数
        cout << currVal << " occurs "
             << cnt << " times" << endl;
    } //最外层的if语句在这里结束
    return 0;
}
``````
---
- 编译器检查程序错误
  - 语法错误（syntax error）
  - 类型错误（type error）
  - 声明错误（declaration error）
    - 每个名字都要先声明后使用
---

### 1.5 类简介
#### 1.5.1 Sales_item类
**例1.5.1 计算售出书籍的和**
``````
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
``````
``````
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
``````
---
#### 1.5.2 初识成员函数
**例1.5.2 检查是否为相同书籍**
``````
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
``````
---
### 1.6 书店程序
**例1.6 记录销售相同书籍的数量**
``````
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
``````
---
## ==第二章 变量和基本类型==
### 2.1 基本内置类型
- 算术类型（arithmetic tyoe）：整型和浮点数
  - 整型（integral type）：字符、整型数、布尔值
- 空类型（void）
---
#### 2.1.1 算术类型
**表2.1.1.1 C++算术类型**

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

---
- 带符号类型和不带符号类型
**表2.1.1.2 signed与unsigned**

| 默认类型 | signed      | unsigned           |
| -------- | ----------- | ------------------ |
| char     | signed char | unsigned char      |
| short    | short       | unsigned short     |
| int      | int         | unsigned int       |
| long     | long        | unsigned long      |
| long     | long        | unsigned long long |

---
#### 2.1.2 类型转换
---
#### 2.1.3 字面值常量
- 字符与字面值
**表2.1.3.1 字面值例子**

| 字面值名称 | 字面值例子        |
| ---------- | ----------------- |
| 二进制     | 0b11              |
| 十进制     | 20                |
| 八进制     | 024               |
| 十六进制   | 0x14              |
| 浮点数     | 3.14159 3.14159e0 |
| 字符       | 'a'               |
| 字符串     | "Hello world"     |
| bool       | true false        |
| 指针       | nullptr           |

---
- 转义序列
**表2.1.3.2 转移序列**

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

---
- 指定字面值的类型
**表2.1.3.3 前缀后缀**

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

---
### 2.2 变量

#### 2.2.1 变量定义
- 初始值
  - 初始化：创建变量并赋初值
  - 赋值：擦出当前值，以新值替代
- 列表初始化
  - 一组用花括号括起来的初始值
- 默认初始化
  - 定义于任何函数体外地变量被初始化为0
  - 定义在函数体内部的内置类型变量将不被初始化
---
#### 2.2.2 声明变量和定义的关系
- 声明非定义
``````
extern int i;//extern 只声明不赋值
``````
- 声明并定义
``````
int j;//声明并定义j
``````
- 定义非声明
``````
extern double pi=3.1416；//显式初始化的声明不在时声明，是定义
``````
---
- 函数体内部初始化extern标记的变量，将引发错误
- 变量可以被多次声明，能且只能被定义一次
---
#### 2.2.3 标识符
- 标识符（identifier）由字母、数字和下划线组成，必须以字母或下划线开头，大小写敏感
---
- 变量命名规范
  - 标识符要能体现实际含义
  - 变量名一般用小写字母
  - 用户自定义的类名一般以大写字母开头
  - 如果标识符由多个单词组成，则单词间应有明显区分（驼峰命名法：小驼峰法：变量；大驼峰法：类名，命名空间，属性等）

**表2.2.3.1：C++关键字**
| 0   | 1          | 2            | 3         | 4                | 5        |
| --- | ---------- | ------------ | --------- | ---------------- | -------- |
| 1   | alingnas   | continue     | friend    | register         | true     |
| 2   | alignof    | decltype     | goto      | reinterpret_cast | try      |
| 3   | asm        | default      | if        | return           | typedef  |
| 4   | auto       | delete       | inline    | short            | typeid   |
| 5   | bool       | do           | int       | signed           | typename |
| 6   | break      | double       | long      | sizeof           | union    |
| 7   | case       | dynamic_cast | mutable   | static           | unsigned |
| 8   | catch      | else         | namespace | static_assert    | using    |
| 9   | char       | enum         | new       | static_cast      | virtual  |
| 10  | char16_t   | explicit     | noexcept  | struct           | void     |
| 11  | char32_t   | export       | nullptr   | switch           | volatile |
| 12  | calss      | extern       | operator  | template         | wchar_t  |
| 13  | const      | false        | private   | this             | while    |
| 14  | constexpr  | float        | protected | thread_local     |          |
| 15  | const_cast | for          | public    | throw            |          |
**表2.2.3.2：C++操作符替代名**
| 1   | 2      | 3     | 4      | 5     | 6      | 7      | 8     | 9   | 10  | 11  |
| --- | ------ | ----- | ------ | ----- | ------ | ------ | ----- | --- | --- | --- |
| and | bitand | compl | not_eq | or_eq | xor_eq | and_eq | bitor | not | or  | xor |

---
#### 2.2.4 名字的作用域
C++大多数作用域都以{}分隔

同一名字在不同作用域中可能指向不同的实体
名字的有效区域始于声明，结束于作用域末端

全局作用域 块作用域

嵌套的作用域 被包围的作用域称内层作用域，相对的为外层作用域
内层作用域可以访问外层作用域
内层作用域可以重新定义外层作用域的名字

2.3 复合类型：引用和指针
声明符语句：基本数据类型（base type） 声明符（declarator）
简单的声明符就是变量
复杂的声明符，基于简单的声明符得到更复杂的类型，并把它指定给变量

2.3.1 引用
一般引用指左值引用（lvalue reference），另一种右值引用（rvalue reference）

引用（reference）为对象起别名
引用类型必须引用（refers to）另外一种类型的对象（引用必须被初始化）
引用的定义：每个引用变量名必须紧跟&
int i=1024,j=2048;
int &ri=i,&rj=j;
所以int &可以看成int型的引用类型，ri,rj看成引用变量
为了连续声明几个引用，int 和 &ri分开
引用不是对象，必须初始化，给引用变量赋值，就是给所引用的对象赋值，可以看成常量指针

2.3.2 指针
指针（pointer）是“指向（point to）”另外一种类型的符合类型
指针本身是一个对象，可以赋值和拷贝，同一指针可以先后指向不同对象
块作用域中定义未初始化的指针，拥有一个不确定的值
int *ip1,*ip2;指向int类型对象的指针
int *看作int型的指针类型，ip1,ip2看作指针对象

取地址符&
int *ip=&ival;

指针值
1.指向一个对象
2.指向紧邻对象所占空间的下一个位置
3.空指针，指针没有指向任何对象
4.无效指针，上述之外的其他值
拷贝或访问无效指针都将发生错误

解引用符*
*p 表示指针指向的对象

int i=42;
int &r=i; 引用
int *p; 指针
p=&i; 取地址符
*p=i;解引用符
int &r2=*p;引用与解引用符
声明语句中&和*用于组成符合类型，表达式中，转变为运算符

空指针
int *p1=nullptr;//等同 int *p1=0;
int *p2=0;

#include <cstdlib>
int *p3=NULL;//等同 int *p3=0;

赋值和指针
赋值永远改变的是左值

void *指针
可以存放任意对象的地址
作用：和别的指针比较、作为函数的输入或输出、赋值给另外一个void*指针
不能直接操作void *指针所指对象

2.3.3 理解符合类型的声明

2.3.4 指向指针的指针
int ival=1024;
int *pi=&ival;
int **ppi=&pi;
指向指针的引用
int i=42;
int *p;
int *&r=p;//指针类型对象的引用

r=&i;//给引用变量赋值改变的事所引用的对象p的值
*r=0;//*r解引用得i,p指向的对象，i的值改为0


2.4 const 限定符
const 限定的变量不能改变值，叫做常量，常量只能初始化不能单独赋值
被const限定的变量能参与运算，不能改变自身的值
默认情况下，const对象仅在文件内有效

声明 extern int i;//extern 只声明不赋值
extern int i=14；//同int i=14;强行赋值等同声明并定义
int j;//声明并定义j
变量可以被多次声明，能且只能被定义一次。
区别：声明可以多次，因此声明extern  int i;可以多次出现
而声明并定义只能一次出现：int j;extern int i=14;

extern const int bufSize=fcn();//声明并定义一个常量,可以被外部文件访问，只能出现一次
extern const int bufSize;//声明一个常量，可以被外部文件访问，可以出现多次

2.4.1 const 的引用
对常量的引用（reference to const）
不能修改被绑定的值，不能给对常量的引用赋值
普通引用不能引用常量

初始化和对const的引用
引用的类型必须与其所引用对象的类型一致，但有例外
1.表达式（表达式可以转换成引用类型），
2.非常量对象（不能通过常量引用改变非常量对象的值）

常量引用（const限定的引用的简称）可以引用非常量对象、字面值、表达式

2.4.2 指针和const
指向常量的指针（pointer to const）不能用于改变其所指对象的值
想存放常量对象的地址，只能使用指向常量的指针；
指针类型必须和所指对象的类型一致，有两个例外：
1.指向常量的指针指向一个非常量的对象；
2.const 指针，将指针本身定位常量，常量指针（const pointer）必须初始化
const double pi=3.14159;
const double *const pip=&pi;//指向常量的常量指针（指针本身是常量，同时指向一个常量对象）
int errNumb=1;
int *const curErr=&errNumb;
*curErr=0;//指向非常量的常量指针，可以改变所指对象的值

不是指向常量的引用，不能引用常量，表达式，字面值
指向常量的引用，可以引用常量，表达式，字面值，非常量对象

指针不能指向表达式，字面值
非指向常量的指针不能指向常量对象
指向常量的指针可以指向常量，非常量对象
常量指针自身的值不能改变
常量指针可以改变其指向的非常量对象的值
（rnm，绕来绕去的，脑壳痛）


2.4.3 顶层const
顶层const（top-level-const）表示指针本身是个常量
底层const（low-level-const）表示指针指向的对象是常量
这是两个相互独立的问题
顶层const可以表示任意的对象是常量
指针类型即可以是顶层const，也可以是底层const

int i=0;
int *const p1=&i;//不能改变p1的值，顶层const
const int ci=42;//不能改变ci的值，顶层const
const int *p2=&ci;//允许改变p2的值，底层const
const int *const p3=p2;//左侧const是底层const，右侧const是顶层const
const int &r=ci;//用于声明引用的const都是底层const
执行拷贝操作时，顶层const不受影响，底层const则必须类型一致，或能转换类型
i=ci;//不受影响
p2=p3;//指向的类型相同，p3的顶层const部分不受影响
//int *p=p3;//错误，p3含底层const，p没有
p2=&i;//int*能转换成const int*
//int &r=ci;//错误，普通的int &不能绑定到int 常量上
const int &r2=i;//const int &可以绑定到一个普通int上

2.4.4 constexpr 和常量表达式
常量表达式（const expression）是指不会改变并且在编译过程就能得到计算结果的表达式
用常量表达式初始化的const对象也是常量表达式

允许将变量声明为constexpr类型，以便由编译器来验证变量的值是否是一个常量表达式
声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化
constexpr函数，足够简单，编译时就可以计算其结果
可以用constexpr函数初始化constexpr变量

字面值类型
算术类型、引用、指针、constexpr类型都属于字面值类型

指针和引用都能定义成constexpr，constexpr指针必须初始值是nullptr或者0，或者是存储于某固定地址中的对象
constexpr 指针能绑定固定地址的变量，constexpr指针能指向固定地址的变量

指针和constexpr
consttexpr 声明中定义类一个指针，限定符constexpr仅对指针有效，与指针指向的对象无关
const int *p=nullptr;//指向常量的指针 底层const
constexpr int *q=nullptr;//常量指针 顶层const
int j=0;
constexpr int i=42;//i的类型是整型常量
//i和j必须定义在函数体外（固定地址）
constexpr const int *p=&i;//常量指针p指向整型常量i
constexpr int *p=&j;//p1是常量指针，指向整数j


2.5.1 类型别名
1.typedef 关键词
typedef double wages;//wages 是double的同义词
typedef wages base, *p;//base 是double 的同义词，p是double *的同义词

2.别名声明（alias declaration）
using SI=SalesItem;//SI是SalesItem的同义词

3.指针、常量和类型别名
typedef char *pstring;//pstring与char *同义
const pstring cstr=0;//cstr是const pstring类型的变量，即指向char类型的对象的常量指针
const pstring *ps;//ps是指向const pstring类型对象的指针变量，它指向的对象是指向char类型的对象的常量指针

2.5.2 auto 类型说明符
把表达式赋值给变量，如果不知道表达式的类型，用auto类型说明符
auto定义的变量必须有初始值
auto在一条语句中声明多个变量，变量的初始基本数据类型必须一样

复合类型、常量和auto
1.使用引用作为初始值时，编译器把引用的对象的类型作为auto的类型
2.auto 一般会忽略掉顶层const，同时底层const会保留下来
const int ci=i;&cr=ci;
auto b=ci;//b是一个整数（ci的顶层const被忽略）
auto c=cr；//c是一个整数（cr是ci的别名）
auto d=&i;//d是一个整型指针
auto e=&ci;//e是一个指向整数常量的指针，对常量去地址是底层const
3.希望推断出的auto类型是一个顶层const，需要明确指出：
const auto f=ci;
4.可以将引用得类型设为auto，
auto &g=ci;//g是一个整型常量引用，绑定到ci
//auto &h=42;//错误，不能为非常量引用绑定字面值
const auto &j=42;//可以为常量引用绑定字面值
5.设置一个类型为auto的引用时，初始值的顶层常量属性仍然保留
6.在同一条语句中定义多个变量，&和*只从属于某个声明符，而非基本数据类型的一部分
auto k=ci，&l=i;
auto &m=ci,*p=&ci;
//错误：i的类型是int而&ci的类型是const int
//auto &n=i,*p2=&ci;

2.5.3 decltype 类型指示符
1.希望从表达式的类型推断出要定义的变量的类型，但不想用该表达式的值初始化变量
decltype(f()) sum=x;//sum的类型就是函数f()d 返回类型
decltype返回该变量的类型（包括顶层const和引用在内）
const int ci=0,&cj=ci;
decltype(ci) x=0;//x的类型是const int
decltype(cj) y=x;//y的类型是const int &,y绑定到变量x
//decltype(cj) z;//错误，z是一个引用，必须初始化
引用都是作为所指对象的同义词出现，用在decltype处例外，表示自己

2.decltype 和引用
如果表达式向decltype返回一个引用类型，意味着表达式的结果对象能作为一条赋值语句的左值：
int i=42,*p=&i,&r=i;
decltype(r+0) b;//加法的结果是int,b是一个未初始化的int
//decltype(*p) c;//错误，解引用指针的类型是引用，而非该指针指向的对象的类型，c类型为int&,必须初始化

decltype的结果类型与表达式形式密切相关。
变量名加一对括号，得到的类型与不加括号时会有不同
变量是可以作为赋值语句左值的特殊表达式
//decltype((i)) d;//错误：d是int&,必须初始化
decltype(i) e;//e是未初始化的int


2.6 自定义数据结构
数据结构就是把一组相关的数据元素组织起来然后使用它们的策略和方法。

2.6.1 定义 SalesData类型
struct SalesData{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
1.类体内部定义名字必须唯一，可以喝类外部定义的名字重复。
2.类体结束的花括号后必须写一个分号，因为类体后面可以紧跟变量名以表示对该类型对象的定义。
struct SalesData{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
} accum,trans,*salesptr;
等价于
struct SalesData{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
SalesData accum,trans,*salesptr;

类数据成员（data menber）
可以为数据成员提供一个类内初始值（in-class initializer）
创建对象时，类内初始值将用于初始化数据成员，没有初始值的成员将被默认初始化
类内初始值可以放在花括号里，或等号右边，不能用圆括号
使用圆括号会被认为是声明函数
struct SalesData{
    std::string bookNo{};
    unsigned units_sold{0};
    double revenue{0.0;}
};
2.6.2 使用SalesData类
//example-2.6.2-.cpp
#include <iostream>
struct SalesData
{
    std::string bookNo{};
    unsigned units_sold{0};
    double revenue{0.0};
};
int main()
{
    SalesData data1, data2;
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
/*
021-52335-222 5 30
021-52335-222 6 29
021-52335-222 11 324 29.4545
 */


2.6.3 编写自己的头文件
类可以定义在函数体外部
也可以在函数体内定义类，但不推荐
确保各个文件总类的定义一致，类通常被定义在头文件中

头文件通常包含哪些只能被定义一次的实体
头文件也经常用到其他头文件的功能

预处理器：确保头文件多次包含仍能安全工作的常用技术是预处理器（perprocessor）
预处理器是编译之前执行的一段程序
#include 是一项预处理功能

另一种预处理功能：头文件保护符（header guard）
#define 指令把一个名字设定为预处理变量
#ifdef 变量已定义时为真
#ifndef 变量未定义时为真
#endif 一旦检查结果为真，则执行后续操作直到#endif指令为止

#ifndef SALESITEM_H  //SALESITEM_H变量未定义，为真执行后续代码
#define SALESITEM_H  //SALESITEM_H变量已定义，再次包含此文件，不会继续执行后续代码
……
#endif //执行到此结束

预处理变量必须唯一，一般用全大写的头文件名

