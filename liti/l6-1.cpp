#include <iostream>
#include <iomanip>
using namespace std;

int main() //主函数
{
    int a[10], b[10];            //生命两个元素个数为10的一维数组
    for (int i = 0; i < 10; i++) //利用for循环为两个数组赋值
    {
        a[i] = i * 2 - 1;
        b[10 - i - 1] = a[i];
    }
    for (int i = 0; i < 10; i++) //利用for循环将两个数组依次打印到屏幕上
    {
        cout << "a[" << i << "] =" << setw(3) << a[i] << "    ";
        cout << "b[" << i << "] =" << setw(3) << b[i] << endl;
    }
    return 0;
}
/*输出
a[0] = -1    b[0] = 17
a[1] =  1    b[1] = 15
a[2] =  3    b[2] = 13
a[3] =  5    b[3] = 11
a[4] =  7    b[4] =  9
a[5] =  9    b[5] =  7
a[6] = 11    b[6] =  5
a[7] = 13    b[7] =  3
a[8] = 15    b[8] =  1
a[9] = 17    b[9] = -1
*/
