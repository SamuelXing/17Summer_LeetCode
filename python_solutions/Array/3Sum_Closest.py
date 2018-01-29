class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()    
        curMin = sys.maxsize
        for i in range(len(nums)):
            if i and nums[i] == nums[i-1]:
                continue
            left, right = i+1, len(nums)-1
            while left < right:
                curSum = nums[i]+nums[left]+nums[right]
                if abs(curSum - target) < abs(curMin - target):
                    curMin = curSum   
                elif curSum <= target:
                    left += 1
                else:
                    right -= 1
        return curMin