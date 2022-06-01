#include <iostream>
using namespace std;

int main()
{
    int i;//声明整型变量i
    int *ptr = &i;//声明并初始化整型指针变量ptr
    i = 10;//把10赋值给i
    cout << "i=" << i << endl;//输出变量i的值
    cout << "*ptr=" << *ptr << endl;//输出指针ptr指向的内容
    return 0;
}
/*输出
i=10
*ptr=10
*/
