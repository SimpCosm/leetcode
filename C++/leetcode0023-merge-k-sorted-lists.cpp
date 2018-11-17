/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/merge-k-sorted-lists
 *
 * Description:
 *  Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        int left = 0, right = lists.size() - 1;
        while (right > 0) {
            if (left >= right) {
                left = 0;
            } else {
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                ++left;
                --right;
            }
        }
        return lists[0];
    }
private:
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
