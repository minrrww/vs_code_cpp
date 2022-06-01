//7.6 类的静态成员
/*1.声明静态成员
在成员的声明之前加上关键字static使得其与类关联在一起。
类的静态成员存在于任何对象之外，对象中不包括任何与静态数据成员有关的数据。
静态成员函数也不与任何对象绑定在一起，它们不包含this指针。
不能声明成const的（无常静态成员函数）
2.使用类的静态成员
可以用作用域运算符、类的对象、引用或指针来访问静态成员。
成员函数不通过作用域运算符就能直接使用静态成员。
3.定义静态成员
既可以在类的内部也可以在类的外部定义静态成员函数。
当在类的外部定义静态成员时，不能重复static关键字，
该关键字只出现在类内部的声明语句。
静态数据成员不属于类的任何一个对象，不是在创建类的对象时定义的。
不是由类的构造函数初始化的。
不能再类的内部初始化静态成员。必须在类的外部定义和初始化每个静态成员。
类似于全局变量，静态数据成员定义在任何函数之外。
一旦定义，一直存在与程序的整个生命周期中。
定义静态数据成员的方式和在类的外部定义成员函数差不多。
想要确保对象只定义一次，
最好的办法是把静态数据成员的定义与其他非内联函数的定义放在同一文件中。
4.静态成员的类内初始化
通常情况下，类的静态成员不应该在类的内部初始化。
可以为静态成员提供const整数类型的类内初始值，
要求静态成员必须是字面值常量类型的constexpr。
初始值必须是常量表达式，因为这些成员本身就是常量表达式。
如果某个静态成员的应用场景仅限于编译器可以替换它的值的情况，
则一个初始化的const或constexpr static不需要分别定义。
相反，如果我们将它用于值不能替换的场景中，则该成员必须有一条定义语句。
5.静态成员能用于某些场景，而普通成员不能
静态数据成员可以是不完全类型。静态数据成员的类型可以就是它所属的类类型。
而非静态数据成员则受到限制，只能声明成它所属类的指针或引用：
class Bar{
    public://...
    private:
    static Bar mem1;//正确：静态成员可以是不完全类型
    Bar *mem2;//正确：指针成员可以是不完全类型
    Bar mem3;//错误：数据成员必须是完整类型
};
静态成员和普通成员的另外一个区别是我们可以使用静态成员作为默认实参。
非静态数据成员不能作为默认实参，因为它本身属于对象的一部分。
静态数据成员只能由静态函数成员改变值。*/

#include <iostream>

using namespace std;
class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate()
    {
        interestRate = 0;
        return ++interestRate;
    }
    static constexpr int period = 30; //period是常量表达式
    double daily_tbl[period];
};
double Account::interestRate = initRate();
constexpr int Account::period; //初始值在类的定义内提供
void Account::rate(double newRate)
{
    interestRate = newRate;
}
int main()
{
    double r;
    r = Account::rate(); //使用作用域运算符访问静态成员
    cout << r << endl;
    Account ac1, *ac2 = &ac1;
    Account::rate(5.6);
    //调用静态成员函数rate的等价形式
    r = ac1.rate(); //通过Account的对象或引用
    cout << r << endl;
    r = ac2->rate(); //通过指向Account对象的指针
    cout << r << endl;
    return 0;
}
