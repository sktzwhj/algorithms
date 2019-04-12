from collections import defaultdict
import numpy as np


class Solution(object):
    def minDominoRotations(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """

        if len(A) != len(B):
            return -1

        current_set = set([A[0], B[0]])
        for i in range(1, len(A)):
            try:

                for val in current_set:
                    if val != A[i] and val != B[i]:
                        current_set.remove(val)
                    if len(current_set) == 0:
                        return -1
            except:
                continue

        step = len(A)
        for val in current_set:
            step = min(step, min(len(A) - A.count(val), len(A) - B.count(val)))
        return step
