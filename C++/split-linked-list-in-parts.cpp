/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei
 *
 * Source: https://leetcode.com/problems/split-linked-list-in-parts
 *
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        for (ListNode* node = root; node != nullptr; node = node->next)
            len++;
        int n = len/k, r = len%k;
        ListNode *node = root, *prev = nullptr;
        for (int i = 0; node != nullptr && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};
