#include <iostream>
using namespace std;
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0; i < 10; i++)
        cout << a[i] << "  "; //使用数组名和下标
    cout << endl;
    for (int *p = a + 9; p >= a; p--)
        cout << *p << "  "; //使用指针变量
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << *(a + i) << "  "; //使用数组名和指针
    cout << endl;
    return 0;
}
/*
1  2  3  4  5  6  7  8  9  0
0  9  8  7  6  5  4  3  2  1
1  2  3  4  5  6  7  8  9  0
*/
