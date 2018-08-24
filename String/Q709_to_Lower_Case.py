class Solution(object):
    def toLowerCase(self, str):
        """
        :type str: str
        :rtype: str
        """
        str_res = ''
        for i in range(len(str)):
            if ord(str[i]) <= ord('Z') and ord(str[i]) >= ord('A'):
                str_res += chr(ord(str[i]) - (ord('A') - ord('a')))
            else:
                str_res += str[i]
        return str_res
        