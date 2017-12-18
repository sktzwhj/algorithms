import numpy

class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        #if sigma(gas) > sigma(cost), there must be a solution.
        #https://discuss.leetcode.com/topic/39755/proof-of-if-total-gas-is-greater-than-total-cost-there-is-a-solution-c/2
        #the above proof makes sense
        if sum(numpy.array(gas)) < sum(numpy.array(cost)):
            return -1
        else:
            tank = 0
            total_cost = 0
            i = 0
            start = i
            while i < len(gas):
                if tank - total_cost < 0:
                    #if we cannot reach i, then any station k between 0 and i cannot be the start because they cannot reach
                    #station i either. otherwise, we can reach k and k can reach i. 
                    start = i+1
                    tank = 0
                    total_cost = 0
                else:
                    tank += gas[i]
                    total_cost += cost[i]
                i += 1
        return start



s = Solution()
print s.canCompleteCircuit([4],[5])