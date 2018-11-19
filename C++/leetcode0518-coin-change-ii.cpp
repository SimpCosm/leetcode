/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/coin-change-ii
 */

#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++)
                dp[j] = dp[j] + dp[j-coin];
        }
        return dp[amount];
    }
};
