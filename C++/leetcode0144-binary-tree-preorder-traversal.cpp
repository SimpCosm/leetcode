/*
 * Copyright (C) 2018 All Rights Reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-preorder-traversal
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
 *  return [1, 2, 3]
 *
 *  Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *pNode = root;
        vector<int> ret;
        if (pNode != nullptr) {
            ret.push_back(pNode->val);
            vector<int> left = preorderTraversal(pNode->left);
            ret.insert(ret.end(), left.begin(), left.end());
            vector<int> right = preorderTraversal(pNode->right);
            ret.insert(ret.end(), right.begin(), right.end());
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        TreeNode *pNode = root;
        while (pNode != nullptr || !s.empty()) {
            while (pNode != nullptr) {
                ret.push_back(pNode->val);
                s.push(pNode);
                pNode = pNode->left;
            }
            if (!s.empty()) {
                pNode = s.top();
                s.pop();
                pNode = pNode->right;
            }
        }
        return ret;
    }
};
