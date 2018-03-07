/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-tilt
 *
 * Description:
 *  Given a binary tree, return the tilt of the whole tree.
 *  The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
 *  The tilt of the whole tree is defined as the sum of all node's tilt.
 *
 */
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        int res = 0;
        postOrder(root, res);
        return res;
    }

private:
    int postOrder(TreeNode* root, int& res)
    {
        if (root == nullptr)
            return 0;

        int leftSum = postOrder(root->left, res);
        int rightSum = postOrder(root->right, res);
        res += abs(leftSum - rightSum);

        return leftSum + rightSum + root->val;
    }
};
