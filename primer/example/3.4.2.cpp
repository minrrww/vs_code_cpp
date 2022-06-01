//example-3.4.2-.cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> text = {"Hello world", " ", "Some string", "Minrrww", "just for you"};
    //text必须是有序的
    //beg和end表示我们搜索范围
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2; //初始状态下的中间点
    //当还有元素尚未检查并且我们还没找到sought时执行循环
    string sought = "Minrrww";
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)           //我们要找的元素在前半部分吗？
            end = mid;               //如果是，调整搜索范围使得忽略掉后半部分
        else                         //我们要找到元素在后半部分吗？
            beg = mid + 1;           //在mid之后寻找
        mid = beg + (end - beg) / 2; //新的中间点
    }
    cout << *++beg << endl;
    cout << *++mid << endl;
    cout << *++end << endl;
}
/*
Minrrww
Minrrww
Minrrww
*/
