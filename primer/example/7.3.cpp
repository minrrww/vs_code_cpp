//7.3 类的其他特性
/*类的特性包括：类型成员、类的成员的类内初始值、可变数据成员、
内=内联成员函数、从成员函数返回*this、
关于如何定义并使用类类型及友元类的更多知识。*/
//7.3.1 类成员再探
/*1.定义一个类型成员
Screen表示显示器中的一个窗口。
每个Screen包含一个用于保存Screen内容的string成员和三个string::size_type
类型成员，它们分别表示光标的位置以及屏幕的高和宽。
类还可以定义某种类型在类中的别名。
typedef可以等价地使用类型别名。
定义类型的成员必须先定义后使用。类型成员通常出现在类开始的地方。
2.Screen类的成员函数
3.令成员作为内联函数
可以在类内部显式地声明成员函数，也能在类外部用inline关键字修饰函数的定义。
同时用inline 关键字也合法，但没必要
内联成员函数也应该与相应的类定义在同一头文件中。
4.重载成员函数
5.可变数据成员mutable data member
可变数据成员永远不会是const，即使它是const对象的成员
const对象只能调用const成员函数，可以修改可变数据成员的值。
6.类数据成员的初始值
定义一个窗口管理类并用它表示显示器上的一组Screen。
类内初始化必须使用=的初始化形式，或者花括号括起来的直接初始化形式
*/
//7.3.2 返回*this 的成员函数
/*返回类型为引用类型，则返回的函数值是返回对象的引用
如果返回类型为普通类型，则返回的函数值是返回对象的拷贝，不能改变返回对象的值。
1.从const成员函数返回*this
一个const成员函数如果以引用得形式返回*this,那么返回类型将是常量引用？
//Screen &display(const Screen *const this){return *this;} //对this功能的说明
screen &display()const{return *this}//c++中可用的等价语句
引用不是对象，它没有常量，返回类型将是绑定到常量的引用。故
const Screen &display()const{return *this};
//因为返回类型只有是绑定到常量的引用才能返回常量的引用

display()函数是打印Screen的内容，不改变Screen的内容，所以定义为const成员函数
但是将display()嵌入到一组动作中：
Screen myScreen;myScreen.display(cout).set('#');
则myScreen是普通对象，可以调用常成员函数display(cout)：指向常量的指针指向了变量
display(cout)不能调用普通成员函数set('#')：指向变量的指针指向类常量（错误）
2.基于const的重载
加一个函数void do_display(ostream &os)const{os<<contents;}
实现成员函数调用成员函数，成员函数调用常成员函数。
重载的函数：
Screen &display(ostream &os){do_display(os);return *this;}
*/
//7.3.3 类类型
/*每个类定义了唯一的类型
两个成员完全一样的类，也是两个不同的类型。
可以把类名作为类型的名字使用，从而直接指向类类型
也可以把类名跟在关键字class或struct后面：
SalesData item1;//默认初始化SalesData类型的对象
class SalesData item1;//等价的声明
1.类的声明
类的声明和定义可以分开
class Screen;//声明类，而不定义类
这种声明称作向前声明（forward declaration）
声明之后，定义之前是一个不完全类型（incomplete type）
不完整类型可以定义指向这种类型的指针或引用，
也可以声明以不完整类型作为参数或者返回类型的函数。
类必须先被定义，然后才能用引用或者指针访问其成员。
例外情况：直到类被定义之后数据才能被声明成这种类型。
类的成员类型不能是该类自己。
然而一个类的名字出现后，就认为它声明过了，允许包含指向它自身类型的引用或指针
*/
//7.3.4 友元再探
/*类可以把普通的非成员函数定义成友元；
还可以把其他的类定义成友元，
也可以把其他类的成员函数定义成友元。
友元函数能定义在类的内部，是隐式内联的。
1.类之间的友元关系
如果一个类指定了友元类，
则友元类的成员函数可以访问此类包括非公有成员在内的所有成员。
2.令成员函数作为友元
必须满足声明和定义的彼此依赖关系。
首先定义Window_mgr类，声明clear函数，不定义。
在clear使用之前必须先声明Screen.
定义Screen，包括对于clear的友元声明
定义clear,此时才可以使用Screen的成员。
3.函数重载和友元
重载函数的名字相同，但它们是不同的函数。
如果一个类想把一组重载函数声明成它的友元，需对这组函数中的每一个分别声明。
4.友元声明和作用域
类和非成员函数的声明不是必须在他们的友元声明之前。
当名字第一次出现在友元声明中，该名字在当前作用域中可见。
友元不一定真的声明在当前作用域中。
在类的内部定义该函数，也必须在类的外部提供相应的声明使得函数可见。*/

#include <iostream>
#include <vector>
using namespace std;

class Screen
{
    //友元类通常定义在类开始的地方
    //Window_mgr的成员可以访问Screen类的私有部分
    friend class Window_mgr;
    //Window_mgr::clear必须在Screen类之前被声明
    //friend void Window_mgr::clear(ScreenIndex);
    //friend const vector<Screen> Window_mgr::display(ostream &) const;
    //friend vector<Screen> Window_mgr::display(ostream &);

public:
    //使用类型别名等价地声明一个类型名字
    //using pos = string::size_type;
    typedef string::size_type pos; //定义类型的成员必须先定义后使用。

    //成员函数
    Screen() = default; //因为Screen有另一个构造函数，所以本函数是必须的。
    //cursor被其类内初始值初始化为0。
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; } //读取光标处的字符，隐式内联
    inline char get(pos ht, pos wd) const;        //显式内联
    Screen &move(pos r, pos c);

    //常量成员函数调用可变数据成员，可以改变常量对象的可变数据成员的值
    void some_member() const;

    //设置光标所在位置的字符或其他任一给定位置的字符：
    Screen &set(char);
    Screen &set(pos, pos, char);

    //根据对象是否是const重载display函数
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    //可变数据成员（mutable data member）
    mutable size_t access_ctr;

    //该函数负责显示Screen的内容
    void do_display(ostream &os) const { os << contents; }
};
//成员函数实现
//普通成员函数实现
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; //计算行的位置
    cursor = row + c;    //在行内将光标移动到指定的列
    return *this;        //以左值的形式返回对象
}
//const成员函数实现，重载get(pos r,pos c)const函数
char Screen::get(pos r, pos c) const //在类的内部声明称inline
{
    pos row = r * width;      //计算行的位置
    return contents[row + c]; //返回给定列的字符
}
//常量数据成员调用可变数据成员并改变其值
void Screen::some_member() const
{
    ++access_ctr; //保存一个计数值，用于记录成员函数被调用的次数
}
//实现set函数成员
inline Screen &Screen::set(char c)
{
    contents[cursor] = c; //设置当前光标所在位置的新值
    return *this;         //将this对象作为左值返回
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; //设置给定位置的新值
    return *this;                   //将this对象作为左值返回
}
//窗口管理类
class Window_mgr
{
public:
    //窗口中每个屏幕的编号
    using ScreenIndex = vector<Screen>::size_type;
    //按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);
    //友元的成员函数直接访问类的私有成员函数
    const vector<Screen> &display(ostream &os) const
    {
        for (auto i = screens.begin(); i != screens.end(); ++i)
            (*i).do_display(os);
        os << endl;
        return screens;
    }
    vector<Screen> &display(ostream &os)
    {
        for (auto i = screens.begin(); i != screens.end(); ++i)
            (*i).do_display(os);
        os << endl;
        return screens;
    }

private:
    //这个Window_mgr追踪的Screen
    //默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
    vector<Screen> screens{Screen(5, 8, 'm')};
};
void Window_mgr::clear(ScreenIndex i)
{
    //s是一个Screen的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    //将那个选定的Screen重置为空白
    s.contents = string(s.height * s.width, '*');
}
int main()
{
    Screen myscreen;
    char ch = myscreen.get(); //根据参数个数，调用Screen::get()
    ch = myscreen.get(0, 0);  //调用Screen::get(pos,pos)
    //把光标移动到一个指定的位置，然后设置改位置的字符值
    myscreen.move(4, 0).set('#');

    Screen myScreen(5, 3, '*');
    const Screen blank(5, 3, '$');
    myScreen.set('#').display(cout); //调用非常量版本
    cout << endl;
    blank.display(cout); //调用常量版本
    cout << endl;

    Window_mgr w = Window_mgr();
    w.display(cout).push_back(Screen(3, 6, 'u'));
    w.clear(1);
    w.display(cout);

    return 0;
}
