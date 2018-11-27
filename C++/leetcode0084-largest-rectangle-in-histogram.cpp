/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/symmetric-tree
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n < 1) return 0;
        vector<int> l(n, 0), r(n, 0);

        l[0] = -1;
        for (int i = 1; i < n; i++) {
            int p = i-1;
            while (p >= 0 && heights[p] >= heights[i])
                p = l[p];
            l[i] = p;
        }

        r[n-1] = n;
        for (int i = n-2; i >= 0; i--) {
            int p = i+1;
            while (p < n && heights[p] >= heights[i])
                p = r[p];
            r[i] = p;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i]*(r[i]-l[i]-1));
        }
        return maxArea;
    }
};

