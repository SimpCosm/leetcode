/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/merge-two-binary-trees
 *
 * Description:
 *  Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 *
 *  You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, them sum node values up as the new value of the merged node. Other wise, the NOT null node will be used as the node of new tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;

        TreeNode* pNode = new TreeNode(0);
        pNode->val = t1->val + t2->val;
        pNode->left = mergeTrees(t1->left, t2->left);
        pNode->right = mergeTrees(t1->right, t2->right);
        return pNode;
    }
};
