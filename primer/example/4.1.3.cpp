#include <iostream>
#include <vector>
using namespace std;
class peaple
{
private:
public:
    void print()
    {
        cout << "print()" << endl;
    }
};
int get_value()
{
    int val;
    cin >> val;
    return val;
}
int main()
{
    int i = 0;
    cout << i << " " << ++i << endl; //先执行i还是先执行++i未定义，有的编译器会出错
    int j = 1024;
    int k = -j; //k是-1024
    bool b = true;
    bool b2 = -b; //b2是1
    cout << k << " " << b2 << endl;
    vector<string> str = {"Hello",
                          ",",
                          "My",
                          "name",
                          "is",
                          "Hanmeimei.",
                          "",
                          "Are",
                          "you?"};
    //s是对常量的引用；元素既没有被拷贝也不会改变
    for (const auto &s : str) //对于str的每一个元素
    {
        cout << s; //输出当前元素
        //遇到空字符或者以句号结束的字符串进行换行
        if (s.empty() || s[s.size() - 1] == '.')
            cout << endl;
        else
            cout << " "; //否则用空字符隔开
    }
    cout << endl;

    //int k = 0;
    //k = {3.14};//错误：窄化转换
    vector<int> vi;                      //初始值为空
    vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //vi含有10个元素，值0-9

    int ival, jval;
    ival = jval = 0; //正确都被赋值为0
    //复制运算满足右结合律，把0赋值给jval，然后其运算结果赋值给ival
    int *pval; //pval是int *类型
    //ival = pval = 0; //错误，pval无法转换成int类型
    string s1, s2;
    s1 = s2 = "OK"; //字符串字面值转换成string对象
    peaple *p = 0;
    p->print();

    int g = get_value(); //得到第一个值
    while (g != 42)
    {
        //其他处理
        cout << g << endl;
        g = get_value(); //得到其他值
    }

    int h;
    //更好的写法：条件部分表达得更加清晰
    while ((h = get_value()) != 42)
    { //其他处理……
        cout << h << endl;
    }
    return 0;
}
