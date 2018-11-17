/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/longest-common-prefix
 *
 * Description:
 *  Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0)
            return "";
        if (size == 1)
            return strs[0];
        string pre = prefixOfTwoStr(strs[0], strs[1]);
        for (int i = 2; i < size; i++) {
            pre = prefixOfTwoStr(pre, strs[i]);
        }
        return pre;
    }
private:
    string prefixOfTwoStr(string& s1, string& s2) {
        if (s1.empty() || s2.empty())
            return "";
        int i = 0, n1 = s1.size(), n2 = s2.size();
        int n = (n1 > n2) ? n2 : n1;
        for (i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                break;
        }
        return s1.substr(0, i);
    }
};
