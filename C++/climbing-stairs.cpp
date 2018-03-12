/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/climbing-stairs
 *
 * Description:
 *  You are climbing a stair case. It takes n steps to reach to the top. Each time you can either 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
            return 0;

        vector<int> s(n+1);

        s[0] = s[1] = 1;

        for (int i = 2; i <= n; i++) {
            s[i] = s[i-1] + s[i-2];
        }

        return s[n];
    }
};
