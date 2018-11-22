/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/palindrome-partitioning
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ret;
        dfs(s, 0, path, ret);
        return ret;
    }

    void dfs(string& s, int begin, vector<string>& path, vector<vector<string>>& ret) {
        int n = s.length();
        if (begin == n) {
            ret.push_back(path);
            return;
        }

        for (int i = begin; i < n; i++) {
            string key = s.substr(begin, i-begin+1);
            if (isValid(key)) {
                path.push_back(key);
                dfs(s, i+1, path, ret);
                path.pop_back();
            }
        }
    }

    bool isValid(string& s) {
        int n = s.length();
        for (int i = 0, j = n-1; i <= j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
