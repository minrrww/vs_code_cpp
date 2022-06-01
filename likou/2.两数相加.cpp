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
        //定义指针变量p，q指向l1，l2指向的对象，当其值改变时，指向的对象也随之改变。
        ListNode *p = l1, *q = l2;
        //对应第一节点数字之和。循环制为对应节点数字之和，不得在循环中赋值为第一节点之和。
        int n = p->val + q->val;
        //声明返回变量的l3的初值，不得改变其指向的对象。pl初值指向l3的对象，循环中改变其对象。
        ListNode *l3 = new ListNode(n % 10), *pl = l3;
        //当对应节点的指针数据成员同时为nullptr时，循环结束
        while (p->next && q->next)
        {
            if (!(p = p->next))                   //如果指针数据成员为nullptr，则为其赋值一个新指针。
                p = new ListNode();               //节点个数对齐
            if (!(q = q->next))                   //如果指针数据成员为nullptr，则为其赋值一个新指针。
                q = new ListNode();               //节点个数对齐
            n = n / 10 + (p->val + q->val);       //条件中的指针指向的对象的整数成员与n值相加
            pl = pl->next = new ListNode(n % 10); //改变指针指向对象，并赋值，右结合律
        }                                         //循环结束，数据成员指针同时指向nullprt
        if (n / 10)                               //商不为0
            pl->next = new ListNode(n / 10);      //则给最后的指针赋值。
        return l3;
    }
};
int main()
{

    ListNode l4(0);
    ListNode l3(7, &l4);
    ListNode l2(7, &l3);
    ListNode l1(1, &l2);
    ListNode h4(0);
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
