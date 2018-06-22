class Solution:
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return self.helper(n, n)
    
    def helper(self, n, m):
        if n == 0: 
            return ['']
        if n == 1:
            return ['0', '1', '8']
        
        prevList  = self.helper(n-2, m)
        
        res = []
        for s in prevList:
            if n != m:
                res += ['0' + s +'0']
            
            res += ['1' + s +'1']
            res += ['6' + s +'9']
            res += ['8' + s +'8']
            res += ['9' + s +'6']
            
        return res