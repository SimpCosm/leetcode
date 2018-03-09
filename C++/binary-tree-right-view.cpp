/*
 * Copyright (C) 2018 all right reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-right-side-view
 *
 * Description:
 *  Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr)
            return ret;

        TreeNode* pNode;
        stack<int> s;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            pNode = q.front();
            q.pop();
            if (pNode == nullptr) {
                ret.push_back(s.top());
                while (!s.empty())
                    s.pop();
                if (!q.empty())
                    q.push(nullptr);

            } else {
                s.push(pNode->val);
                if (pNode->left) q.push(pNode->left);
                if (pNode->right) q.push(pNode->right);
            }
        }
        return ret;
    }
};
