
            l1->next->val += 1;
            l1->val %= 10;
            if (l1->next->val / 10)
                l1->next = addTwoNumbers(l1->next, new ListNode(0));
            else
                l1->next = new ListNode(1);
        