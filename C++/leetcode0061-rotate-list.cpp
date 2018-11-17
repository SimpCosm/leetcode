/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/rotate-list
 *
 * Description:
 *  Given a list, rotate the list to the right by k places, where k is non-negative.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode *newH = head, *tail = head;
        int len = 1;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        if (k %= len) {
            for (auto i = 0; i < len-k; i++)
                tail = tail->next;
        }

        newH = tail->next;
        tail->next = nullptr;
        return newH;
    }
};
