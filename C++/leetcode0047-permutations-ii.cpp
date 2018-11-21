/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/permutations-ii
 *
 * Description:
 *  Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ret;
        dfs(nums, 0, ret);
        return vector<vector<int>>(ret.begin(), ret.end());
    }

    void dfs(vector<int>& nums, int begin, set<vector<int>>& ret) {
        if (begin == nums.size()) { ret.insert(nums); return; }
        for (int i = begin; i < nums.size(); i++) {
            if (i == begin || nums[i] != nums[begin]) {
                swap(nums[begin], nums[i]);
                dfs(nums, begin+1, ret);
                swap(nums[begin], nums[i]);
            }
        }
    }
};
