/*
 * Copyright (C) 2017 All Rights Reserved.
 *
 * Author:         Houmin Wei  <weihoumin@gmail.com>
 * Created:        Wed 27 Dec 2017 02:20:13 PM CST
 * Last Modified:  Wed 27 Dec 2017 02:38:25 PM CST
 *
 * Source: https://leetcode.com/problems/single-number-ii
 *
 * Description:
 *  Given an array of integers, every element appears three times except for one, which appears
 *  exactly once. Find that single one.
 *
 * Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using
 *  extra memory?
 *
 * Complexity:
 *  Time: _O(n)_
 *  Space: _O(1)_
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int one = 0, two = 0;

            for (const auto& i : nums) {
                int new_one = (~i & one) | (i & ~one & ~two);
                int new_two = (~i & two) | (i & one);
                one = new_one;
                two = new_two;
            }

            return one;
        }
};

int main()
{
   vector<int>  nums = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4};
   cout << "The single number is：" << Solution().singleNumber(nums) << endl;
   return 0;
}
