//eaample-3.6-.cpp
#include <iostream>
using namespace std;

int main()
{
    //大小为3的数组，每个元素是含有4个整数的数组
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //大小为10的数组，每个元素都是大小为20的数组
    //这些数组的元素是含有30个整数的数组
    int arr[10][20][30] = {11};                 //将所有元素初始化为0
    cout << ia[2][3] << endl;                   //下标输出
    cout << *(*(ia + 2) + 3) << endl;           //解引用输出
    cout << *(end(*(end(ia) - 1)) - 1) << endl; //迭代器解引用
    ia[2][3] = arr[0][0][0];                    //赋值
    cout << ia[2][3] << endl;                   //下标输出
    cout << *(*(ia + 2) + 3) << endl;           //解引用输出
    cout << *(end(*(end(ia) - 1)) - 1) << endl; //迭代器解引用
    //把引用row绑定到ia的第二个数组上,引用的是一个数组名(指针变量)
    int(&row)[4] = ia[1];
    cout << *row << endl;
    //迭代器给多维数组赋值

    for (auto i = begin(ia); i != end(ia); i++)
    {
        for (auto j = begin(*i); j != end(*i); j++)
        {
            *j = *j * *j; //赋值
            cout << *j << " ";
        }
    }
    cout << endl;

    //下标遍历多维数组
    for (decltype(end(ia) - begin(ia)) i = 0; i != end(ia) - begin(ia); i++)
    {
        for (ptrdiff_t j = 0; j != end(ia[i]) - begin(ia[i]); j++) //数组迭代器距离的数据类型ptrdiff_t
        {
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;

    //范围for语句遍历多维数组
    //改变数组元素的值，row、col需要定义为引用
    //不改变数组元素的值，row需要定义为引用，避免数组被自动转成指针
    //如果row不定义为引用，row会被认为是指向首元素int *类型的指针
    //内循环就不合法了
    for (const auto &row : ia)
        for (auto col : row)
            cout << col << " ";
    cout << endl;

    //p是指针，指向维度是4的数组，数组的元素类型是整数
    //p指向第一层数组ia[],p=&ia[]
    //int(*p)[4] = ia; //p指向含有4个整数的数组,用ia数组的首地址初始化auto p=ia;
    //p = &ia[2];//p指向ia的尾元素
    //cout << *(*p) << endl;
    //指针遍历多维数组
    for (int(*p)[4] = ia; p != ia + (end(ia) - begin(ia)); p++)
    {
        for (auto q = *p; q != *p + (end(*p) - begin(*p)); q++) //数组迭代器距离的数据类型ptrdiff_t
        {
            cout << *q << " ";
        }
    }
    cout << endl;

    //类型别名简化多维数组的指针
    using int_array = int[4]; //新标准下类型别名声明
    typedef int intArray;     //等价的typedef 类型别名声明
    for (int_array *p = ia; p != ia + (end(ia) - begin(ia)); p++)
    {
        for (intArray *q = *p; q != *p + (end(*p) - begin(*p)); q++) //数组迭代器距离的数据类型ptrdiff_t
        {
            cout << *q << " ";
        }
    }
    cout << endl;

    return 0;
}
/*
11
11
11
11
11
11
4
0 1 4 9 16 25 36 49 64 81 100 121
0 1 4 9 16 25 36 49 64 81 100 121
0 1 4 9 16 25 36 49 64 81 100 121
0 1 4 9 16 25 36 49 64 81 100 121
0 1 4 9 16 25 36 49 64 81 100 121
*/
