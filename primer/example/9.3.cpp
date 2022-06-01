//9.3 顺序容器操作
/*顺序容器和组织容器的不同之处在于两者组织元素的方式。
这些不同之处直接关系到了元素如何存储、访问、添加以及删除。*/
//9.3.1 向顺序容器添加元素
/*除array外，所有标准容器都提供灵活的内存管理。
在运行时可以动态添加或删除元素来改变容器大小。
表9.5：向顺序容器添加元素的操作
这些操作会改变容器的大小；array不支持这些操作。
forward_list 有自己专有版本的insert和emplace；
forward_list 不支持push_back和emplace_back。
vector和string不支持push_front和emplace_front。
c.push_back(t)       在c的尾部创建一个值为t或由args创建的元素。返回void
c.emplace_back(args)
c.push_front(t)      在c的头部创建一个值为t或由args创建的元素。返回void
c.emplace_front(args)
c.insert(p,t)        在迭代器p指向的元素之前创建一个值为t或由args创建的元素。
c.emplace(p,args)    返回指向新添加的元素的迭代器。
c.insert(p,b,e)      将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前。
                     b和e不能指向c中的元素。返回指向新添加的第一个元素的迭代器；
                     若范围为空，则返回p
c.insert(p,il)       il是一个花括号包围的元素值列表。讲这些给定值插入到迭代器p指向的元素之前。
                     返回指向新添加的第一个元素的迭代器；若范围为空，则返回p
c.insert(p,n,t)      将n个t元素插入到迭代器p指向的元素之前。
向一个vector、string或deque插入元素会使所有指向容器的迭代器、引用和指针失效。
1.使用push_back
array和forward_list 不支持
string vector list deque 支持
2.使用push_front
array vector string 不支持
list forward_list deque 支持
3.在容器中的特定位置添加元素
vector deque list string 支持insert，vector string可以用insert在begin之前插入元素。
array forward_list 不支持insert
insert将元素插入到vector deque string任何位置都是合法的
4.插入范围内元素
5.使用insert的返回值
6.使用emplace操作
emplace_front、emplace和emplace_back对应push_front、insert和push_back
前者传递参数给元素的构造函数，直接创建对象，后者传递元素类型的对象给容器，拷贝到容器中。*/
//9.3.2 访问元素
/*
容器中无元素，访问操作的结果是未定义的。!c.empty()
首元素：*c.begin(),c.front()尾元素：*(--c.end()),c.back()
表9.6：在顺序容器中访问元素的操作
at和下标操作只适合用于string、vector、deque和array。
back不适用于forward_list。
c.back()     返回c中尾元素的引用。若c为空，函数行为未定义。
c.front()    返回c中首元素的引用。若c为空，函数行为未定义。
c[n]         返回c中下标为n的元素的引用。n是一个无符号整数。
             若n>=c.size(),则函数行为未定义。
c.at(n)      返回下标为n的元素的引用。
             如果下标越界，则抛出一out_of_range异常。
1.访问成员函数返回的使引用
2.下标操作和安全的随机访问
下标大于0小于size()
下标运算符不检测下标是否在合法范围*/
//9.3.2 删除元素
/*表9.7：顺序容器的删除操作
这些操作会改变容器的大小，所以不适用于array
forward_list有特殊版本的erase
forward_list不支持pop_back;vector和string不支持pop_front
c.pop_back()       删除c中尾元素。若c为空，则函数行为未定义。函数返回void
c.pop_front()      删除c中首元素。若c为空，则函数行为未定义。函数返回void
c.erase(p)         删除迭代器p所指定的元素，
                   返回一个指向被删除元素之后元素的迭代器，
                   若p指向尾元素，则返回尾后迭代器。
                   若p是尾后迭代器，则函数行为未定义。
c.erase(b,e)       删除迭代器b和e所指范围内的元素。返回一个指向最后一个被删除元素之后元素的迭代器，
                   若e本身就是尾后迭代器，则函数也返回尾后迭代器。
c.clear()          删除c中的所有元素。返回void
删除deque中除收尾位置之外的任何元素都会使所有迭代器、引用和指针失效。
指向vector或string中删除点之后位置的迭代器、引用和指针失效。
删除元素的成员函数并不检查其参数。*/
//9.3.4 特殊的forward_list操作
/*在一个forward_list中添加或删除元素的操作是通过改变给定元素之后的元素来完成的。
insert_after\emplace_after\erase_after
forward_list定义了before-begin,返回一个首前（off-the-beginning）迭代器。
允许在这个迭代器之后添加或删除元素。
表9.8 在forward_list中插入或删除元素的操作
lst.before_begin()       返回指向链表首元素之前不存在的元素的迭代器。
lst.cbefore_begin()      不能接引用。cbefore_begin()返回一个const_iterator
lst.insert_after(p,t)    在迭代器p之后的位置插入元素。
lst.insert_after(p,n,t)  t是一个对象，n是数量，
lst.insert_after(p,b,e)  b和e使表示范围的一对迭代器，
lst.insert_after(p,il)   il是一个花括号列表。
                         返回一个指向最后一个插入元素的迭代器。
                         若干范围为空，则返回p。
                         若p为尾后迭代器，则函数为未定义。
emplace_after(p,args)    使用args在p指定的位置之后创建一个元素。
                         返回一个指向这个新元素的迭代器。若p为尾后迭代器，则函数行为未定义。
lst.erase_after(p)       删除p指向的位置之后的元素，或删除b之后直到e之间的元素。
lst.erase_after(b,e)     返回一个指向被删除元素之后元素的迭代器，若不存在这样的元素，则返回尾后迭代器。
                         如果p指向lst的尾元素或者是一个尾后迭代器，则函数行为未定义。
当在forward_list中添加或删除元素时，我们必须关注两个迭代器：一个指向我们要处理的元素，另一个指向其前驱。
*/
//9.3.5 改变容器大小
/*表9.9：顺序容器大小操作
resize不适用于array
c.resize(n)    调整c的大小为n个元素。若n<c.size()，则多出的元素被丢弃。
               若必须添加新元素，对新元素进行值初始化。
c.resize(n,t)  调整c的大小为n个元素。任何新添加的元素都初始化为值t。

如果resize缩小容器，则指向被删除元素的迭代器、引用和指针都会失效；
对vector、string或的却、进行resize可能导致迭代器、指针和引用失效。
*/
//9.3.6 容器操作可能使迭代器失效
/*在向容器添加元素后：
如果容器是vector或string，且存储空间被重新分配，则指向容器的迭代器、指针和引用都会失效。
如果存储空间未重新分配，指向插入位置之前的元素的迭代器、指针和引用仍有效，但指向插入位置之后元素
的迭代器、指针和引用将失效。
对于deque，插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用失效。
如果在首尾位置添加元素，迭代器会失效，但指向存在的元素的引用和指针不会失效。
对于list和forward_list，指向容器的迭代器、指针和引用任然有效。
1.编写改变容器的循环程序
2.不要保存end()返回的迭代器*/

#include <iostream>
//vector 可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素肯可能很慢。
#include <vector>
//deque  双端队列。支持快速随机访问。在头尾位置插入/删除速度很快。
#include <deque>
//list   双向链表。只支持双向顺序访问。在list中任何位置进行插入/删除操作速度都很快。不提供下标操作
#include <list>
//forward_list  单项链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作速度都很快。不提供下标操作
#include <forward_list>
//array  固定大小数组。支持快速随机访问。不能添加户删除元素
#include <array>
//string 与vector相似的容器，但专门用于保存字符。随机访问快。在尾部插入/删除数度快
#include <string>
using namespace std;

int main()
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> di = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int> fi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> ai = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string s = "0123456789";
    auto beg = s.begin() + 10;
    s.push_back('i');
    cout << *beg << endl;
    //遍历
    //下标遍历  list和forward_list不提供下标操作
    for (vector<int>::size_type i = 0; i != vi.size(); ++i)
        cout << vi[i] << " ";
    cout << endl;
    for (decltype(di.size()) i = 0; i != di.size(); ++i)
        cout << di[di.size() - i - 1] << " ";
    cout << endl;
    for (decltype(ai.size()) i = 0; i != ai.size(); ++i)
        cout << ai[i] << " ";
    cout << endl;
    for (decltype(s.size()) i = 0; i != s.size(); ++i)
        cout << s[di.size() - i - 1] << " ";
    cout << endl;
    //for(:)遍历
    for (auto i : vi)
        cout << i << " ";
    cout << endl;
    for (auto i : di)
        cout << i << " ";
    cout << endl;
    for (auto i : li)
        cout << i << " ";
    cout << endl;
    for (auto i : fi)
        cout << i << " ";
    cout << endl;
    for (auto i : ai)
        cout << i << " ";
    cout << endl;
    for (auto i : s)
        cout << i << " ";
    cout << endl;
    //迭代器遍历
    for (vector<int>::iterator iter = vi.begin(); iter != vi.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    for (deque<int>::const_iterator citer = di.cbegin(); citer != di.cend(); ++citer)
        cout << *citer << " ";
    cout << endl;
    for (auto iter = li.cbegin(); iter != li.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    for (auto iter = fi.begin(); iter != fi.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    for (auto iter = ai.cbegin(); iter != ai.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    for (auto iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    vector<int>::difference_type dt = vi.end() - vi.begin();
    vi.insert(vi.begin() + 1, dt, 1);
    for (vector<int>::iterator iter = vi.begin(); iter != vi.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    int a = 1, b = 2, c = 3, d = 4;
    int aii[4] = {1, 2, 3, 4};
    const int *ip[4] = {&a, &b, &c, &d}; //包含4个指针的数组，指针指向const int类型
    const int(*icp)[4] = &aii;           //包含4个const int 的数组的指针
    const int(&icr)[4] = aii;            //包含4个const int 的数组的引用
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
    auto iter = vi.begin();
    while(iter!=vi.end())
    {
        if(*iter%2){
            iter = vi.insert(int, *iter);
            iter += 2;
        }else
            iter = vi.srase(iter);
    }
    return 0;
}
