/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/basic-calculator
 *
 */

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string expression) {
        stack<int> s;
        int result = 0;
        int number = 0;
        int sign = 1;
        for (char c : expression) {
            if (isdigit(c)) {
                number = number * 10 + c - '0';
            } else if (c == '+') {
                result += number * sign;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                result += number * sign;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                s.push(result);
                s.push(sign);
                sign = 1;
                result = 0;
            } else if (c == ')') {
                result += sign * number;
                number = 0;
                result *= s.top(); s.pop();
                result += s.top(); s.pop();
            }
        }
        if (number != 0) result += sign * number;
        return result;
    }
};
