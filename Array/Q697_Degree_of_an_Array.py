class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        import sys
        pos = defaultdict(list)
        for idx in range(len(nums)):
            pos[nums[idx]].append(idx)
        global_deg = max([len(v) for v in pos.values()])
        if global_deg == 1:
            return 1
        min_len = sys.maxsize
        for k, v in pos.items():
            if len(v) == global_deg:
                requried_len =  v[-1] - v[0] + 1
                if requried_len < min_len:
                    min_len = requried_len
        return min_len