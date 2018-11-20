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
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;

	    backtrack(num, 0, result);
	    return result;
    }

	void backtrack(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}

		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    backtrack(num, begin + 1, result);
            swap(num[begin], num[i]);
		}
    }
};
