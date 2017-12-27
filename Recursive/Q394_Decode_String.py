import re

'''
the sub func in re module is quite useful to implement many complicated replacement. 
the second parameter can be a function which describes how to replace the matched pattern.
'''

class Solution(object):
    def decodeString(self, s):
        while '[' in s:
            s = re.sub(r'(\d+)\[([a-z]*)\]', lambda m: int(m.group(1)) * m.group(2), s)
            print s
        return s


s = Solution()
print s.decodeString('2[ac]3[b]')