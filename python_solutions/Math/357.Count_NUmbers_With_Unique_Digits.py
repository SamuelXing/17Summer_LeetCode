class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n == 0:
            return 1
        
        ans, base = 10, 9
        for i in range(2, min(n, 10)+1):
            base *= (9 - i + 2)
            ans += base
        
        return ans
        
  