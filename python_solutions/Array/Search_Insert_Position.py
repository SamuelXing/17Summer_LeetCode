class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        start, end = 0, len(nums)-1
        while start+1 < end:
            mid = start + int((end-start)/2)
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid
            else:
                end = mid
                
        # where to insert
        if nums[start] >= target:
            return start
        if nums[end] >= target:
            return end
        return len(nums)