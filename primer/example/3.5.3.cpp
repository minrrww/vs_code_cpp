//example-3.5.3-.cpp
#include <iostream>
using namespace std;
int main()
{
    string nums[] = {"one", "two", "three"}; //数组的元素是string对象
    string *pstr1 = &nums[0];                //pstr1指向nums的第一个元素
    string *pstr2 = nums;                    //等价于*pstr2=&nums[0]
    cout << *pstr1 << " " << *pstr2 << endl; //输出pstr1,pstr2指向的对象
    cout << (pstr1 == pstr2) << endl;        //输出两个指针是否相等

    int ia1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //ia是一个含有10个整数的数组
    auto ia2(ia1);                              //ia2是一个整型指针，指向ia的第一个元素。等价于auto ia2(&ia[0])
    //ia2 = 43;                                 //错误：ia2是一个指针，不能用int值给指针赋值
    cout << ia1[5] << " " << *(ia2 + 5) << endl; //输出ia[5]和ia2+5指针指向的对象

    //ia3是一个含有10个整数的数组
    decltype(ia1) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //ia3 = p;    //错误，不能用整型指针给数组赋值
    int i = 10;
    ia3[4] = i;                                  //正确：把i的值付给ia3的一个元素
    cout << ia1[4] << " " << *(ia3 + 4) << endl; //对比ia[4]和ia3+4指向的对象

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ip = arr; //ip指向arr的第一个元素
    cout << *ip << " ";
    ++ip; //p指向arr[1];
    cout << *ip << endl;

    int *e1 = &arr[10]; //指向arr尾元素的下一个位置的指针
    cout << e1 << endl; //输出尾后指针

    int *beg = begin(ia1);                 //指向ia首元素的指针
    int *last = end(ia1);                  //指向ia尾元素的下一位置的指针
    cout << end(ia1) - begin(ia1) << endl; //输出尾后指针和首指针之间的距离

    constexpr size_t sz = 5;
    int arr1[sz] = {1, 2, 3, 4, 5};
    int *ip1 = arr1;                     //等价于int *ip1=&arr[0]
    int *ip2 = ip1 + 4;                  //ip2指向arr的尾元素arr[4]
    cout << *ip1 << " " << *ip2 << endl; //指针加法

    int *ip3 = arr1 + sz; //不能解引用
    //int *p2 = arr1 + 10; //错误，arr只有5个元素，p2的值未定义

    auto n = end(arr1) - begin(arr1); //n的值是5，也是arr中元素的数量

    int *b = arr1, *e = arr1 + sz;
    while (b < e)
    {
        cout << *b; //使用*b;
        ++b;
    }
    cout << endl;

    int ia[] = {0, 2, 4, 6, 8}; //含有5个整数的数组
    int last1 = *(ia + 4);      //相当于把ia[4]初始化给last
    int last2 = *ia + 4;        //相当于把ia[0]+4初始化给l
    cout << last1 << " " << last2 << endl;

    int a = ia[2];  //ia转换成指向数组首元素的指针
                    //ia[2]得到(ia+2)所指的元素
    int *ap = ia;   //ap指向ia的首元素
    a = *(ap + 2);  //等价于i=ia[2]
    ap = &ia[2];    //ap指向索引为2的元素
    int j = ap[1];  //ap[1]等价于*(p+1),就是ia[3]表示的那个元素
    int k = ap[-2]; //ap[-2]等价于*(ap-2),就是ia[0]表示的那个元素
    cout << a << " " << j << " " << k << endl;
    return 0;
}
