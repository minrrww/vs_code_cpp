#include <iostream>

using namespace std;
class Point //Point类定义
{
public:                                      //外部接口
    Point(int x = 0, int y = 0) : x(x), y(y) //构造函数
    {
        count++;
    }
    Point(const Point &p) : x(p.x), y(p.y) //复制构造函数
    {
        count++;
    }
    ~Point()
    {
        count--;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    static int count; //静态数据成员，用于记录点的个数
private:              //私有数据成员
    int x, y;
};
int Point::count = 0;
int main()
{
    int *ptr = &Point::count; //定义一个int型指针，指向类的静态成员
    Point a(4, 5);            //定义对象a
    cout << "Point A:" << a.getX() << "," << a.getY();
    cout << " Object count=" << *ptr << endl; //直接通过指针访问静态数据成员
    Point b(a);                               //定义对象b
    cout << "Point B:" << b.getX() << "," << b.getY();
    cout << " Object count=" << *ptr << endl; //直接通过指针访问静态数据成员
    return 0;
}
