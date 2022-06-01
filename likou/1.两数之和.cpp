#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i != n - 1; ++i)
            for (int j = i + 1; j != n; ++j)
                if (nums[j] + nums[i] == target)
                    return {i, j};
    }
};
int main()
{
    Solution s;
    vector<int> vi = {2, 7, 11, 15};
    vector<int> tw = s.twoSum(vi, 26);
    cout << (*tw.begin()) << " " << *(tw.begin() + 1) << endl;
    return 0;
}
