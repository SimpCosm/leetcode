/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Desciption:
 *  Given a sorted linked list, delete all duplicates such that each element appear only once.
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
        while (head) {
            while (head->next && head->next->val == head->val)
                head = head->next;
            cur->next = head;
            cur = cur->next;
            head = head->next;
        }
        return pNode->next;
    }
};
