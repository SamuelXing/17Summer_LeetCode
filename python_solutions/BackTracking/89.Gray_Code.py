class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = [0]
        for i in range(n):
            result += [x + pow(2, i) for x in reversed(result)]
        
        return result