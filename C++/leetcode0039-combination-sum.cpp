/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/combination-sum
 *
 * Description:
 *  Given a set of candidate numbers(C)(without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 *  The Same repeated number may be chosen from C unlimited number of times.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        findSum(candidates, target, path, ret, 0);
        return ret;
    }

    void findSum(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& ret, int begin) {
        if (target == 0) {
            ret.push_back(path);
            return ;
        }

        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            path.push_back(candidates[i]);
            findSum(candidates, target-candidates[i], path, ret, i);
            path.pop_back();
        }
    }
};
