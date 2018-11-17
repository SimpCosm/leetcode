/*
 * Copyright (C) 2018 All Rights Reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 *
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

    TreeNode* helper(vector<int>& inorder, int i, int j, vector<int>& postorder, int ii, int jj) {
        if (i >= j || ii >= jj)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[jj-1]);
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), root->val);
        int dis = iter - inorder.begin() - i;

        root->left = helper(inorder, i, i+dis, postorder, ii, ii+dis);
        root->right = helper(inorder, i+dis+1, j, postorder, ii+dis, jj-1);
        return root;
    }
};
