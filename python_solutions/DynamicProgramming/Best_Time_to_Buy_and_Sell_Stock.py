class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        total, low = 0, sys.maxsize
        for x in prices:
            if x - low > total:
                total = x - low
            if x < low:
                low = x
        return total
