class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None:
            return 0
        maxSum, curSum, minSum = -1-sys.maxsize, 0, 0
        for i in nums:
            curSum += i
            maxSum = max(maxSum, curSum-minSum)
            minSum = min(minSum, curSum)
        
        return maxSum