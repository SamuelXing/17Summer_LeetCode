class Solution:
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        if A is None or B is None:
            return 0
        m, n = len(A), len(B)
        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        maxLen = 0
        for i in range(m+1):
            for j in range(n+1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                else:
                    if A[i-1] == B[j-1]:
                        dp[i][j] = 1 + dp[i-1][j-1]
                        maxLen = max(maxLen, dp[i][j])

        return maxLen