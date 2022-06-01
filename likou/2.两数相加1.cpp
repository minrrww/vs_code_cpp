#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int n = 0)//递归法
    {
        if (l1 || l2)
        {
            n += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            ListNode *r = new ListNode(n % 10);
            r->next = addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, n / 10);
            return r;
        }
        else
            return (n) ? new ListNode(n) : nullptr;
    }
};
int main()
{
    ListNode l4(9);
    ListNode l3(7, &l4);
    ListNode l2(7, &l3);
    ListNode l1(1, &l2);
    ListNode h4(9);
    ListNode h3(1, &h4);
    ListNode h2(5, &h3);
    ListNode h1(4, &h2);
    Solution s;
    ListNode *lp = s.addTwoNumbers(&l1, &h1);
    ListNode *w = lp;
    while (w != nullptr)
    {
        cout << w->val << " ";
        w = w->next;
    }
    cout << endl;
    return 0;
}
