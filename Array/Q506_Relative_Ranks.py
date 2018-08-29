class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        rankings = sorted(range(len(nums)), key = lambda idx:nums[idx], reverse=True)
        if len(rankings) >= 1:
            nums[rankings[0]] = "Gold Medal"
        if len(rankings) >= 2:
            nums[rankings[1]] = "Silver Medal"
        if len(rankings) >= 3:
            nums[rankings[2]] = "Bronze Medal"
        for i in range(3, len(nums)):
            nums[rankings[i]] = str(i + 1)
        return nums