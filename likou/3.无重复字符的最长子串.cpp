#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(128, 0);
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            i = max(i, m[s[j]]); //i为上次出现字符s[j]字符的位置，从0开始。
            m[s[j]] = j + 1;     //m['a']=m[97]=1,出现a的位置是1，m['b']=m[98]=2,出现b的位置是2，出现c的位置是3，出现a的位置是4，a重复，上次出现a的位置是i=1
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution so;
    string s = "abcabcbb";
    cout << so.lengthOfLongestSubstring(s) << endl;
    return 0;
}
