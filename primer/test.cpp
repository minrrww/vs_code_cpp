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
}
