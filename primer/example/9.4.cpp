//9.4 vector对象是如何增长的
/*虽然vector在每次重新分配内存空间时都要移动所有元素，
但使用此策略后，其扩张操作通常比list和deque还要快。
1.管理容量的成员函数
表9.10：容器大小管理操作
shrink_to_fit只适用于vector、string和deque
capacity和reserve只适用于vector和string
c.shrink_to_fit()    请将capacity()减少为与size()相同大小。
c.capacity()         不重新分配内存空间的话，c可以保存多少元素
c.reserve(n)         分配至少能容纳n个元素的内容空间。
reserve 并不改变容器中元素的数量，仅影响vector预先分配多大的内存空间。
reserve永远不会减少容器占用的内存空间。
2.capacity和size
size是指它已经保存的元素的数目
capacity则是在不分配新的内存空间的前提下它最多可以保存多少元素。
每个vector实现都可以选择自己的内存分配策略。但是必须遵守的一条原则是：
只有当迫不得已时才可以分配新的内存空间。*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    ivec.reserve(50);
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    ivec.push_back(42);
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    ivec.shrink_to_fit();
    cout << " ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    return 0;
}
