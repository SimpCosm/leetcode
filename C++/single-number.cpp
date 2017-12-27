/*
 * Copyright (C) 2017 All Rights Reserved.
 *
 * Author:         Houmin Wei  <weihoumin@gmail.com>
 * Created:        Wed 27 Dec 2017 02:10:22 PM CST
 * Last Modified:  Wed 27 Dec 2017 02:13:59 PM CST
 *
 * Source: https://leetcode.com/problems/single-number
 *
 * Description:
 *  Given an array of intergers, every element appears *twice* except for one. Find that one.
 * Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using
 *  extra memory?
 *
 * Solution:
 *  This is a classic interview question. As we know, a XOR a = 0 and the XOR operator is commutative.
 *  So, XOR all of numbers, the result is the number which only appears once.
 *
 * Complexity:
 *  Time: O(n)
 *  Space: O(1)
 */

#include <iostream>
#include <numeric>
#include <vector>

class Solution {
    public:
        int singleNumber(std::vector<int>& nums) {
            return accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        }
};

int main()
{
    std::vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    std::cout << "The single number is: " << Solution().singleNumber(nums) << std::endl;
    return 0;
}
