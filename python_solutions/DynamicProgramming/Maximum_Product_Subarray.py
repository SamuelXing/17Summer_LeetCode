class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None:
            return 0
        
        maxP, minP, ret = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            tmp = maxP
            maxP = max(max(maxP*nums[i], nums[i]), minP*nums[i])
            minP = min(min(tmp*nums[i], nums[i]), minP*nums[i])
            ret = max(ret, maxP)
        return ret