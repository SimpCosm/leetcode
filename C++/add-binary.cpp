/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/add-binary
 *
 * Description:
 *  Given two binary string, return their sum (also a binary string).
 */

#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        int i = a.size() - 1, j = b.size() - 1;
        int s = 0;
        while (i >= 0 || j >= 0 || s == 1) {
            s += i >= 0 ? a[i--]-'0' : 0;
            s += j >= 0 ? b[j--]-'0' : 0;
            c = char(s % 2 + '0') + c;
            s /= 2;
        }
        return c;
    }
};
