#include <iostream>
#include <cmath>
using namespace std;
class Point //Point类定义
{
public: //外部接口
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() { return x; }
    int getY() { return y; }
    friend float dist(const Point &p1,const Point &p2); //友元函数声明
private:
    int x, y; //私有数据成员
};
float dist(const Point &p1,const Point &p2)//常引用作形参
{                           //友元函数实现
    double x = p1.x - p2.x; //通过对象访问私有数据成员
    double y = p1.y - p2.y;
    return static_cast<float>(sqrt(x * x + y * y));
}
int main() //主函数
{
    const Point myp1(1, 3), myp2(3, 9); //定义Point类的对象
    cout << "The distance is:";
    cout << dist(myp1, myp2) << endl; //计算两点之间的距离
    return 0;
}
/*输出
The distance is:6.32456
*/
