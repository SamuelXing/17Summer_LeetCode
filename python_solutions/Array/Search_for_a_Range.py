class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = [-1, -1]
        if len(nums) == 0:
            return ret
        
        start, end = 0, len(nums)-1
        while start+1 < end:
            mid = start+int((end-start)/2)
            if nums[mid] >= target:
                end = mid
            else:
                start = mid
                
        if nums[start] == target:
            ret[0] = start
        elif nums[end] == target:
            ret[0] = end
        else:
            return ret
        
        start, end = ret[0], len(nums)-1
        while start+1 < end:
            mid = start+int((end-start)/2)
            if nums[mid] <= target:
                start = mid
            else:
                end = mid
        
        if nums[end] == target:
            ret[1] = end
        elif nums[start] == target:
            ret[1] = start
        else:
            ret[1] = ret[0]
            
        return ret
                
# Notes: run binary search twice
