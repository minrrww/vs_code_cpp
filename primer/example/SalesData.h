using namespace std;
struct SalesData
{
    //新成员：关于SalesData对象的操作
    string isbn() const { return bookNo; } //定义内部函数时隐式的inline函数
    SalesData &combine(const SalesData &); //相同ISBN编号书籍自加
    //常量成员函数(const member function)
    //const 限定隐式的this指针形参不能改变
    double avgPrice() const; //相同ISBN编号书籍的平均价格
    //数据成员
    string bookNo;          //书籍的ISBN编号
    unsigned unitsSold = 0; //销售数量
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
    unitsSold += rhs.unitsSold;
    revenue += rhs.revenue;
    return *this;
}
SalesData add(const SalesData &, const SalesData &);
ostream &print(ostream &, const SalesData &);
istream &read(istream &, SalesData &);
SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}
ostream &print(ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.unitsSold << " "
       << item.revenue << " " << item.avgPrice();
    return os;
}
istream &read(istream &is, SalesData &item)
{
    double price = 0;
    is >> item.bookNo >> item.unitsSold >> price;
    item.revenue = price * item.unitsSold;
    return is;
}
