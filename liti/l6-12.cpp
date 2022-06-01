#include <iostream>
using namespace std;
class Point //类的定义
{
public:                                         //外部接口
    Point(int x = 0, int y = 0) : x(x), y(y) {} //构造函数
    int getX() const { return this->x; }        //返回x
    int getY() const { return y; }              //返回y
private:                                        //私有数据成员
    int x, y;
};
int getX()
{
    int x = 9;
    return x;
}
int main() //主函数S
{

    Point a(3, 5);                                //定义并初始化对象a
    Point *p1 = &a;                               //定于对象指针，用a的地址将其初始化
    int (Point::*funcPtr)() const = &Point::getX; //定义函数指针并初始化
    cout << (a.*funcPtr)() << endl;                //利用对象名和函数指针访问对象成员
    cout << (p1->*funcPtr)() << endl;             //利用对象指针和函数指针访问对象成员
    cout << p1->getX() << endl;                   //利用指针访问对象成员
    cout << a.getY() << endl;                     //利用对象名访问对象成员
    return 0;
}
/*
3
3
3
5
*/
