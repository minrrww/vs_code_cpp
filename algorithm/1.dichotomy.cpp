//
#include <iostream>
#include <vector>
using namespace std;
//dichotomy 二分法
int binary_search(const vector<int> vi, const int item, int &nums)
{
    auto a = *vi.cbegin(), b = *(vi.cend() - 1);
    if (a == b)
    {
        if (a == item)
            return a;
        else
            return -1;
    }
    else
    {
        int low = a < b ? a : b, high = a > b ? a : b, mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (mid == item)
                return mid;
            else
            {
                if (mid > item)
                {
                    high = mid;
                    nums += 1;
                }
                else if (mid < item)
                {
                    low = mid;
                    nums += 1;
                }
            }
        }
    }
}
//排序算法
vector<int> &selectionSort(vector<int> &vi)
{
    int smallest = *vi.begin();
    for (auto beg = vi.begin()+1; beg != vi.end(); ++beg)
    {
        if (smallest > *beg)
        {
            smallest = *beg;
            vi.insert(vi.begin(), smallest);
            vi.erase(beg);
        }
    }
    return vi;
}
//按顺序输出
void print(const vector<int> vi)
{
    for (auto i : vi)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<int> vi, vi2 = {0, 1}; //
    for (int i = 0; i != 100; ++i)
        vi.push_back(99 - i);
    print(vi);
    //查找40
    int n = 0;
    cout << binary_search(vi, 40, n) << " " << n << endl;
    print(selectionSort(vi));

    return 0;
}
