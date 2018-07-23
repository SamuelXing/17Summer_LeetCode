class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        if k > len(prices)//2:
            return self.quickSolve(prices)
        
        buy = [prices[0]]*(k+1)
        sell = [0]*(k+1)
        
        for p in prices:
            for i in range(1, k+1):
                buy[i] = min(buy[i], p-sell[i-1])
                sell[i] = max(sell[i], p-buy[i])
        
        return sell[k]
    
    def quickSolve(self, prices):
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
                
        return profit
            