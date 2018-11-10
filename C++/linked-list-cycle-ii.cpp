/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/linked-list-cycle-ii
 *
 * Solution:
 *  If there is a cycle, assume the beginning is the kth node.
 *  The slower pointer moves m = k + x + qn, the faster moves (2m - m = pn = m) more nodes.
 *  The k + x = (p-q)n;
 *  So, after moving k nodes, they will meet again in the beginning.
 */
#include <stdio.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
