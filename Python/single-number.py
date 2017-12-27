#!/bin/env python3
#-*- coding: utf-8 -*-
#
# Copyright (C) 2017 All Rights Reserved.
# Author:          Houmin Wei  <weihoumin@gmail.com>
# Created:         Wed 27 Dec 2017 02:01:09 PM CST
# Last Modified:   Wed 27 Dec 2017 02:07:54 PM CST
#
# Source: https://leetcode.com/problems/single-number
#
# Description:
#   Given an array of intergers, every element appears twice except for on. Find that single one.
# Note:
#   Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#
# Complexity:
#   Time: O(n)
#   Space: O(1)

import operator

class Solution:
    """
    :type nums: List[int]
    :return: int
    """
    def singleNumber(self, nums):
        a = 0
        for i in nums:
            a ^= i
        return a

if __name__ == '__main__':
    print(Solution().singleNumber([1, 1, 2, 2, 3]))
