class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        # need[i][j] represent the lowest money you need to pay when it gurantees to win in range(i, j)
        need = [[0]*(n+1) for _ in range(n+1)]
        for lo in range(n, 0, -1):
            for hi in range(lo+1, n+1):
                # the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
                need[lo][hi] = min(x+max(need[lo][x-1], need[x+1][hi]) for x in range(lo,hi))
        
        return need[1][n]

    # recursion + memorization
    def getMoneyAmount(self, n):
        self.dp = [[sys.maxsize]*(n+1) for _ in range(n+1)]
        return self.solve(1, n)
    
    def solve(self, lo, hi):
        if lo >= hi: return 0
        if self.dp[lo][hi] != sys.maxsize: return self.dp[lo][hi]
        for i in range(lo, hi+1):
            self.dp[lo][hi] = min(i + max(self.solve(lo, i-1), self.solve(i+1, hi)), self.dp[lo][hi])
        return self.dp[lo][hi]
                