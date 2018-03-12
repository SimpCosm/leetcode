/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/min-cost-climbing-stairs
 *
 * Description:
 *  On a staircase, the i th step has some non-negative cost cost[i] assigned (0 indexed).
 *  Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i)
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        return min(dp[n-2], dp[n-1]);
    }
};
