#include <iostream>
using namespace std;

class Point //类的定义
{
private:
    int x, y;//私有数据成员
public://外部接口
    Point();
    Point(int x, int y);
    ~Point();
    void move(int newX, int newY);
    int getX() const { return x; }
    int getY() const { return y; }
    static void showCount();//静态函数成员
};
Point::Point(){//构造函数实现
    x = y = 0;
    cout << "Default Constructor called." << endl;
}
Point::Point(int x,int y):x(x),y(y){//构造函数重载实现
    cout << "Constructor called." << endl;
}
Point::~Point(){//析构函数实现
    cout << "Destructor called." << endl;
}
void Point::move(int newX,int newY){//成员函数实现
    cout << "Moving the point to(" << newX << "," << newY
         << ")" << endl;
    x = newX;
    y = newY;
}

int main()
{
    cout << "Entering main..." << endl;
    Point a[2];//定义一个Point类数组，包括两个数组元素
    for (int i = 0; i < 2; i++)
        a[i].move(i + 10, i + 20);
    cout << "Exiting main..." << endl;
    return 0;
}
/*输出
Entering main...
Default Constructor called.
Default Constructor called.
Moving the point to(10,20)
Moving the point to(11,21)
Exiting main...
Destructor called.
Destructor called.
*/
