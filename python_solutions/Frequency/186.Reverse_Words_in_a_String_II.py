class Solution:
    def reverseWords(self, str):
        """
        :type str: List[str]
        :rtype: void Do not return anything, modify str in-place instead.
        """
        def reverse(i, j):
            while i < j:
                str[i], str[j] = str[j], str[i]
                i, j = i+1, j-1
            
        reverse(0, len(str)-1)
        
        start = 0
        for i in range(len(str)):
            if str[i] == ' ':
                reverse(start, i-1)
                start = i+1
        
        reverse(start, len(str)-1)
        