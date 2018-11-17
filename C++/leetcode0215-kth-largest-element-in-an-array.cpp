/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * Description:
 *  Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct elemnt.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k-1) return nums[pos];
            if (pos > k-1) right = pos - 1;
            else left = pos + 1;
        }
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
