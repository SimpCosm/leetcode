/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@pku.edu.cn>
 *
 * Source: https://leetcode.com/container-with-most-water
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int ret = 0;
        while (left < right) {
            ret = max(ret, (right-left)*min(height[right], height[left]));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ret;
    }
};
