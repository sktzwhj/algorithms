class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """

        res = [""]
        S = S.lower()
        for i in S:
            if not i in '1234567890':
                res = [c + i for c in res] + [c + i.upper() for c in res]
            else:
                res = [c + i for c in res]
        return res