class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        res = []
        words = (A + ' ' + B).split()
        for word in words:
            if words.count(word) == 1:
                res.append(word)
        return res
            
        
                
        