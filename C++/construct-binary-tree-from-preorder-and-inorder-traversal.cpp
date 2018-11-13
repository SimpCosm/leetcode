/*
 * Copyright (C) 2018 All Rights Reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* helper(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        if (i >= j || ii >= jj)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);

        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), root->val);
        int dis = iter - inorder.begin() - ii;

        root->left = helper(preorder, i+1, i+1+dis, inorder, ii, ii+dis);
        root->right = helper(preorder, i+1+dis, j, inorder, ii+dis+1, jj);
        return root;
    }
};

