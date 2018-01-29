class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        length = len(nums)
        ret = []
        for i in range(length-2):
            if i and nums[i] == nums[i-1]:
                continue
            left, right = i+1, length-1
            target = -1*nums[i]
            while left<right:  
                if nums[left]+nums[right] == target:
                    ret.append([nums[i], nums[left], nums[right]])
                    left+=1
                    right-=1
                    while left < right and nums[left] == nums[left - 1]:
                        left+=1
                    while left < right and nums[right] == nums[right+1]:
                        right-=1
                elif nums[left]+nums[right] < target:
                     left+=1
                else:
                     right-=1
        return ret