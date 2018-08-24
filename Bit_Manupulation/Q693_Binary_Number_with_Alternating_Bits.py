class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        n_str = '{0:032b}'.format(n)
        first_one = n_str.find('1')
        first_one = 0 if first_one == -1 else first_one
        for i in range(first_one, len(n_str) - 1):
            if n_str[i] == n_str[i + 1]:
                return False
        return True
