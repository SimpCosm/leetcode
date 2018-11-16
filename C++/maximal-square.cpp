/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/maximal-square
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m <= 0)
            return 0;
        int n = matrix[0].size();
        int maxSize = min(m, n);
        if (maxSize <= 0) return 0;
        bool flag = false;
        int size = 0;
        vector<vector<bool>> f(m, vector<bool>(n, false));
        for (int s = 1; s <= maxSize; s++) {
            for (int i = 0; i <= m-s; i++) {
                for (int j = 0; j <= n-s; j++) {
                    if (s == 1) {
                        f[i][j] = matrix[i][j] == '1';
                    } else {
                        f[i][j] = f[i][j] && f[i][j+1] && f[i+1][j] && f[i+1][j+1];
                    }
                    if (f[i][j]) flag = true;
                }
            }
            if (flag) {
                flag = false;
                size = s;
            } else {
                break;
            }
        }
        return size * size;
    }
};

class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            sz = max(sz, dp[0][j]);
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            sz = max(sz, dp[i][0]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    sz = max(sz, dp[i][j]);
                }
            }
        }
        return sz * sz;
    }
};
