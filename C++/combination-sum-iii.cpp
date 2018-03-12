/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/combination-sum-iii
 *
 * Description:
 *  Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationsSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        findSum(k, n, path, ret, 1);
        return ret;
    }

    void findSum(int k, int n, vector<int>& path, vector<vector<int>>& ret, int begin) {
        if (k < 0 || n < 0)
            return ;
        if (k == 0 && n == 0) {
            ret.push_back(path);
            return ;
        }

        for (int i = begin; i < 10; i++) {
            path.push_back(i);
            findSum(k-1, n-i, path, ret, i+1);
            path.pop_back();
        }
    }
};
