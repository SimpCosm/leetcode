/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Desciption:
 *  Given a sorted linked list, delete all nodes that have duplicate numbers. leaving only distinct numbers from the original list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pNode = new ListNode(0);
        ListNode* cur = pNode;
        bool flag = false;
        while (head) {
            while (head->next && head->next->val == head->val)
            {
                head = head->next;
                flag = true;
            }
            if (!flag)
            {
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
            flag = false;
        }
        cur->next = nullptr;
        return pNode->next;
    }
};
