class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mx, mn = [nums[0]], [nums[0]]
        
        for i in range(1, len(nums)):
            mx.append(max(mx[i-1]*nums[i], mn[i-1]*nums[i], nums[i]))
            mn.append(min(mx[i-1]*nums[i], mn[i-1]*nums[i], nums[i]))
        
        return max(mx)