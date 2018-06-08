class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        profit, own = 0, -prices[0]
        for i in range(1, len(prices)):
            profit = max(profit, own + prices[i] - fee) #sell-out
            own = max(own, profit - prices[i]) #buy-in
        
        return profit
        