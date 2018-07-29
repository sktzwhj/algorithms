import sys


def gca(a, b):
    if b == 0:
        return a
    return gca(b, a % b)

def lcm(a, b):
    return (a/gca(a, b))* b

class Solution(object):
    def nthMagicalNumber(self, N, A, B):
        """
        :type N: int
        :type A: int
        :type B: int
        :rtype: int
        """
        MOD = 10**9 + 7
        if N == 1:
            return min(A, B)
        if N == 2:
            return max(A, B)
        magic_max = max(A, B)*(N + 1)
        #magic_max = 10**14
        magic_min = 2
        start = magic_min
        end = magic_max
        mid = 0
        lcm_val = lcm(A, B)
        curr_index = 0
        while start < end:
            mid = (start + end) / 2
            if mid / A + mid / B - mid / lcm_val < N:
                start = mid + 1
            else:
                end = mid
        return start % MOD


if __name__ == "__main__":
    s = Solution()
    print s.nthMagicalNumber(5, 2, 4)
