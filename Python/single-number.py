# Time: O(n)
# Space: O(1)

# Given an array of intergers, every element appears twice except for on. Find that single one.
# Note:
#   Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#

import operator

class Solution:
    """
    :type nums: List[int]
    :return: int
    """
    def singleNumber(self, nums):
        return reduce(operator.xor, nums)

if __name__ == '__main__':
    print(Solution().singleNumber([1, 1, 2, 2, 3]))

