//7.1 定义抽象数据类型
//7.1.1 设计SalesData类
/*成员函数（member function）
SalesData的接口：
一个isbn成员函数，用于返回对象的ISBN编号
一个combine成员函数，用于将一个SalesData对象加到另一个对象上
一个名为add的函数，执行两个SalesData对象的加法
一个read函数，将数据从istream读入到SalesData对象中
一个print函数，将SalesData对象的值输出到ostream
1.使用上面的接口
代码实现讲解略*/
//7.1.2.定义改进的SalesData类
/*成员函数必须声明在类内部，它的定义既可以在类的内部也可以在内的外部。
作为接口的非成员函数，它们定义和声明都在类的外部。
定义在类内部的成员函数是隐式的inline函数
1.引入this
return bookNo;//等同于return this->bookNo;
2.引入const成员函数
this的类型是指向类类型非常量版本的常量指针（this指针本身不能改变）。
SalesData类中，this的类型是SalesData *const，是一个顶层const。
不能把this绑定到常量对象上，即：
不能用一个常量对象调用普通的成员函数。
所以把this定义为指向常量的指针，具有一定的灵活性。
this是隐式形参，所以成员函数形参列表后面的const，用来修饰this指向的对象
这样的const的成员函数被称为常量成员函数(const member function)。
常量对象，以及常量对象的引用指针都只能调用常量成员函数。
3.类作用域和成员函数
编译器分两步处理类：先编译数据成员的声明，然后才轮到成员函数。
因此，成员函数可以随意使用类中的其他成员。
4.在类的外部定义成员函数
类外部定义成员函数，必须与声明匹配。
类外部定义常量成员函数，必须在形参列表后加const。
类外部定义成员函数名字必须包含它所属的类名：
double SalesData::avgPrice() const
使用作用域运算符
5.定义一个返回this对象的函数
函数combine的设计初衷类似于复合赋值运算符+=，
调用该函数的对象代表的是赋值运算符左侧的运算对象，
右侧运算对象则通过显式的实参被传入函数。
该函数值得注意的是它的返回语句，+=后this所指对象值改变，返回类型是引用*/
//7.1.3定义类相关的非成员函数
/*定义一些辅助函数，操作上属于类的接口，实际上不属于类本身。
如果函数在概念上属于类但不定义在类中，它一般与类声明在同一头文件中。
如果非成员函数是类接口的组成部分，则这些函数的声明应该与类在同一个头文件中。
1.定义read和print函数
read和print分别接受一个各自IO类型的引用作为其参数，
IO类不能被拷贝的类型，只能通过引用来传递它们。
读取和写入的操作都会改变流的内容，两个函数接受的都是普通引用，而非队常量的引用。
print函数不负责换行，执行输出的任务的函数应该尽量减少对格式的控制，
这样可以确保由用户代码来决定是否换行。
2.定义add函数
利用combine成员函数*/
//7.1.4 构造函数
/*每个类都分别定义了它的对象被初始化的方式，
类通过一个或几个特殊的成员函数控制其对象的初始化过程，
这些函数叫做构造函数（constructor）。
构造函数的任务是初始化对象的数据成员，只要类的对象被创建，就会执行构造函数。
构造函数与类名相同，没有返回类型，有参数列表（可能为空的）和函数体（可能为空的）。
可以包括多个构造函数，类似重载函数。
不同构造函数之间必须在参数数量或参数类型上有所区别。
构造函数不能被声明称const的。
创建const对象时，直到构造函数完成初始化，对象才能真正取得其常量属性。
构造函数在const对象的构造过程中可以向其写值。
1.合成的默认构造函数
通过默认构造函数（default constructor）来控制默认初始化过程。
默认构造函数无任何实参。
如果没有显示定义构造函数，那么编译器会隐式定义默认构造函数。
又被称为合成的默认构造函数（synthesized default constructor）。
用如下规则来初始化类的数据成员：
如果存在类内的初始值，用它来初始化成员。
否则，默认初始化该成员。
2.某些类不能依赖于合成的默认构造函数
普通类，必须定义它自己的默认构造函数，原因有三：
一是编译器只有在发现类不包括任何构造函数的情况下才会生产默认构造函数。
一旦定义了一些其他构造函数，除非再定义一个默认构造函数，否则无默认构造函数。
如果一个类在某种情况下需要控制对象初始化，那么该类可能在所用情况下都需要控制。
二是合成的默认构造函数可能执行错误的操作。
定义的块中的内置类型或复合类型的对象被默认初始化，它们的值将是未定义的。
如果类包含有内置类型或者复核类型的成员，
则只有当这些成员全都被赋予了类内的初始值时，
这个类才适合于使用合成的默认构造函数。
三是编译器有时不能为某些类合成默认的构造函数。
类中包含其他类类型的成员且这个成员的类型没有默认构造函数。
3.定义SalesData的构造函数
如果需要默认的行为，可以通过在参数列表后面写上=default来要求编译器生产构造函数。
可以和声明出现在内部，也可以和定义出现在外部。在不外部，默认情况下不是inline的。
默认构造函数是否有效，需要内置类型或复合类型的数据成员有初始值。
4.构造函数初始值列表
冒号后，花括号前的部分称为构造函数初始值类别（constructor initialize list）。
负责为新创建的对象的一个或几个数据成员赋初值。
构造函数初始值时成员名字的一个列表，每个名字后面紧跟括号括起来的
（或者在花括号内的）成员初始值。不同成员的初始化通过逗号分隔开来。
某个数据成员被构造函数初始值列表忽略时，将隐式初始化。
通常情况下，构造函数使用类内初始值不失为一种好的选择。
5.在类的外部定义构造函数
以istream为参数的构造函数，调用read函数以给数据成员赋以初值。
构造函数没有返回类型，所以从指定的函数名字开始。
构造函数没有构造函数初始值列表，执行了构造函数体，所以对象成员仍然能被初始化。
read函数第二个参数是一个SalesData对象的引用，
*this将this对象作为实参传递给read函数。*/
//7.1.5 拷贝、赋值和析构
/*类还需要控制拷贝、赋值和销毁对象时发生的行为。
拷贝行为，在初始化变量，以值的方式传递或返回一个对象发生。
使用赋值运算符会发生赋值行为。
当对象不再存在时执行销毁操作。
如果我们不主动定义这些操作，编译器将替我们合成它们。
1.某些类不能依赖于合成的版本
当类需要分配类对象之外的资源时，合成的版本常常失效。
很多需要动态内存的类能使用vector对象或者string对象管理必要的存储空间。
使用vector或者string的类能避免分配和释放内存带来的复杂性。*/

#include <iostream>
using namespace std;
struct SalesData
{
    //新增的构造函数
    //该构造函数不接受任何实参，它是一个默认构造函数。
    SalesData() = default;
    SalesData(const string &s) : bookNo(s) {}
    SalesData(const string &s, unsigned n, double p) : bookNo(s), unitsSold(n), revenue(p * n) {}
    SalesData(istream &);
    //新成员：关于SalesData对象的操作
    string isbn() const { return bookNo; } //定义内部函数时隐式的inline函数
    SalesData &combine(const SalesData &); //相同ISBN编号书籍自加
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
