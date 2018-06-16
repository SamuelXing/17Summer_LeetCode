# O(N^2), DP solution
class Solution:
    def lengthOfLIS(self, nums):
        n = len(nums)
        if n <= 1:
            return n
        
        dp = [1]*n
        
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
                    
        return max(dp)

# O(NlogN)
# (1) if x is larger than all tails, append it, increase the size by 1
# (2) if tails[i-1] < x <= tails[i], update tails[i]

class Solution:
    def lengthOfLIS(self, nums):
        LIS, size = [0] * len(nums), 0
        
        for n in nums:
            l, r = 0, size
            while l < r:
                m = (l+r)>>1
                if n > LIS[m]:
                    l = m+1
                else:
                    r = m
            LIS[l] = n
            size = max(l+1, size)
        return size