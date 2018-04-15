class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1,1,2]
        if n <= 2:
            return dp[n]
        else:
            dp += [0 for i in range(n-2)]
            for i in range(3, n+1):
                for j in range(1, i+1):
                    dp [i] += dp[i-j]*dp[j-1]
            return dp[n]