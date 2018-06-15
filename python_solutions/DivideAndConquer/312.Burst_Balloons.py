# recursive solution
class Solution:
    def maxCoins(self, iNums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1]+iNums+[1] 
        n = len(nums)
        memo = [[0]*n for _ in range(n)]
            
        return self.burst(memo, nums, 0, n-1)
    
    def burst(self, memo, nums, left, right):
        if left + 1 == right: return 0
        if memo[left][right] > 0: return memo[left][right]
        
        ans = 0
        for i in range(left+1, right):
            ans = max(ans, nums[left]*nums[i]*nums[right] + \
                     self.burst(memo, nums, left, i) + self.burst(memo, nums, i, right))
        memo[left][right] = ans
        return ans

# dp solution
class Solution:
    def maxCoins(self, iNums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + iNums + [1]
        n = len(nums)
        dp = [[0]*n for _ in range(n)]
        
        for length in range(2, n):
            for left in range(n-length):
                right = left + length
                for i in range(left+1, right):
                    dp[left][right] = max(dp[left][right], nums[left]*nums[i]*nums[right] + \
                                         dp[left][i] + dp[i][right])
        
        return dp[0][n-1]

