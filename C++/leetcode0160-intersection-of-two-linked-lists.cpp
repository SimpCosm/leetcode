/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/intersection-of-two-linked-lists
 *
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA-lenB; i++) {
                p1 = p1->next;
            }
        } else {
            for (int i = 0; i < lenB-lenA; i++) {
                p2 = p2->next;
            }
        }

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }

    int getLength(ListNode *head) {
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        return len;
    }
};
