/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/maximum-length-of-repeated-subarray
 *
 */
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    f[i][j] = 0;
                } else if (A[i-1] == B[j-1]) {
                    f[i][j] = f[i-1][j-1] + 1;
                    ans = max(f[i][j], ans);
                }
            }
        }
        return ans;
    }
};
