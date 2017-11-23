class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        curr_max = 0
        i = 0
        j = 1
        while i < len(s):
            while j < len(s):
                print 's[j]:%s, s[i:j]:%s'%(s[j],s[i:j])
                if s[j] in s[i:j]:

                    break
                j += 1
            if j - i  > curr_max:
                curr_max = j - i

            i+= 1

        return curr_max

s = "abcabcaa"


solution = Solution()
print solution.lengthOfLongestSubstring(s)