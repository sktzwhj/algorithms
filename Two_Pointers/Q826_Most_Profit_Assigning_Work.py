class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        diff_profit_pairs = zip(difficulty, profit)
        diff_profit_pairs = sorted(diff_profit_pairs, key=lambda a:a[1], reverse=True)
        worker = sorted(worker, reverse=True)
        i = 0
        j = 0
        total_profit = 0
        while i < len(worker):
            if worker[i] >= diff_profit_pairs[j][0]:
                total_profit += diff_profit_pairs[j][1]
                i += 1
            else:
                if j < len(profit) - 1:
                    j += 1
                else:
                    break
        return total_profit

s = Solution()
difficulty = [85,47,57]
profit = [24,66,99]
worker = [40,25,25]
print s.maxProfitAssignment(difficulty, profit, worker)