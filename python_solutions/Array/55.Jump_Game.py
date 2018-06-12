class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        tempMax = 0
        for i in range(len(nums)):
            if i > tempMax: return False
            if tempMax < i + nums[i]:
                tempMax = max(tempMax, i+nums[i])
        return True            
        