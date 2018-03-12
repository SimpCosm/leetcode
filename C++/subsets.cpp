/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/subsets
 *
 * Description:
 *  Given a set of distinct integers, nums, return all possible subsets(the power set).
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, subset, ret);
        return ret;
    }

    void findSubsets(vector<int>& nums, int begin, vector<int>& subset, vector<vector<int>>& ret) {
        ret.push_back(subset);
        for (int i = begin; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            findSubsets(nums, i+1, subset, ret);
            subset.pop_back();
        }
    }
};
