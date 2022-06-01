//7.4 类的作用域
/*每个类都有自己的作用域。
在类的作用域外，普通的数据和函数成员只能由对象、
引用或者指针使用成员访问运算符来访问。
对于类类型成员则使用作用域运算符访问。
1.作用域和定义在类外部的成员
定义在类外部的成员，处理参数列表前明确我们当前正位于类的作用域中。
函数返回类型出现在函数名前，位于类的作用域外。返回类型必须指明是哪个类的成员。*/
//7.4.1 名字查找与类的作用域
/*目前，名字查找（name lookup）过程比较直接了当：
一、在名字所在地块中寻找其声明语句，只考虑在名字的使用之前出现的声明。
二、如果没找到，继续查找外层作用域。
三、如果最终没有找到匹配的声明，则程序报错。
类的定义分为两步：
首先，编译成员的声明
直到类全部可见后才编译函数体。
1.用于类成员声明的名字查找
声明中使用的名字，包括返回类型或者参数列表中使用的名字，必须在使用前确保可见。
2.类型名要特殊处理
内层作用域可以重新定义外层作用域中的名字，
即使该名字已经在内层作用域中使用过。
在类中，如果成员使用了外层作用域中的某个名字，
而该名字代表一种类型，则类不能在之后重新定义该名字。（该错误编译器不为此负责）
类型名的定义通常出现在类的开始处，
这样能确保所有使用该类型的成员都出现在类名单定义之后。
3.成员定义中的普通块作用域的名字查找
在成员函数内查找该名字->在类内查找->在成员函数定义之前的作用域内查找。
不建议使用其他成员的名字作为某个成员函数的参数。
4.类作用域之后，在外围的作用域中查找
外层的对象被屏蔽，任然可以通过作用域运算符访问。
5.在文件中名字的出现处对其进行解析*/
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
    //向窗口添加一个Screen，返回它的编号
    ScreenIndex addScreen(const Screen &);

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
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}
int main()
{
    Screen::pos ht = 2, wd = 8;
    Screen scr(ht, wd, '#');
    Screen *p = &scr;
    char c = scr.get();
    scr.display(cout);
    c = p->get();
    scr.set(1,7,'@').display(cout);
    Window_mgr w = Window_mgr();
    w.addScreen(scr);
    w.display(cout);

    return 0;
}
