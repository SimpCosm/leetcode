/*
 * Copyright (C) 2018 all reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/invert-binary-tree
 *
 * Description:
 *  Invert a binary tree.
 *  ```
 *        4
 *      /   \
 *     2     7
 *    / \   / \
 *   1   3 6   9
 *  ```
 *  to
 *  ```
 *        4
 *      /   \
 *     7     2
 *    / \   / \
 *   9   6 3   1
 *  ```
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode *pNode = root;
        if (pNode->left != nullptr || pNode->right != nullptr) {
            TreeNode *tmp = pNode->left;
            pNode->left = invertTree(pNode->right);
            pNode->right = invertTree(tmp);
        }
        return pNode;
    }
};
