class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # initialize
        dp = [sys.maxsize]*(amount+1)
        dp[0] = 0
                
        for i in range(amount+1):
            for c in coins:
                if c <= i:
                    dp[i] = min(dp[i], dp[i-c] + 1)
   
        return dp[amount] if dp[amount] != sys.maxsize else -1
        
 