/*
 * Copyright (C) 2017 All Rights Reserved.
 *
 * Author:         Houmin Wei  <weihoumin@gmail.com>
 * Created:        Wed 27 Dec 2017 02:44:10 PM CST
 * Last Modified:  Wed 27 Dec 2017 03:03:47 PM CST
 *
 * Source: https://leetcode.com/problems/single-number-iii
 *
 * Description:
 *  Given an array of numbers `nums`, in which exactly two elements appear only once and all the
 *  other elements appear exactly twice.
 *
 *  For Example:
 *      Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]
 *
 * Note:
 *  1. The order of the result is not important. So in the above example, [5, 3] is also correct.
 *  2. Your algorithm should run in linear runtime complexity. Could you implement it using constant
 *     space complexity?
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            // XOR all the elements to get x ^ y.
            const auto x_xor_y = accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());

            // Get the last bit where 1 occurs by "x & ~(x - 1)"
            // Because -(x - 1) = ~(x - 1) + 1  <=>  -x = ~(x - 1)
            // So we can also get the last bit where 1 occurs by "x & -x"
            const auto bit = x_xor_y & -x_xor_y;

            // Get the subset of nums where the number has the bit.
            // The subset only contains one of the two integers, call it x.
            // XOR all the elements in the subset to get x.
            vector<int> result(2, 0);
            for (const auto& i : nums) {
                result[static_cast<bool>(i & bit)] ^= i;
            }
            return result;
        }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = Solution().singleNumber(nums);
    cout << "The single numbers are: " << result[0] << " and " << result[1] << endl;
    return 0;
}
