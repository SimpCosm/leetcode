/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/top-k-frequent-words
 *
 * Description:
 *  Given a non-empty list of words, return the k most frequent elements.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ret;
        unordered_map<string, int> m;
        auto cmp = [] (pair<string, int>& a, pair<string, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue< pair<string, int>, vector<pair<string, int>>, decltype(cmp)> heap(cmp);
        for (auto word : words) m[word]++;
        for (auto it : m) heap.push(it);
        for (int i = 0; i < k; i++) {
            ret.push_back(heap.top().first);
            heap.pop();
        }
        return ret;
    }
};
