class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur_cnt = 0
        max_cnt = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                cur_cnt += 1
            if i == len(nums) - 1 or nums[i] == 0:
                if cur_cnt > max_cnt:
                    max_cnt = cur_cnt
                cur_cnt = 0
        return max_cnt