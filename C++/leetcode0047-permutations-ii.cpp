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
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
private:
    void permute(vector<int> nums, int start, vector<vector<int>>& perms) {
        int n = nums.size();
        if (start == n - 1) {
            perms.push_back(nums);
        } else {
            for (int i = start; i < n; i++) {
                if ((i == start) || (nums[i] != nums[start])) {
                    swap(nums[i], nums[start]);
                    permute(nums, start + 1, perms);
                }
            }
        }
    }
};
