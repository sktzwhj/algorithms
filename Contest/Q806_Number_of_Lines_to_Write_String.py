class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        line_cnt = 1
        line_offset = 0
        for c in S:
            last_offset = widths[ord(c) - ord('a')]
            line_offset += last_offset
            if line_offset > 100:
                line_cnt += 1
                line_offset = last_offset
        return [line_cnt, line_offset]

if __name__ == "__main__":
    s = Solution()
    widths = [4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
    S = "bbbcccdddaaa"
    print s.numberOfLines(widths, S)