class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        x = '{0:032b}'.format(x)
        y = '{0:032b}'.format(y)
        dist = 0
        for i in range(len(x)):
            if x[i] != y[i]:
                dist += 1
        return dist