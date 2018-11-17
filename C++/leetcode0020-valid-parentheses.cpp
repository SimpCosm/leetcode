/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/longest-valid-parentheses
 */
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>  m{{')','('}, {']','['}, {'}','{'}};
        stack<char> par_stack;
        for (auto c:s){
            if (m.find(c)!=m.end()){
                if (par_stack.empty() || par_stack.top() != m[c]) {return false;}
                else{
                   par_stack.pop();
                }
            }
            else{
                par_stack.push(c);
                }
            }
        return par_stack.empty();
    }
};
