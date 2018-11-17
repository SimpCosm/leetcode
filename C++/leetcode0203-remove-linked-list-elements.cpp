/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/remove-linked-list-elements
 *
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *iter = pre;
        while (iter->next) {
            ListNode *ele = iter->next;
            if (ele->val == val) {
                iter->next = ele->next;
            } else {
                iter = ele;
            }
        }
        return pre->next;
    }
};
