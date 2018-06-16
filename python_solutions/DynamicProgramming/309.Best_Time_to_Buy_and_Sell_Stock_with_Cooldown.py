# thinking process:

'''
 The key for dp is to find the variables to represent the states and deduce the transition function.
 
 Three states in this states: buy, sell, cooldown
 buy[i]: the maximum profit for any sequence ends with buy before ith day 
 sell[i]: the maximum profit for any sequence ends with sell before ith day 
 cooldown[i]: the maximum profit for any sequence ends with rest before ith day 

 #1, solution
 buy[i] = max(rest[i-1]-prices, buy[i-1])
 sell[i] = max(buy[i-1]+prices, sell[i-1])
 cooldown = max(sell[i-1], buy[i-1], rest[i-1]) ??

 #2, furthure observation
 rest[i] = sell[i-1]

====》

 buy[i] = max(sell[i-2]-price, buy[i-1])
 sell[i] = max(buy[i-1]+price, sell[i-1])

'''
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        buy = [0]*len(prices)
        sell = [0]*len(prices)
        
        buy[0] = -prices[0]
        
        for i in range(1, len(prices)):
            buy[i] = max(sell[i-2]-prices[i], buy[i-1]) if i-2 >= 0 else max(buy[i-1], -prices[i])
            sell[i] = max(buy[i-1]+prices[i], sell[i-1])
        
        return sell[len(prices)-1]


'''
# Optimized Solution with O(1) Space
'''
class Solution:
    def maxProfit(self, prices):
        if len(prices) < 2:
            return 0
        sell, buy, prev_sell, prev_buy = 0, -prices[0], 0, 0
        for price in prices:
            prev_buy = buy
            buy = max(prev_sell - price, prev_buy)
            prev_sell = sell
            sell = max(prev_buy + price, prev_sell)
        return sell




