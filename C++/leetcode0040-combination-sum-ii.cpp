/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/combination-sum-ii
 *
 * Description:
 *  Given a set of candidate numbers(C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 *  Each number in C may only be used once in the combination.
 */

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ret;
        vector<int> path;
        findSum(candidates, target, path, ret, 0);
        return vector<vector<int>> (ret.begin(), ret.end());
    }

    void findSum(vector<int>& candidates, int target, vector<int>& path, set<vector<int>>& ret, int begin) {
        if (target == 0) {
            ret.insert(path);
            return ;
        }

        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            path.push_back(candidates[i]);
            findSum(candidates, target-candidates[i], path, ret, i+1);
            path.pop_back();
        }
    }
};
