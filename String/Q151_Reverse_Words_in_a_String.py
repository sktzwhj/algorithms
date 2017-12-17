class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        splitted_s = s.split()
        if len(splitted_s) == 0:
            return ''
        return ' '.join(splitted_s[::-1])



if __name__ == "__main__":
    s = Solution()
    print s.reverseWords(' ')