class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import defaultdict
        cnt_dic = defaultdict(int)
        for c in s:
            cnt_dic[c] += 1
        for i in range(len(s)):
            if cnt_dic[s[i]] == 1:
                return i
        return -1
