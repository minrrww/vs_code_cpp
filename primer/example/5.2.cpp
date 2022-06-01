//5.2 语句作用域
/*在if、switch、while和for语句的控制结构内定义的变量，其内部可见
  如果其他代码需要访问控制变量，则变量必须定义在语句的外部。*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int get_num = 0;
    while (int i = get_num) //每次迭代时创建并初始化i
        cout << i << endl;
    //寻找第一个负值元素
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto beg = v.begin();
    while (beg != v.end() && *beg >= 0)
        ++beg;
    if (beg == v.end())
        cout << "v中每个元素都大于等与0" << endl;
    return 0;
}
/*v中每个元素都大于等与0*/
