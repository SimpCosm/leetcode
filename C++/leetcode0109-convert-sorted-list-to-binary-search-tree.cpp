/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei
 *
 * Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
 *
 */

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        return toBST(head, nullptr);
    }

    TreeNode* toBST(ListNode* head, ListNode* tail) {
        ListNode *slow = head, *fast = head;
        if (head == tail) {
            return nullptr;
        }
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = toBST(head, slow);
        root->right = toBST(slow->next, tail);
        return root;
    }
};
