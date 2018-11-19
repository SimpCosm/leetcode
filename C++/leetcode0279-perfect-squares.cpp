/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/perfect-squares
 */

#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for (int i = 1; i*i <= n; i++) {
            for (int j = i*i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};
