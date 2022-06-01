#include <iostream>
using namespace std;
int main()
{
    //void voidObject;  // 错，不能声明void 类型变量
    void *pv;           //可以声明void类型指针
    int i = 5;
    pv = &i;//void类型指针指向整型变量
    int *pint = static_cast<int *>(pv);//void 类型指针赋值给int类型指针
    cout << "*pint=" << *pint << endl;
    return 0;
}
/*
*pint=5
*/
