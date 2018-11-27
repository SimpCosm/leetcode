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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;

        vector<int> h(m, 0);
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == '1')
                h[i] = 1;
        }
        int result = largestInLine(h);

        for (int i = 1; i < n; i++) {
            resetHeight(matrix, h, i, m);
            result = max(result, largestInLine(h));
        }
        return result;
    }

    void resetHeight(vector<vector<char>>& matrix, vector<int>& h, int idx, int m) {
        for (int i = 0; i < m; i++) {
            if (matrix[idx][i] == '1') h[i] += 1;
            else h[i] = 0;
        }
    }

    int largestInLine(vector<int>& h) {
        int n = h.size();
        vector<int> l(n, 0), r(n, 0);

        l[0] = -1;
        for (int i = 1; i < n; i++) {
            int p = i-1;
            while (p >= 0 && h[p] >= h[i])
                p = l[p];
            l[i] = p;
        }

        r[n-1] = n;
        for (int i = n-2; i >= 0; i--) {
            int p = i+1;
            while (p < n && h[p] >= h[i])
                p = r[p];
            r[i] = p;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, h[i]*(r[i]-l[i]-1));
        }
        return maxArea;
    }
};
