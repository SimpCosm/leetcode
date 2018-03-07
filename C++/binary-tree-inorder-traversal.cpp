/*
 * Copyright (C) 2018 All Rights Reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-inorder-traversal
 *
 * Description:
 *  Given a binary tree, return the inorder traversal of its nodes' values.
 *
 *  For example:
 *  Given binary tree [1, null, 2, 3],
 *  ```
 *      1
 *       \
 *        2
 *       /
 *      3
 *  ```
 *  return [1, 3, 2]
 *
 *  Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *pNode = root;
        vector<int> ret;
        if (pNode != nullptr) {
            vector<int> left = inorderTraversal(pNode->left);
            ret.insert(ret.end(), left.begin(), left.end());
            ret.push_back(pNode->val);
            vector<int> right = inorderTraversal(pNode->right);
            ret.insert(ret.end(), right.begin(), right.end());
        }
        return ret;
    }
};
