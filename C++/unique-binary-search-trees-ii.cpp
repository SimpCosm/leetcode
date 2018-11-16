/*
 * Copyright (C) 2018 all reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/unique-binary-search-trees-ii
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if (n <= 0) return return ret;

        return genBST(1, n);
    }

    vector<TreeNode*> genBST(int min, int max) {
        vector<TreeNode*> ret;
        if (min > max) {
            ret.push_back(nullptr);
            return ret;
        }

        for (int i = min; i <= max; i++) {
            vector<TreeNode*> left = genBST(min, i-1);
            vector<TreeNode*> right = genBST(i+1, max);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
