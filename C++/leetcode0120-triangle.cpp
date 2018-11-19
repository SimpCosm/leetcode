/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 */

#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n+1, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
            }
        }
        return f[0];
    }
};
