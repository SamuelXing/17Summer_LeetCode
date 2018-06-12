class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        start, end = 0, len(nums)-1
        while start <= end:
            mid = start + (end-start)//2
            if nums[mid] == target:
                return mid
            elif (nums[start] < nums[mid] and target < nums[mid] and target >= nums[start] \
                 or nums[start] > nums[mid] and not (target <= nums[end] and target > nums[mid])):
                end = mid-1
            else:
                start = mid+1
                
        return -1
    