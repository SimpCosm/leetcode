/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/top-k-frequent-elements
 *
 * Description:
 *  Given a non-empty array of integers, return the k most frequent elements.
 */

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> heap;
        vector<int> res;
        for (auto a : nums)
            ++m[a];
        for (auto it : m)
            heap.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
