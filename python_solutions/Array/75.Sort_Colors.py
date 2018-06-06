class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) <=1:
            return
        
        lp, rp = 0, len(nums)-1
        idx = 0
        
        while idx <= rp:
            if nums[idx] == 0:
                nums[idx], nums[lp] = nums[lp], nums[idx]
                idx += 1
                lp += 1
            elif nums[idx] == 1:
                idx += 1
            elif nums[idx] == 2:
                nums[idx], nums[rp] = nums[rp], nums[idx]
                rp -= 1
        
        return