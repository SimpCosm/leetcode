/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/longest-valid-parentheses
 */
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> stack;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') stack.push(i);
            else {
                if (!stack.empty()) {
                    if (s[stack.top()] == '(') stack.pop();
                    else stack.push(i);
                }
                else stack.push(i);
            }
        }
        if (stack.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!stack.empty()) {
                b = stack.top();
                stack.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
