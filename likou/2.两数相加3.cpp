#include <iostream>
using namespace std;
//Definition for singly-linked list->
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        l2->val = l1->val + l2->val;
        if (l2->val / 10)
        {
            if (l2->next)
            {
                l2->next->val += l2->val / 10;
                l2->next = addTwoNumbers(new ListNode(), l2->next);//此处只能说new ListNode()
            }
            else
                l2->next = new ListNode(l2->val / 10);
        }
        l2->val %= 10;
        l2->next = addTwoNumbers(l1->next, l2->next);
        return l2;
    }
};
int main()
{
    ListNode a1(0);
    ListNode a2(0, &a1);
    ListNode a3(0, &a2);
    ListNode a4(9);

    ListNode b1(9);
    ListNode b2(9, &b1);
    ListNode b3(9, &b2);
    ListNode b4(1,&b3);

    Solution s;
    auto *sum = s.addTwoNumbers(&a4, &b4);
    ListNode *b = &b4;
    while (sum)
    {
        cout << sum->val << " ";
        sum = sum->next;
    }
    cout << endl;

    return 0;
}
