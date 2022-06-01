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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            carry = carry / 10 + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            if (!head)
                head = tail = new ListNode(carry % 10);
            else
                tail = tail->next = new ListNode(carry % 10);
            if (l1)
                l1 = l1->next;//l1=l1 ? l1->next : nullptr;
            if (l2)
                l2 = l2->next;//l2=l2 ? l2->next : nullptr;
        }
        tail->next = (carry / 10 ? new ListNode(carry / 10) : nullptr);
        return head;
    }
};
int main()
{
    ListNode l4(0);
    ListNode l3(7,&l4);
    ListNode l2(7, &l3);
    ListNode l1(1, &l2);
    ListNode h4(0);
    ListNode h3(6,&h4);
    ListNode h2(5, &h3);
    ListNode h1(4, &h2);
    Solution s;
    ListNode *lp = s.addTwoNumbers(&l3, &h3);
    ListNode *w = lp;
    while (w != nullptr)
    {
        cout << w->val << " ";
        w = w->next;
    }
    cout << endl;
    return 0;
}
