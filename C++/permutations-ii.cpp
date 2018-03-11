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
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> permution;
        findPermution(nums, permution, ret);
        return vector<vector<int>> (ret.begin(), ret.end());
    }

    void findPermution(vector<int>& nums, vector<int>& permution, set<vector<int>>& ret) {
        if (nums.size() == 0)
        {
            ret.insert(permution);
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
