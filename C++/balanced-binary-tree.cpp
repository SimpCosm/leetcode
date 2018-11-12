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
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }

    int getDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = getDepth(root->left);
        if (left == -1) return -1;
        int right = getDepth(root->right);
        if (right == -1) return -1;
        if (abs(left-right) > 1) return -1;
        return 1+max(left, right);
    }

};
