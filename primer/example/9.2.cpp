//9.2 容器库概览
/*容器类型上的操作形成了一种层次:
某些操作是所有容器类型都提供的。
另外一些操作仅针对顺序容器，或无序容器。
还有一些操作只适合于一小部分容器。
容器定义的头文件，文件名与类型名相同。deque、list等
容器均定义为模板类。如vector，提供额外信息来生成特定的容器类型。
1.对容器可以保存的元素类型的限制
顺序容器几乎可以保存任意类型的元素。容器元素也可以是容器。
vector<vector<string>> lines;
较旧的编译器可能需要空格：
vector<vector<string> > lines;
某些容器对元素类型有其自己的特殊要求。
如顺序容器构造函数的一个版本接受容器大小参数，
它使用了元素类型的默认构造函数。
但某些类没有默认的构造函数。可以定义一个保存这种类型对象的容器，
但我们在构造这种容器时不能只传递给它一个元素数目参数。
//假定noDefault是一个没有默认构造函数的类型
vector<noDefault>v1(10,init);//正确：提供了元素初始化器
vector<noDefault>v2(10);//错误：必须提供一个元素初始化器
表9.2：容器操作
类型别名
iterator        此容器类型的迭代器类型
const_interator 可以读取元素，不能修改元素的迭代器类型
size_type       无符号整数类型，足够保存此种容器类型最大可能容器但大小
difference_type 带符号整数类型，足够保存两个迭代器之间的距离
value_type      元素类型
reference       元素的左值类型，与value_type&含义相同
const_reference 元素的const左值类型（即，const value_type&)
构造函数
C c             默认构造函数，构造空容器（array)
C c1(c2)        构造c2的拷贝c1
C c(b,e)        构造c，将迭代器b和e指定的范围内的元素拷贝到c（array不支持）
C c{a,b,c,...}  列表初始化c
赋值与swap
c1=c2           将c1中的元素替换为c2中的元素
c1={a,b,c...}   将c1中的元素替换为列表中的元素（适用于array，但列表元素个数必须小于等于c1大小）
a.swap(b)       交换a和b的元素
swap(a,b)       与a.swap(b)等价
大小
c.size()        c中元素的数目（不支持forward_list）
c.max_size()    c可以保存的最大元素数目
c.empty()       若c中存储了元素，返回false，否则返回true
添加/删除元素（不适用于array）
//在不同容器中，这些操作的接口都不同
c.insert(args)  将args中的元素拷贝进c
c.emplace(inits)使用inits构造c中的一个元素
c.erase(args)   删除args指定的元素
c.clear()       删除c中的所有元素，返回void
关系运算符
==,!=           所有容器都支持相等（不等）运算符
<,<=,>,>=       关系运算符（无序关联容器不支持）
获取迭代器
c.begin(),c.begin() 返回指向c的首元素和尾元素之后位置的迭代器
c.cbegin(),c.cbegin()返回const_iterator
反向容器但额外成员（不支持forward_list）
reverse_iterator 按逆序寻址元素的迭代器
const_reverse_iterator 不能修改元素的逆序迭代器
c.rbegin(),c.rbegin()返回指向c的尾元素和首元素之前位置的迭代器
c.crbegin(),c.credn()返回const_reverse_iterator*/
//9.2.1迭代器
/*1.迭代器范围
一个迭代器范围（iterator range）由一对迭代器表示，
两个迭代器分别指向同一容器中的元素或者是尾元素之后的位置（one past the last element）。
这种元素范围被称为左闭合区间（left-inclusive interval）
2.使用左闭合范围蕴含的编程假定
这种范围有三种方便的性质：
如果 begin与end相等，则范围为空
如果begin与end不等，则范围至少包含一个元素
可以对begin递增若干次，使得begin==end*/
//9.2.2 容器类型成员
/*每个容器都定义类多个类型：size_type、iterator、const_iterator。
反向迭代器
类型别名，通过类型别名，可以在不了解容器中元素类型的情况下使用它。
元素类型：value_type,元素类型的一个引用reference或const_reference。
//iter是通过list<string>定义的一个迭代器类型
list<string>::iterator iter;
//count是通过vector<int>定义的一个difference_type类型
vector<int>::difference_type count;*/
//9.2.3 begin和end成员
/*当不需要写访问时，应使用cbegin和cend*/
//9.2.4 容器定义和初始化
/*每个容器类型都定义类一个默认构造函数，array除外。
表9.3：容器定义和初始化
C c           默认构造函数，如果C是一个array，则c中元素按默认方式初始化，否则为空
C c1(c2)      c1初始化为c2的拷贝。c1和c2必须是相同的类型，
C c1=c2       相同容器，相同元素类型。array类型，还必须相同大小。
C c{a,b,c...} c初始化为初始化列表中元素的拷贝。列表元素类型必须与C的元素类型相容。
C c={a,b,c...}对于array类型，列表中元素数目必须等于或小于array的大小。
C c(b,e)      c初始化为迭代器b和e指定范围中的元素的拷贝。
              范围中元素的类型必须与CD元素类型相容（array不适用）
只有顺序容器（不包括array）的构造函数才能接受大小参数
C seq(n)      seq包含n个元素，这些元素进行了值初始化，此构造函数是explicit的。
              string类型不适用
C seq(n,t)    seq包含n个初始化为值t的元素
1.将一个容器初始化为另一个容器但拷贝
//每个容器有三个元素，用给定的初始化器进行初始化
list<string>authors={"Milton","Shakespeare","Austen"}；
vector<const char*>articles={"a","an","the"};
list<string>list2(authors);//正确：类型匹配
deque<string>authList(authors);//错误：容器类型不匹配
vector<string>words(articles);//错误：容器元素类型必须匹配
//正确：可以将const char*元素转换为string
forward_list<string> words(articles.begin(), articles.begin());
由于迭代器表示一个范围，可以使用这种构造函数拷贝一个容器的子序列。
2.列表初始化
除array外，列表初始化还隐含地指定了容器的大小。
3.与顺序容器大小相关的构造函数
元素类型是内置类型或者是具有默认构造函数的类类型，
可以只为构造函数提供一个容器大小参数。
否则必须指定一个显式地元素初始值。
只有顺序容器（不包括array）的构造函数才能接受大小参数
4.标准库array具有固定大小
array<int,2>//2个int的数组
array<string,10>
array<int,10>::size_type i;
大小是array类型的一部分，array不支持普通容器构造函数。
一个默认构造的array是非空的，包含了与其大小一样多的元素。
这些元素都被默认初始化。与内置数组中的元素相同。
不能对内置数组进行拷贝或对象赋值操作，但array并无此限制。*/
//9.2.5 赋值和swap
/*赋值运算符将左边容器中的全部元素替换为右边容器中元素的拷贝。
如果两个容器原来大小不同，赋值运算后两者的大小都与右边容器的原大小相同。
与内置内置数组不同，标准库array类型允许赋值。
赋值号左右两边的运算对象必须具有相同的类型,不支持显式转换。
由于右边运算对象的大小可能与左边运算对象的大小不同，array不支持assign。
表9.4：容器赋值运算
c1=c2           将c1中的元素替换为c2中的元素的拷贝。c1和c2必须具有相同的类型。
                array还必须是相同的大小，其他容器拷贝后c1，c2大小同c2.
c={a1,a2,a3...} 将c1中元素替换为初始化列表中元素的拷贝，
                array适用，但注意列表元素个数小于等于array元素个数
swap(c1,c2)     交换c1和c2中的元素。c1和c2必须具有相同的类型。swap通常比从c2向c1拷贝元素快得多
c1.swap(c2)
assign操作不适用于关联容器和array
seq.assign(b,e) 将seq中的元素替换为迭代器b和e所表示的范围中的元素。迭代器b和e不能指向seq中的元素
seq.assign(il)  将seq中的元素替换为初始化列表il中的元素
seq.assign(n,t) 将seq中的元素替换为n个值为t的元素

赋值相关运算回导致指向左边容器内部的迭代器、引用和指针失效。
swap操作不会导致失效（array和string的情况除外）
1.使用assign（仅顺序容器）
赋值运算符要求左右两边运算对象类型相同，assign可以实现char*值赋予string类型对象
2.使用swap
除array外，swap不对任何元素进行拷贝、删除或插入操作，可以保证在常数时间内完成。
swap之后，指向容器的迭代器、引用、指针不会失效。
对于array和string使用swap交换后，交换了元素。指针因元素个数不同会失效。*/
//9.2.6 容器大小操作
/*每个容器类型有三个大小操作
size返回容器元素的数目
empty当size为0时返回布尔值true，否则返回false
max_size返回一个大于或等于该类型容器所能容纳的最大元素数的值
forward_list支持max_size和empty，不支持size*/
//9.2.7 关系运算符
/*每个容器都支持相等运算符==和!=；
除了无序容器外的所有容器都支持关系运算符>,>=,<,<=。
关系运算符左右两端的运算对象必须是相同类型的容器，且必须保持元素类型相同。
比较两个容器实际上进行元素的逐对比较。与string的关系运算相似。
如果两个容器具有相同大小且所有元素都两两相等，则两个容器相等；否则不等。
如果两个容器大小不同，当较小容器中每个元素都等于较大容器中对应的元素，则较小容器小于较大容器。
如果两个容器不是另一个容器的前缀子序列，则它们的比较结果取决于第一个不想等元素的比较结果。
1.容器的关系运算符使用元素的关系运算符完成比较。
如果容器的元素不支持==和<运算，则容器也不能使用相应的关系运算。*/
#include <iostream>
#include <array>
#include <vector>
#include <list>
using namespace std;

int main()
{
    array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> a2 = {0}; //所有元素均为0
    array<int, 10> a3 = a1;  //默认初始化很奇怪啊？所以没有默认构造函数？
    a1 = a2;                 //替换a1中的元素，a2的大小必须哈a1相同
    a2 = {0};                //能将一个花括号类别赋予数组。列表大小不能大于a1大小
    auto iter3 = a1.begin()+1;
    cout << *iter3 << " ";
    a1.swap(a3);
    cout << *iter3 << endl;//元素交换了位置
    for (auto i = a1.begin(); i != a1.end(); ++i)
        cout << *i << " ";
    cout << endl;
    vector<int> vi1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi2 = {0};
    vector<int> vi3 = vi1;
    vector<int> vi4(4, 25);
    vi1 = vi2;
    vi2 = {0, 3};
    auto iter = vi2.begin()+1;
    cout << *iter << " ";
    vi2.swap(vi3);
    cout << *iter << endl;//iter指向的元素不变
    vi1.assign(vi2.begin(), vi2.begin());
    for (auto i = vi2.begin(); i != vi2.end(); ++i)
        cout << *i << " ";
    cout << endl;
    list<string> names;
    list<string> vs = {"abc", "Hello", "world"};
    auto iter1 = vs.begin();
    cout << *iter1 << " ";
    names.swap(vs);
    cout << *iter1 << endl;//元素不变
    vector<const char *> oldstyle = {"abc", "Hello", "world"};
    //正确，可以将const char*转换为string
    names.assign(oldstyle.cbegin(), oldstyle.cend());
    for (auto i : names)
        cout << i << " ";
    cout << endl;
    //等价于slist1.clear();
    //后跟slist1.insert(slist1.begin(),10,"Hiya!");
    list<string> slist1(1);     //1个元素，为空string
    slist1.assign(10, "Hiya!"); //10个元素，每个都是“Hiya!”
    string s1 = "Hello!W", s2 = "World!";
    auto iter2 = s1.begin();
    cout << *iter2 << " ";
    swap(s1, s2);
    cout << *iter2 << endl;//元素交换了位置
    for (auto i = s1.begin(); i != s1.end(); ++i)
        cout << *i << " ";
    cout << endl;
    string s3(4, 't');
    return 0;
}
