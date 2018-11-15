/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/longest-palindromic-substring
 *
 */
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 1)
            return s;

        int maxLen = 0;
        string longest;
        vector<vector<bool>> d(len, vector<bool>(len, false));

        for (int l = 0; l < len; l++) {
            for (int i = 0; i < len-l; i++) {
                int j = i + l;
                if (s[i] == s[j] && (j-i<=2 || d[i+1][j-1])) {
                    d[i][j] = true;

                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        longest = s.substr(i, maxLen);
                    }
                }
            }
        }
        return longest;
    }
};
