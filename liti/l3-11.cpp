#include <iostream>

using namespace std;
void swap(int &a,int &b)//使用引用传递
//void swap(int a,int b)
{
    int t = a;
    a = b;
    b = t;
}
int main()
{
    int x = 5, y = 10;
    cout << "x=" << x << "    y=" << y << endl;
    swap(x, y);
    cout << "x=" << x << "    y=" << y << endl;
    getchar();
    return 0;
}
