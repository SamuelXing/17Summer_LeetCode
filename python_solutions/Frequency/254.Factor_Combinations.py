import math
class Solution(object):
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n <= 1: return []
        ans = []
        self.factor(n, [], ans)
        return ans
    
    def factor(self, num, temp, ans):
        if temp:
            ans.append(temp + [num])
        
        start = temp[-1] if temp else 2
        for i in range(start, int(round(math.sqrt(num)))+1):
            if num % i == 0:
                self.factor(num//i, temp+[i], ans)