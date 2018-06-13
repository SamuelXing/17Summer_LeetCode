class Solution:
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        d.sort(key = lambda x: (-len(x), x))
        for w in d:
            i = 0
            # check matches in s 
            for c in s:
                if i < len(w) and c == w[i]:
                    i += 1
            if i == len(w):
                return w
        return ""