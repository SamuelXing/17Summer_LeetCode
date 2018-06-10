class Solution:
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """     
        if len(M) == 0 or len(M[0]) == 0: return 0
        
        m, n, res = len(M), len(M[0]), 0
        dp = [[[0 for z in range(4)] for y in range(n)] for x in range(m)]
        
        for i in range(m):
            for j in range(n):
                if M[i][j] == 1:
                    # horizontal
                    dp[i][j][0] = dp[i][j-1][0] + 1 if j else 1
                    res = max(res, dp[i][j][0])
                    # vertical
                    dp[i][j][1] = dp[i-1][j][1] + 1 if i else 1
                    res = max(res,dp[i][j][1])
                    # diagonal
                    dp[i][j][2] = dp[i-1][j-1][2] + 1 if (i and j) else 1
                    res = max(res,dp[i][j][2])
                    # anti-diagonal
                    dp[i][j][3] = dp[i-1][j+1][3] +1 if (i and j < n-1) else 1
                    res = max(res,dp[i][j][3])
        return res