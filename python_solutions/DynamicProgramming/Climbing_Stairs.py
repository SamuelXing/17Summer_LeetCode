class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        else:
            rst = [1]*(n+1)
            for i in range(1, n+1):
                rst[i] = rst[i-1] + rst[i-2] if i >=2 else rst[i-1]
        return rst[n]