class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 0:
            return 0
        
        dp = [0]*(n+1)
        dp[0] = 1
        
        for i in range(n):
            dp[i+1] = 0
            if s[i] != '0':
                dp[i+1] += dp[i]
            if i>=1 and s[i-1] != '0' and ((ord(s[i-1])-ord('0'))*10 + ord(s[i])-ord('0')) <= 26:
                dp[i+1] += dp[i-1]
                
        return dp[n]