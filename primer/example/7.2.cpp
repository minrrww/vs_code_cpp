//7.2 访问控制与封装
/*已经为类定义了接口，但没有任何机制强制用户使用这些接口。
C++中使用访问说明符（access specifiers）加强类的封装性。
public说明符之后的成员在整个程序内可被访问，public成员定义类的接口。
private说明符之后的成员可以被类的成员函数访问，不能使用该类的代码访问，
private部分封装了类的实现细节。
一个类可以包含0个或者多个访问说明符。
每个访问说明符有效范围直到出现下一个访问说明符或者到达类的结尾处为止。
1.使用class或struct关键字
class和struct默认的访问权限不同。class默认是private，struct默认是public。*/
//7.2.1 友元
/*SalesData数据成员是private的，read,print,add函数无法正常编译。
类想把一个函数作为它的友元，增加一条以friend关键字开始的函数声明语句。
友元声明只能出现在类内部，在类内出现的位置不限。
友元不是类的内部成员，不受它所在区域访问控制级别的约束。
一般说来，最好在类定义开始或结束前的位置集中声明友元。
1.友元的声明
友元的声明仅仅指定了访问权限，而非一个通常意义上的函数声明。
在友元声明之外再专门对函数进行一次声明。
通常报友元的函数声明与类本身放置在同一个头文件中（类的外部）。
许多编译器未强制限定友元函数必须在使用之前在类的外部声明。*/
#include <iostream>
using namespace std;
class SalesData
{
    //为SalesDatal的非成员函数接口所做的友元声明
    friend istream &read(istream &, SalesData &);
    friend ostream &print(ostream &, const SalesData &);
    friend SalesData add(const SalesData &, const SalesData &);

public: //添加访问说明符
    //新增的构造函数
    //该构造函数不接受任何实参，它是一个默认构造函数。
    SalesData() = default;
    SalesData(const string &s) : bookNo(s) {}
    SalesData(const string &s, unsigned n, double p) : bookNo(s), unitsSold(n), revenue(p * n) {}
    SalesData(istream &);
    //新成员：关于SalesData对象的操作
    string isbn() const { return bookNo; } //定义内部函数时隐式的inline函数
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
SalesData::SalesData(istream &is)
{
    //read函数的作用是从is中读取一条交易信息然后存入this对象中
    read(is, *this);
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
    return 0;
}
