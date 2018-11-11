/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/problems/reverse-linked-list-ii
 *
 * Description:
 *  Reverse a singly linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *l1 = pre;
        for (int i = 1; i < m; i++) {
            l1 = l1->next;
        } // l1->next = begin of second

        ListNode *start = l1->next;
        ListNode *then = start->next;

        for (int i = 0; i < n-m; i++) {
            start->next = then->next;
            then->next = l1->next;
            l1->next = then;
            then = start->next;
        }

        return pre->next;

    }
};
