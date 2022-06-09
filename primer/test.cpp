#include <iostream> //#include 指令:告诉编译器，需使用头文件（header）iostream库
#include <string>
using namespace std;
constexpr int size()
{
    return 2;
}
    int j;
    constexpr int i = 42; // i的类型是整型常量
int main()
{
    const int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = size();
    int m;
    cin >> m;
    const int l = m + 1;
    const int s = size();
    const int *p = nullptr;     //指向常量的指针 底层const
    constexpr int *q = nullptr; //常量指针 顶层const
    int a = 2;
    // i和j必须定义在函数体外（固定地址）
    constexpr const int *p1 = &i; //常量指针p指向整型常量i
    constexpr int *p2 = &j;      // p1是常量指针，指向整数j
    constexpr int &v = j;
    cout << v;
}
