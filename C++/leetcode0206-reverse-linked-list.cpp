/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/problems/reverse-linked-list
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
    ListNode* reverseList(ListNode* head) {
        ListNode *tail = nullptr;
        ListNode *iter = head;
        while (iter) {
            ListNode *tmp = iter->next;
            iter->next = tail;
            tail = iter;
            iter = tmp;
        }
        return tail;

    }
};
