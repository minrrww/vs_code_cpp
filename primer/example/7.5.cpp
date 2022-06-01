//7.5 构造函数再探
//7.5.1 构造函数初始值列表
/*定义变量时，立即初始化，或先定义再赋值。
如果诶呦在构造函数的初始值列表中显式地初始化成员，
则该成员将在构造函数体之前执行默认初始化。
SalesData::SalesData(const string &s,unsigned cnt,double price)
{
    bookNo=s;
    untsSold=cnt;
    revenue=cnt*price;
}
和构造函数列表显式初始化的区别
1.构造函数的初始化有时必不可少
如果成员是const或者引用得话，必须初始化。
如果成员属于某种类类型且该类没有定义默认构造函数时，
也必须将这个成员初始化。
引用得初始化必须引用已声明或的变量或对象。
养成构造函数初始值的习惯。
2.成员初始化的顺序
构造函数初始值列表只说明用于初始化成员的值，不限定初始化的执行顺序。
初始化顺序与类定义的出现顺序一致。
令构造函数的初始值顺序与成员声明的顺序一致。
尽量避免使用某些成员初始化其他成员。
构造函数的参数作为成员的初始值，尽量避免使用同一对象的其他成员。
3.默认实参和构造函数
如果一个构造函数，为所有参数都提供了默认实参，
则它实际上也定义类默认构造函数。
*/
//7.5.2 委托构造函数
/*我们可以定义所谓的委托构造函数（delegating constructor）。
一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程。*/
//7.5.3 默认构造函数的作用
/*默认初始化在以下情况下发生：
块作用域内不使用任何初始值定义一个非静态变量或者数组时。
一个类本身含有类类型的成员且使用合成的默认构造函数时。
当类类型的成员没有在构造函数初始值列表中显式地初始化。
初始化在以下情况下发生：
在数组初始化的过程中如果我们提供的初始值数量少于数组的大小时。
不使用初始值定义一个局部静态变量时。
书写形如T()的表达式显式地请求初始化时。
类必须包含一个默认构造函数以便在上述情况下使用。
1.使用默认构造函数
默认初始化不加圆括号，函数加圆括号。*/
//7.5.4 隐式的类类型转换
/*转换构造函数（converting constructor）
能通过一个实参调用的构造函数定义类一条丛构造函数的参数类型向类类型隐式转换的规则。
1.只允许一步类类型转换
2.类类型转换不是总有效
3.抑制构造函数定义的隐式转换
通过声明为explicit加以阻止
explicit只对一个实参的构造函数生效。
需要多个实参的构造函数不能用于执行隐式转换。
explicit只能出现在构造函数声明时
explicit只能用于直接初始化，不能用于拷贝初始化。
4.为转换显式地使用构造函数
item.combine(SalesData(null_book));
5.标准库中含有显式构造函数的类：
接受一个单参数的const char*的string构造函数不是explicit的
接受一个容量参数的vector构造函数是explicit的。*/
//7.5.5 聚合类
/*当一个类满足如下条件时，我们说它是聚合的：
所有成员都是public的。
没有定义任何构造函数。
没有类内初始值。
没有基类，也没有virtual函数
struct data{
    int ival;
    string s;};
可以提供一个花括号括起来的成员初始值列表，并用它初始化聚合类的数据成员。
//vall.ival=0;vall.s=string("Anna")
Data vall={0,"Anna"};
初始值的顺序必须与声明一致。
与初始化数组元素的规则一样，
如果初始值列表中的元素个数少于类的成员数量，则靠后的成员被默认初始化。
初始值列表的元素个数决不能超过类的成员数量。
显式地初始化类的对象的成员存在三个明显的缺点：
类的所有成员都是public，
将正确初始化每个对象的每个成员的重任交给了类的用户。容易出错。
添加或删除一个成员后，所有的初始化语句都需要更新。*/
//7.5.6 字面值常量类
/*constexpr函数的参数和返回值必须是字面值类型。
除了算术类型、引用和指针外，某些类也是字面值类型。
字面值类型的类可能含有constexpr函数成员。
constexpr函数成员必须符合constexpr函数的所有要求，是隐式const的。
数据成员都是字面值类型的聚合类是字面值常量类。
如果一个类不是聚合类，但它符合下述要求，则它也是一个字面值常量类：
数据成员都必须是字面值类型。
类必须至少含有一个constexpr构造函数。
如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；
或者如果成员属于某种类类型，则初始值必须使用成员自己的constexpr构造函数。
类必须使用析构函数的默认定义，该成员负责销毁类的对象。

1.constexpr构造函数
尽管构造函数不能是const的，但是字面值常量类的构造函数可以是constexpr函数。
一个字面值常量类必须至少提供一个constexpr构造函数。
constexpr构造函数可以声明成=default的形式或者是删除函数的形式。
否则，constexpr构造函数鼻血既符合构造函数的要求，又符合constexpr函数的要求。
constexpr构造函数必须初始化所有数据成员，初始值或者使用constexpr构造函数，
或者是一条常量表达式。
constexpr构造函数用于生成constexpr对象以及constexpr函数的参数或返回类型。
*/

#include <iostream>
using namespace std;
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    //如果构造函数生成对象是constexpr对象，常对象只能调用常成员函数any()const
    constexpr bool any()const { return hw || io || other; }
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
int main()
{
    SalesData total;      //保存当前求和结果的变量
    if (read(cin, total)) //读入第一笔交易
    {
        SalesData trans;         //保存下一条交易数据的变量
        while (read(cin, trans)) //读入剩余的交易
        {
            if (total.isbn() == trans.isbn()) //检查isbn
                total.combine(trans);         //更新变量total当前的值
            else
            {
                print(cout, total) << endl; //输出结果
                total = trans;              //处理下一本书
            }
        }
        print(cout, total) << endl; //输出最后一条交易
    }
    else //没有输入任何信息
    {
        cerr << "No data?!" << endl; //通知用户
    }
    string null_book = "9-999-99999-9";
    SalesData item;
    item.combine(null_book);

    constexpr Debug io_sub(false, true, false); //调试IO
    if (io_sub.any())                           //等价于if(true)
        cerr << "print appropriate error messages" << endl;
    constexpr Debug prod(false); //无调试
    if (prod.any())              //等价于if(false)
        cerr << "print an erro message" << endl;
    return 0;
}
