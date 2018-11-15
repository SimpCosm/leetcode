/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/longest-palindromic-subsequence
 *
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();

        vector<vector<int>> f(len, vector<int>(len, 0));
        for (int i = len-1; i >= 0; i--) {
            f[i][i] = 1;
            for (int j = i+1; j < len; j++) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1] + 2;
                } else {
                    f[i][j] = max(f[i+1][j], f[i][j-1]);
                }
            }
        }
        return f[0][len-1];
    }
};
