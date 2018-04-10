class Solution:
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        ret = 0
        if len(nums) == 0:
            return ret
        nums.sort()
        for i in range(len(nums)-2):
            left, right = i+1, len(nums)-1
            while left < right:
                if nums[left] + nums[right] < target - nums[i]:
                    ret += right - left
                    left += 1
                elif nums[left] + nums[right] >= target - nums[i]:
                    right -= 1
        return ret
                    