/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/implement-strstr
 *
 * Description:
 *  Implement strStr().
 *  Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found != string::npos)
            return found;
        else
            return -1;
    }
};
