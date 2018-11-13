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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumup(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int sumup(TreeNode *root, int sum) {
        int res = 0;
        if (sum == root->val) ++res;
        if (root->left) res += sumup(root->left, sum - root->val);
        if (root->right) res += sumup(root->right, sum - root->val);
        return res;
    }
};
