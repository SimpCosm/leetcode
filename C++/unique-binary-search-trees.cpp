/*
 * Copyright (C) 2018 all reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/unique-binary-search-trees
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
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        for (int i=2; i<=n; i++) {
            dp[i] = 0;
            for (int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
