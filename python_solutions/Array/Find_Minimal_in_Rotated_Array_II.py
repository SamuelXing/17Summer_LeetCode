class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        left, right = 0, len(nums)-1
        
        while left+1 < right:
            mid = int(left+(right-left)/2)
            if nums[mid] < nums[right]:
                right = mid
            elif nums[mid] > nums[right]:
                left = mid
            else:
                right -= 1
        return min(nums[left], nums[right])
        