class Solution:
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        maxLen = 0
        pathLen = {0: 0}
        
        for line in input.splitlines():
            text = line.lstrip('\t')
            depth = len(line) - len(text)
            
            if '.' in text:
                maxLen = max(maxLen, pathLen[depth] + len(text))
            else:
                pathLen[depth+1] = pathLen[depth] + len(text) + 1
                
        return maxLen