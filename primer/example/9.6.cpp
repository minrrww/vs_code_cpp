//9.6 容器适配器
/*标准库定义了三个顺序容器适配器：stack、queue和priority_queue。
适配器（adaptor）是标准库中的一个通用概念。容器、迭代器和函数都有适配器。
本质上，一个适配器是一种机制，能使某种事物的行为看起来像另外一种事物一样。
一个容器适配器接受一种已有的容器类型，使其行为看起来像一种不同的类型。
stack适配器接受一个顺序容器，除array或forward_list外。操作起来像stack一样。
表9.17：所有容器适配器都支持的操作和类型
size_type          一种类型，足以保存当前类型的最大对象的大小
value_type         元素类型
container_type     实现适配器的底层容器类型
A a;               创建一个名为a的空适配器
A a(c);            创建一个名为a的适配器，带有容器c的一个拷贝
关系运算符         每个适配器都支持所有关系运算符：==、!=、<、<=、>和>=
这些运算符返回底层容器的比较结果
a.empty()          若a包含任何元素，返回false，否则返回true
a.size()           返回a中的元素数目
swap(a,b)          交换a和b的内容，a和b必须有相同类型，包括底层容器类型也必须相同
a.swap(b)
1.定义一个适配器
每个适配器都定义两个构造函数：默认构造函数创建一个空对象，
接受一个容器的构造函数拷贝该容器来初始化适配器。
stack和queue是基于deque实现的，
priority_queue是在vector之上实现的。

对于有一个给定的适配器，可以使用那些容器是有限制的。
所有容器都要求容器具有添加和删除元素的能力，适配器不能构造在array之上。
所有容器都要求容器具有添加、删除以及访问尾元素的能力，forward_list不能构造适配器。
stack只要求push_back、pop_back和back操作，可以使用vector、list、deque
queue要求back、push_back、front和push_front，可以构造于list或deque之上，不能基于vector构造。
priority_queue除了front、push_back和pop_back操作之外还要求随机访问能力，
可以构造于vector或deque之上，不能基于list构造。

2.栈适配器
stack类型定义在stack头文件中

表9.18：表9.17未列出的栈操作
栈默认基于deque实现，也可以在list或vector之上实现。
s.pop()          删除栈顶元素，但不返回该元素
s.push(item)     创建一个新元素压入栈顶，改元素通过拷贝或移动item而来，
s.emplace(args)  或者由args构造
s.top()          返回栈顶元素，但不将元素弹出栈。

每个适配器都基于底层容器类型的操作定义了自己的特殊操作。
我们只可以使用适配器操作，不能使用底层容器类型的操作。

3.队列适配器
表9.18：表9.17未列出的queue和priority_queue操作
queue默认基于deque实现，priority_queue默认基于vector实现。
queue也可以基于list或vector实现，priority_queue也可以用deque实现。
q.pop()          返回queue的首元素或priority_queue的最高优先级的元素，但不删除元素。
q.front()        返回首元素，但不删除此元素
q.back()         返回尾元素，但不删除此元素，只适用于queue
q.top()          返回最高优先级元素，但不删除该元素
q.push(item)     在queue末尾或priority_queue中恰当的位置创建一个新元素，其值为item，
q.emplace(args)  或者由args构造

标准库queue使用一种先进先出（first-in,first-out,FIFO)的存储和访问策略。
priority_queue允许为队列中的元素建立优先级。
标准库在元素类型上使用<运算符号来确定相对优先级。*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
using namespace std;
int main()
{
    //1.定义一个适配器
    deque<int> di = {1, 2, 3};
    stack<int> stk(di); //从deq拷贝元素到stk
    //在vector上实现的空栈
    stack<string, vector<string>> str_stk;
    //str_stk2在vector上实现，初始化时保存svec的拷贝
    vector<string> swec;
    stack<string, vector<string>> str_stk2(swec);
    //2.栈适配器
    stack<char> intStack; //空栈
    //填满栈
    for (size_t ix = 97; ix != 123; ++ix)
        intStack.push(ix);    //intStack保存0到9十个数
    while (!intStack.empty()) //intStack中有值就继续循环
    {
        auto value = intStack.top();
        cout << value << endl;
        //使用栈顶值的代码
        intStack.pop(); //弹出栈顶元素，继续循环
    }
    //3.队列适配器
    queue<int, list<int>> intq;
    return 0;
}
