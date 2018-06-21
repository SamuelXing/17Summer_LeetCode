class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start, end = 0, len(nums)-1
        while start < end:
            mid = start + (end - start)//2
            
            # make sure get the first element of the sorted array
            if mid % 2 == 1:
                mid -= 1
                
            if nums[mid] != nums[mid+1]:
                end = mid
            else:
                start = mid + 2
        
        return nums[start]