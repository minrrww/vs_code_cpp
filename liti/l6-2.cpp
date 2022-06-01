#include <iostream>

using namespace std;
//计算二维数组a每行元素的值得和，nRow是行数
void rowSum(int a[][4], int nRow) //数组作为参数时，一般不指定第一维的大小，即使指定，也会背被忽略
{
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 1; j < 4; j++)
            a[i][0] += a[i][j]; //改变形参数组元素的值，会影响函数实参的值
    }
}
int main() //主函数
{
    //声明并初始化数组
    int table[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
    for (int i = 0; i < 3; i++) //输出数组元素
    {
        for (int j = 0; j < 4; j++)
            cout << table[i][j] << "  ";
        cout << endl;
    }
    rowSum(table, 3);           //调用子函数，计算各行和
    for (int i = 0; i < 3; i++) //输出计算结果
        cout << "Sum of row " << i << " is " << table[i][0] << endl;
    for (int i = 0; i < 3; i++) //输出数组元素
    {
        for (int j = 0; j < 4; j++)
            cout << table[i][j] << "  ";
        cout << endl;
    }
    return 0;
}
/*
1  2  3  4
2  3  4  5
3  4  5  6
Sum of row 0 is 10
Sum of row 1 is 14
Sum of row 2 is 18
10  2  3  4
14  3  4  5
18  4  5  6
*/
