import copy

class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        #should use backtrack
        alex_sum = 0
        total_sum = sum(piles)
        return self._helper(piles, alex_sum, total_sum)

    def _helper(self, remain_piles, alex_sum, total_sum):
        if alex_sum > 0.5 * total_sum:
            return True
        if len(remain_piles) == 0:
            return alex_sum > 0.5 * total_sum
        for i in range(len(remain_piles)):
            remain_piles_copy = copy.copy(remain_piles)
            del remain_piles_copy[i]
            if self._helper(remain_piles_copy, alex_sum + remain_piles[i], total_sum):
                return True
        return False

if __name__ == "__main__":
    s = Solution()
    piles = [5, 3, 4, 5]
    print s.stoneGame(piles)