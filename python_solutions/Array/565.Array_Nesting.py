class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        maxSize = 0
        
        for idx in range(len(nums)):
            size, i = 0, idx
            while nums[i] >= 0:
                ii = nums[i]
                nums[i] = -1
                i = ii
                size += 1
            maxSize = max(maxSize, size)
        
        return maxSize
