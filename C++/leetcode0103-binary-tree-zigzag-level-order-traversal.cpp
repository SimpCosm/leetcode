/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
 *
 * Description:
 *  Given a binary tree, return the *zigzag* level order traversal of its nodes' values. (ie. from left to right, then right to left for the next level and alternate between).
 */

#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;

        stack<int> s;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> level;
        bool leftToRight = true;
        while (!q.empty()) {
            TreeNode* pNode = q.front();
            q.pop();
            if (pNode == nullptr) {
                if (!leftToRight) {
                    while (!s.empty()) {
                        level.push_back(s.top());
                        s.pop();
                    }
                }
                ret.push_back(level);
                level.resize(0);
                leftToRight = (leftToRight == true) ? false : true;
                if (q.size() > 0)
                    q.push(nullptr);
            } else {
                if (leftToRight)
                    level.push_back(pNode->val);
                else
                    s.push(pNode->val);
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
