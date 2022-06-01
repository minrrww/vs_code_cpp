//8.2 文件输入输出
/*头文件fstream定义类三个类型类支持文件IO：
fstream    ifstream，wifstream从一个文件读取数据
           ofstream，wofstream向一个给定文件写入数据
           fstream，wfstream读写给定文件

表8.3：fstream特有的操作
fstream fstrm          创建一个未绑定到文件流。
                       fstream是头文件fstream中定义的一个类型
fstream fstrm(s)       创建一个fstream，并打开名为s的文件。
                       s可以是string类型，
                       或者一个指向C风格字符串的指针。
                       这些构造函数都是explicit的。
                       默认的文件模式mode依赖与fstream的类型。
fstream fstrm(s,mode)  与前一个构造函数类似，但按指定mode打开文件
fstrm.open(s)          打开名为s的文件，并将文件与fstrm绑定。
                       s可以是一个string或一个指向C风格字符串的指针。
                       默认的文件mode依赖于fstream的类型。返回void
fstrm.close()          关闭与fstrm绑定到文件。返回void
fstrm.is_open()        返回一个bool值，
                       指出与fstrm关联到文件是否成功打开且尚未关闭*/
//8.2.1 使用文件流对象
/*当我们想要写一个文件时，可以定义一个文件流对象，并将对象与文件关联起来。
每个文件流对象都定义类一个名为open的成员函数，
定位给定的文件，并视情况打开为读或写模式。
创建文件流对象时，可以提供文件名。
如果提供文件名，则open会自动被调用。
文件名可以是string类型的对象，也可以说C风格字符数组。
1.用fstream代替iostream&
替换部分7.5.cpp中的代码，实现文件写入内存，内存输出文件。
2.成员函数open和close
如果定义一个空文件流对象，可以随后调用open来将它与文件关联起来。
对一个已经打开的文件流调用open会失败，并会导致failbit被置位。
为了将文件流关联到另一个文件，必须首先关闭已经关联到文件。
文件关闭成功，我们可以打开新的文件。
如果open成功，则open会设置流的状态，使得good()为true。
3.自动构造和析构
input是while循环的局部变量，每个循环步中都要创建和销毁一次。
当一个fstream对象被销毁时，close会自动被调用。*/

//8.2.2 文件模式
/*每个流都有一个关联到文件模式（file mode），用来指出如何使用文件。
表 8.4：文件模式
in      以读方式打开
out     以写方式打开
app     每次写操作前均定位到文件末尾
ate     打开文件后立即定位到文件末尾
trunc   截断文件
binary  以二进制方式进行IO

无论用哪种方式打开文件，我们都可以指定文件模式。
用open打开文件时可以，用一个文件名初始化流来隐式打开文件时也可以。
指定文件模式有如下限制：
只可以对ofstream或fstream对象设定out模式
只可以对ifstream或fstream对象设定in模式
只有当out也被设定时才可设定trunc模式
只要trunc没被设定，就可以设定app模式。在app模式下，即使没有显式指定out模式，
    文件也总是以输出方式被打开。
默认情况下，即使我们没有指定trunc，以out模式打开的文件也会被截断。
    为类保留out模式打开文件的内容，我们必须同时指定app模式，
    这样只会将数据追加写到文件末尾；或者同时指定in模式，
    即打开文件同时进行读写操作。
ate和binary模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用。

每个文件流类型都定义类一个默认的文件模式，当我们未指定文件模式，就使用默认模式。
ifstream关联到文件默认以in模式打开
ofstream关联到文件默认以out模式打开
fstream关联到文件默认以in和out模式打开
1.以out模式打开文件会丢弃已有数据
阻止一个ofstream清空给定文件内容的方法是同时指定app模式。
ofstream打开的文件中已有数据的唯一方法是显式指定app或in模式
2.每次调用open时都会确定文件模式
可能是显式地设置，也可能是隐式地设置，未指定，就是使用默认值。*/
#include <iostream>
#include <fstream>
using namespace std;
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    //如果构造函数生成对象是constexpr对象，常对象只能调用常成员函数any()const
    constexpr bool any() const { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }

private:
    bool hw;    //硬件错误，而非IO错误
    bool io;    //IO错误
    bool other; //其他错误
};
class SalesData
{
    //为SalesDatal的非成员函数接口所做的友元声明
    friend istream &read(istream &, SalesData &);
    friend ostream &print(ostream &, const SalesData &);
    friend SalesData add(const SalesData &, const SalesData &);

public:
    //非委托构造函数使用对应的实参初始化成员
    SalesData(string s, unsigned cnt, double price) : bookNo(s), unitsSold(cnt), revenue(cnt * price) {}
    //其余构造函数全都委托给另一个构造函数
    SalesData() : SalesData("", 0, 0) {}
    SalesData(string s) : SalesData(s, 0, 0) {}
    SalesData(istream &is) : SalesData() { read(is, *this); }
    //新成员：关于SalesData对象的操作
    string isbn() const
    {
        return bookNo;
    }                                      //定义内部函数时隐式的inline函数
    SalesData &combine(const SalesData &); //相同ISBN编号书籍自加

private: //添加了访问说明符
    //常量成员函数(const member function)
    //const 限定隐式的this指针形参不能改变
    double avgPrice() const; //相同ISBN编号书籍的平均价格

    //数据成员
    string bookNo;          //书籍的ISBN编号
    unsigned unitsSold = 0; //书籍销售数量
    double revenue = 0.0;   //相同ISBN编号书籍的总价
};
double SalesData::avgPrice() const
{
    if (unitsSold)
        return revenue / unitsSold;
    else
        return 0;
}
SalesData &SalesData::combine(const SalesData &rhs)
{
    unitsSold += rhs.unitsSold; //把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this; //返回调用该函数的对象
}
//非类的成员函数的接口
istream &read(istream &, SalesData &);
ostream &print(ostream &, const SalesData &);
SalesData add(const SalesData &, const SalesData &);
//输入的交易信息包括ISBN、售出总数和售出价格
istream &read(istream &is, SalesData &item)
{
    double price = 0;
    is >> item.bookNo >> item.unitsSold >> price;
    item.revenue = price * item.unitsSold;
    return is;
}
ostream &print(ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.unitsSold << " "
       << item.revenue << " " << item.avgPrice();
    return os;
}
SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs; //把lhs的数据成员拷贝给sum
    sum.combine(rhs);    //把rhs的数据成员加到sum当中
    return sum;
}
int main(int argc, char **argv)
{
    string s = "infile";
    ifstream input(s); //打开销售记录文件
    ofstream output;   //打开输出文件
    if (output)
        output.open("outfile", ofstream::app);//隐含为输出模式
    SalesData total;        //保存当前求和结果的变量
    if (read(input, total)) //读入第一笔交易
    {
        SalesData trans;           //保存下一条交易数据的变量
        while (read(input, trans)) //读入剩余的交易
        {
            if (total.isbn() == trans.isbn()) //检查isbn
                total.combine(trans);         //更新变量total当前的值
            else
            {
                print(output, total) << endl; //输出结果
                total = trans;                //处理下一本书
            }
        }
        print(output, total) << endl; //输出最后一条交易
    }
    else //没有输入任何信息
    {
        cerr << "No data?!" << endl; //通知用户
    }
    for (auto p = argv + 1; p != argv + argc; ++p)
    {
        ifstream input(*p);
        if (input)
        {
            ofstream output(*p);
        }
        else
            cerr << "couldn't open: " + string(*p);
    }
    return 0;
}
