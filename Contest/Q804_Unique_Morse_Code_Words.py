

class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        moorse_dict = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                       "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]

        coded_set = set()
        for word in words:
            coded_word = ''
            for c in word:
                coded_word += moorse_dict[ord(c) - ord('a')]
            coded_set.add(coded_word)
        return len(coded_set)