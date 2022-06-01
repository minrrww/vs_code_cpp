#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(),nums2.begin(),nums2.end());
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < m+n; ++i)
        {

        }
    }
};
int main()
{

    return 0;
}
//1 2 3 6 10
//4 5 99 101 202 909
