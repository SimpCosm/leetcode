/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/path-sum-ii
 */
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        findPaths(root, sum, path, ret);
        return ret;
    }
private:
    void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ret) {
        if (root == nullptr)
            return ;
        path.push_back(root->val);
        if ((root->left == nullptr) && (root->right == nullptr) && (root->val == sum))
            ret.push_back(path);
        findPaths(root->left, sum-root->val, path, ret);
        findPaths(root->right, sum-root->val, path, ret);
        path.pop_back();
    }
};
