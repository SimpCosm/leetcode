/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/word-break
 *
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> f(len+1, false);
        f[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};
