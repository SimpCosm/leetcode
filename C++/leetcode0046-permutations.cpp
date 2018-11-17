/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/permutations
 *
 * Description:
 *  Given a collection of distinct numbers, return all possible permutations.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 0)
            return ret;

        vector<int> permution;
        findPermution(nums, permution, ret);
        return ret;
    }

    void findPermution(vector<int>& nums, vector<int>& permution, vector<vector<int>>& ret) {
        if (nums.size() == 0)
        {
            ret.push_back(permution);
            return ;
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            permution.push_back(num);
            nums.erase(nums.begin()+i);
            findPermution(nums, permution, ret);
            permution.pop_back();
            nums.insert(nums.begin()+i, num);
        }
    }
};
