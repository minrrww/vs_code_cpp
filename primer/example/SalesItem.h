//SalesItem.h
#ifndef SALESITEM_H
#define SALESITEM_H
#include <iostream>
#include <string>
using namespace std;
class SalesItem
{
private:                //私有数据成员
    string isbn;        //书的ISBN号
    unsigned unitsSold; //售出数量（本）
    double revenue;     //销售总价
public:                 //外部接口
                        //带默认值的构造函数，相当于4次重载:无参数，1参数，2参数，3参数
    SalesItem(string isbn = "", unsigned unitsSold = 0, double price = 0.0)
        : isbn(isbn), unitsSold(unitsSold)
    {
        revenue = price * unitsSold;
    }
    SalesItem(istream &is) { is >> *this; }                             //重载构造函数，用构造函数读入输入流
    SalesItem &operator+=(const SalesItem &s);                          //重载+=运算符
    friend istream &operator>>(istream &in, SalesItem &s);              //用友元函数重载>>运算符
    friend ostream &operator<<(ostream &is, const SalesItem &s);        //用友元函数重载<<运算符
    friend bool operator==(const SalesItem &lhs, const SalesItem &rhs); //友元函数可以访问私有数据成员
    double avgPrice() const                                             //求平均售价
    {
        if (unitsSold) //如果数量不为0，返回平均值
            return revenue / unitsSold;
        else //如果数量为0,返回0.0
            return 0.0;
    }
    bool sameIsbn(const SalesItem &s) //比较ISBN是否相等
    {
        return isbn == s.isbn;
    }
};
SalesItem operator+(const SalesItem &lhs, const SalesItem &rhs); //声明重载+运算符
istream &operator>>(istream &in, SalesItem &s)                   //实现重载>>运算符，返回左值，返回类型使用引用
{
    double price = 0;                     //定义单价
    in >> s.isbn >> s.unitsSold >> price; //输入流ISBN，数量，单价
    if (in)                               //如果输入流有效，计算总价
        s.revenue = s.unitsSold * price;
    else //否则，将无参数构造函数赋值给s
        s = SalesItem();
    return in; //返回左值
}

ostream &operator<<(ostream &is, const SalesItem &s) //实现重载<<运算符，返回左值，返回类型使用引用
{
    is << s.isbn << "\t" << s.unitsSold << "\t" << s.revenue << "\t" << s.avgPrice(); //输出几个值
    return is;                                                                        //返回左值
}

bool operator==(const SalesItem &lhs, const SalesItem &rhs) //声明并实现重载==运算符
{                                                           //全等为真，否则为假
    return lhs.unitsSold == rhs.unitsSold && lhs.isbn == rhs.isbn && lhs.revenue == rhs.revenue;
}

bool operator!=(const SalesItem &lhs, const SalesItem &rhs) //声明并实现重载!=运算符
{
    return !(lhs == rhs); //利用重载的==运算符
}

SalesItem &SalesItem::operator+=(const SalesItem &s) //实现重载+=运算符
{
    unitsSold += s.unitsSold;
    revenue += s.revenue;
    return *this; //返回左值
}

SalesItem operator+(const SalesItem &lhs, const SalesItem &rhs) //实现重载+运算符
{
    SalesItem ret(lhs); //利用构造函数创建对象
    return ret += rhs;  //调用重载的+=运算符
}
#endif
