class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        
        dictionary = [0]*26
        
        for i, s in enumerate(S):
            dictionary[ord(s) - ord('a')] = i
        
        start, end, ret = 0, 0, []
        for i, s in enumerate(S):
            end = max(end, dictionary[ord(s) - ord('a')])
            if i == end:
                ret.append(end-start+1)
                start = end + 1
        
        return ret