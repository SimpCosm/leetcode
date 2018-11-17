/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/average-of-levels-in-binary-tree
 *
 * Description:
 *  Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if (root == nullptr)
            return ret;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int cnt = 0;
        double sum = 0;
        while (!q.empty()) {
            TreeNode* pNode = q.front();
            q.pop();
            if (pNode == nullptr) {
                ret.push_back(sum / cnt);
                sum = 0;
                cnt = 0;
                if (q.size() > 0)
                    q.push(nullptr);
            } else {
                cnt ++;
                sum += (double)pNode->val;
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
