import sys
import numpy
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #use dp_min[i] and dp_max[i] to store the maximum/minimal product for the subarries which end with nums[i], respectively.
        #the minimal product is necessary because you may get the max product by multiplying two negative numbers
        num_len = len(nums)
        local_max = nums[0]
        local_min = nums[0]
        max_product = nums[0]
        for i in range(1,num_len):
            local_min, local_max = min(local_min*nums[i], nums[i],local_max*nums[i]),\
                                   max(local_min*nums[i], nums[i], local_max*nums[i])
            if local_max > max_product:
                max_product = local_max
        return max_product


s = Solution()
print s.maxProduct([-4,-3])