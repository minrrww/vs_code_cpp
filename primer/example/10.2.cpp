//10.2 初识泛型算法
/*标准库提供了超过100个算法。这些算法有一致的结构。
除了少数例外，标准库算法都对一个范围内的元素进行操作。
我们将此元素范围称为“输入范围”。
理解算法的最基本方法就是了解它们是否读取元素、改变元素或是重排元素顺序。*/
//10.2.1 只读算法
/*find(),count(),accumulate()都是只读算法。
accumulate()算法定义在numeric中。
accumulate的第三个参数的类型决定了函数中使用哪个加法运算符以及返回值的类型。
1.算法和元素类型
accumulate将第三个参数作为求和起点，这蕴含着一个编程假定：
将元素类型加到和的类型上的操作必须是可行的。
即，序列中元素的类型必须与第三个参数匹配，或者能够转换为第三个参数的类型。
由于string定义了+，可以用accumulate将vector中所有string元素连接起来。
由于const char*类型没有+运算符，使用C风格字符串将产生编译错误。
2.操作两个序列的算法
只读算法equal，用于确定两个序列是否保存相同的值。如果对应元素都相等，返回true，否则，返回false。
equal用迭代器完成操作，可以比较不同容器类型的元素。元素类型也不必一样。
但第二个序列至少与第一个序列一样长。
那些只接受一个单一迭代器来表示第二个序列的算法，都假定第二个序列至少与第一个序列一样长。
*/
//10.2.2 写容器元素的算法
/*一些算法将新值赋予序列中的元素。
当我们使用这类算法时，必须注意确保序列原大小至少不小于我们要求算法写入的元素数目。
关键概念：迭代器参数
一些算法从两个序列中读取元素。构成这两个序列的元素可以来自于不同类型的容器。
两个序列中元素的类型也不要求严格匹配。
算法要求的只是能够比较两个序列中的元素。
操作两个序列的算法之间区别在于我们如何传递第二个序列。equal接受三个迭代器，其他接受四个迭代器。
用一个单一迭代器表示第二个序列的算法都假定第二个序列至少与第一个一样长。
确定算法不会试图访问第二个序列中不存在的元素是程序员的责任。
1.算法不检查写操作
一些算法接受一个迭代器指出一个单独的目的位置。
这些算法将新值赋予一个序列中的元素，该序列从目的位置迭代器指向的元素开始。
向目的位置迭代器写入数据的算法假定目的位置足够大，能容纳要写入的元素。
2.介绍back_inserter
一种保证算法有足够元素空间来容纳输出数据的方法是使用插入迭代器（insert iterator）。
插入迭代器是一种向容器中添加元素的迭代器。
当我们通过一个迭代器像容器元素赋值时，值被赋予迭代器指向的元素。
当我们通过一个插入迭代器赋值时，一个与赋值号右侧相等的元素不添加到容器中。
back_inserter是定义在头文件iterator中的一个函数。
back_inserter接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器。
通常使用back_inserter来创建一个迭代器，作为算法的目的位置来使用。
3.拷贝算法
拷贝（copy）算法是另一个像目的位置迭代器指向的输出序列中的元素写入数据的算法。
此算法接受三个迭代器，前两个表示一个输入范围，第三个表示目的的序列的起始位置。
此算法将输入范围中的元素拷贝到目的序列中。
传递给copy的目的序列至少要包含与输入序列一样多的元素，这一点很重要。
copy返回的是其目的位置迭代器递增后的值。
多个算法都提供所谓的“拷贝”版本。这些算法计算新元素的值，
但不会将它们放置在输入序列的末尾，而是创建一个新序列保存这些结果。
replace,replace_copy在头文件algorithm中，替换指定序列的元素，后者不改变原序列。*/
//10.2.3 重排容器元素的算法
/*某些算法会重排容器中元素的顺序，一个明显的例子是sort。
调用sort会重排输入序列的元素，使之有序，它是利用元素类型的<运算符来实现排序的。
1.消除重复单词
sort将按照字典顺序排序
2.使用unigue
unigue算法重排输入序列，将相邻的重复项消除，并返回一个指向不重复值范围末尾的迭代器。
3.使用容器操作删除元素
为了真正删除无用元素，我们必须使用容器操作。*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <list>
using namespace std;
void print(vector<int>);
void print(vector<string>);
void elimDups(vector<string> &);
void fun_0()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //对vec中的元素求和，和的初值是0
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;
}
void fun_1()
{
    vector<string> v{"1", "2", "3"};
    string sum = accumulate(v.cbegin(), v.cend(), string("")); //第三个参数必须显式创建一个string
    cout << sum << endl;

    vector<int> roster1{1, 2, 3, 4, 5, 6}, roster2{1, 2, 3, 4, 5};
    roster2.push_back(6);
    //roster2中的元素数目应该至少与roster1一样多
    bool eq = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    cout << eq << endl;
}
void fun_2()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec);
    fill(vec.begin(), vec.end(), 0); //将每个元素重置为0
    print(vec);
    //将容器的子序列设置为10；
    fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
    print(vec);
    fill_n(vec.begin(), vec.size(), 0); //将所有元素重置为0
    print(vec);
    fill_n(vec.begin() + 1, vec.size() - 2, 10);
    print(vec);
    auto it = back_inserter(vec); //通过它赋值会将元素添加到vec中
    *it = 42;
    print(vec);
    vector<int> v; //空向量
    //正确：back_inserter创建一个插入迭代器，可用来像v添加元素
    fill_n(back_inserter(v), 10, 0); //添加10个元素到v
    print(v);
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)]; //a2与a1大小一样
    //ret指向拷贝到a2的尾元素之后的位置
    auto ret = copy(begin(a1), end(a1), a2); //把a1的内容拷贝给a2
    list<int> ilst(10, 0);
    //将所有值为0的元素改为42
    replace(ilst.begin(), ilst.end(), 0, 42);
    //使用back_inserter按需要增长目标序列
    vector<int> ivec;
    replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(ivec), 42, 1);
    print(ivec);
}
void fun_3()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
}
void elimDups(vector<string> &words)
{
    //按字典序排序words，以便查找重复单词
    sort(words.begin(), words.end());
    print(words);
    //unique重排输入范围，使得每个单词只出现一次
    //排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unigue = unique(words.begin(), words.end());
    print(words);
    //使用向量操作erase删除重复单词
    words.erase(end_unigue, words.end());
    print(words);
}
void print(vector<int> vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}
void print(vector<string> vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}
int main()
{
    fun_0();
    fun_1();
    fun_2();
    fun_3();
    return 0;
}
