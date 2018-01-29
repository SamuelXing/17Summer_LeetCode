class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0 or len(nums) == 1:
            return 0
        
        start, end = 0, len(nums)-1
        while start+1<end:
            mid = start + int((end-start)/2)
            if nums[mid] < nums[mid-1]:
                end = mid
            elif nums[mid] < nums[mid+1]:
                start = mid
            else:
                start = mid
                
        if nums[start] < nums[end]:
            return end
        else:
            return start