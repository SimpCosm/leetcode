/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/balanced-binary-tree
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!root->left) return 1+right;
        if (!root->right) return 1+left;
        return 1+min(left, right);
    }
};
