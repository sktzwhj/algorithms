from collections import defaultdict

class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        s_char_dic = defaultdict(0)
        t_char_dic = defaultdict(0)
        for c in s:
            s_char_dic[c] += 1
        for c in t:
            t_char_dic[c] += 1
        for k in t_char_dic.keys():
            if not s_char_dic.has_key(k) or t_char_dic[k] - s_char_dic[k] > 0:
                return k

