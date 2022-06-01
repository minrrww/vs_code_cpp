//第十章泛型算法
/*标准库容器定义的操作集合惊人的小。
标准库并未给每个容器添加大量功能，而是提供一组算法，算法中的大多数都独立鱼任何特定的容器，
这些算法是通用的（generic，或称泛型的）：它们可用与不同类型的容器和不同类型的元素。
标准库并未给每个容器都定义成员函数实现某些操作，而是定义了一组泛型算法（generic algorithm）：
成为算法，它们实现了一些经典算法的公共接口。*/

//11.概述
/*大多数算法定义在头文件algorithm中。标准库头文件还在头文件numeric中定义了一组数值泛型算法。
算法并不直接操作容器，而是遍历两个迭代器指定的一个元素范围。
find操作的是迭代器，可以用同样的find函数在任何容器汇总查找值。
find(begin,end,val)，find返回一个等于val值的元素的迭代器，否则返回end。
由于find操作的是迭代器，因此我们可以用同样的find函数在任何容器中查找值。
find也可用内置数组上的迭代器查找值。
还可以在序列的子范围中查找，只需将指向子范围首元素和尾元素之后位置的迭代器（指针）传递给find。
1.算法如何工作
find的工作是在一个未排序的元素序列中查找一个特定元素。概念上，find应执行如下步骤：
（1）访问序列中的首元素；
（2）比较此元素与我们要查找的值；
（3）如果此元素与我们要查找的值匹配，find返回标识此元素的值；
（4）否则，find前进到下一个元素，重复执行步骤2和3；
（5）如果达到序列尾，find应停止；
（6）如果find达到序列末尾，它应该返回一个指出元素未找到的值。
     此值和步骤3返回的值必须具有相容的类型。
这些步骤都不依赖于容器所保存的元素类型。
只要有一个迭代器可以用来访问元素，find就完全不依赖与容器类型。
甚至无须理会保存元素的是不是容器。
2.迭代器令算法不依赖与容器，……
3.……，但算法依赖于元素类型的操作
大多数算法都使用了一个或多个元素类型上的操作。

关键概念：算法永远不会执行容器的操作
算法永远不会改变底层容器的大小。
算法可能改变容器中保存的元素的值，也可能在容器内移动元素，但永远不会直接添加或删除元素。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
void fun_1()
{
    vector<int> vec = {1, 3, 4, 9, 13, 42, 45, 49, 23, 33, 39};
    int val = 42; //我们将查找的值
    //如果在vec中找到想要的元素，则返回结果指向它，否则返回结果为vec.cend()
    auto result = find(vec.cbegin(), vec.cend(), val);
    //报告结果
    cout << "The value " << val
         << (result == vec.cend() ? " is not present" : " is present") << endl;
}
void fun_2()
{
    list<string> lst{"a value", " ", "hello", "world"};
    string val = "a value"; //我们要查找的值
    //此调用在list中查找string元素
    auto result = find(lst.cbegin(), lst.cend(), val);
}
void fun_3()
{
    int ia[] = {27, 210, 12, 47, 109, 83};
    int val = 83;
    int *result = find(begin(ia), end(ia), val);
    //在从ia[1]开始，直至（但不包含）ia[4]的范围内查找元素
    result = find(ia + 1, ia + 4, val);
}
int main()
{
    fun_1();
    fun_2();
    fun_3();
    return 0;
}
