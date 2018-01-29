class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hsMap = {}
        for i in range(len(nums)):
            if nums[i] in hsMap:
                return [hsMap[nums[i]], i]
            else:
                hsMap[target-nums[i]] = i