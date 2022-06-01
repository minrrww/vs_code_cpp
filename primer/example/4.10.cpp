//4.10 逗号运算符
//1.逗号运算符（comma operator)含有两个运算对象，按照从左至右的顺序依次求值。
//2.逗号运算符规定了求值顺序，先求左侧表达式值，将结果丢弃。
//3.求值结果是右侧表达式的值，如果右侧是左值，结果就是左值。
//4.逗号运算符常被用在for循环中。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::size_type cnt = ivec.size();
    //将把从size到1的值赋给ivec的元素
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        cout << (ivec[ix] = cnt) << " ";
    cout << endl;
    return 0;
}
/*
10 9 8 7 6 5 4 3 2 1
*/
