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
        ListNode *pNode = new ListNode(0);

        while (head)
        {
            auto tmp = head->next;
            head->next = pNode->next;
            pNode->next = head;
            head = tmp;
        }
        return pNode->next;
    }
};
