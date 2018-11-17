/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * Description:
 *  Given a linked list, swap every two adjacent nodes and return its head.
 *  For example,
 *  Given `1->2->3->4`, you should return the list as `2->1->4->3`.
 *  You algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pNode = new ListNode(0);
        pNode->next = head;
        ListNode* cur = pNode;
        while (cur->next && cur->next->next) {
            auto next_one = cur->next;
            auto next_two = next_one->next;
            auto next_three = next_two->next;
            cur->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            cur = next_one;
        }
        return pNode->next;
    }
};
