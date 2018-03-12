/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/merge-two-sorted-lists
 *
 * Description:
 *  Merge two sorted lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 *  Example:
 *  ```
 *  Input: 1->2->4, 1->3->4
 *  Output: 1->1->2->3->4->4
 *  ```
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *pNode = new ListNode(0);
        ListNode *cur = pNode;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;

        return pNode->next;
    }
};
