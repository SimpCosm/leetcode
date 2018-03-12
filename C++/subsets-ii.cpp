/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/subsets-ii
 *
 * Description:
 *  Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, subset, ret);
        return ret;
    }

    void findSubsets(vector<int>& nums, int begin, vector<int>& subset, vector<vector<int>>& ret) {
        ret.push_back(subset);
        for (int i = begin; i < nums.size(); i++) {
            if (i > begin && nums[i] == nums[i-1])  // skip duplicates
                continue;
            subset.push_back(nums[i]);
            findSubsets(nums, i+1, subset, ret);
            subset.pop_back();
        }
    }
};
