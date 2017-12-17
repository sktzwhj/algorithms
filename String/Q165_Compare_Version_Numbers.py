class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        version1_split = version1.split('.')
        version2_split = version2.split('.')
        min_len = min(len(version1_split), len(version2_split))
        for i in range(min_len):
            if int(version1_split[i]) > int(version2_split[i]):
                return 1
            elif int(version1_split[i]) < int(version2_split[i]):
                return -1
        if len(version1_split) > len(version2_split):
            for i in range(min_len, len(version1_split)):
                if int(version1_split[i]) != 0:
                    return 1
            return 0
        elif len(version1_split) < len(version2_split):
            for i in range(min_len, len(version2_split)):
                if int(version2_split[i]) != 0:
                    return -1
            return 0
        else:
            return 0


s = Solution()
print s.compareVersion('1', '1.1')
