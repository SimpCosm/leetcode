/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/trapping-rain-water
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        vector<int> maxLeft(n, 0), maxRight(n, 0), delta(n, 0);


        int sum = 0;
        int max = height[0];
        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max;
            if (max < height[i])
                max = height[i];
        }

        max = height[n-1];
        maxRight[n-1] = 0;

        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = max;
            if (max < height[i])
                max = height[i];

            delta[i] = min(maxLeft[i], maxRight[i]) - height[i];
            if (delta[i] > 0)
                sum += delta[i];
        }

        return sum;
    }
};
