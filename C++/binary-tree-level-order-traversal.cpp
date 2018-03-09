/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-level-order-traversal
 *
 * Description:
 *  Given a binary tree, return the level order traversal of its nodes' values. (ie. from left to right, level by level).
 */

#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> level;
        while (!q.empty()) {
            TreeNode* pNode = q.front();
            q.pop();
            if (pNode == nullptr) {
                ret.push_back(level);
                level.resize(0);
                if (q.size() > 0)
                    q.push(nullptr);
            } else {
                level.push_back(pNode->val);
                if (pNode->left != nullptr) {
                    q.push(pNode->left);
                }
                if (pNode->right != nullptr) {
                    q.push(pNode->right);
                }
            }
        }
        return ret;
    }
};
