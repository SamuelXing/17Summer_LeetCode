class Solution:
    # two-pointers
    def twoSum(self, nums, target):
        l, r = 0, len(nums)-1
        
        while l <= r:
            if nums[l] + nums[r] > target:
                r -= 1
            elif nums[l] + nums[r] < target:
                l += 1
            else:
                return [l+1, r+1]

    # hash map
    def twoSum(self, nums, target):
        hashMap = {}
        for i in range(len(nums)):
            if (target - nums[i]) in hashMap:
                return [hashMap[target - nums[i]]+1, i+1]
            else:
                hashMap[nums[i]] = i

    # binary search
    def twoSum(self, nums, target):
        for i in range(len(nums) - 1):
            l, r = i+1, len(nums) - 1
            while l <= r:
                m = (l+r)//2
                if nums[m] == target - nums[i]:
                    return [i+1, m+1]
                elif nums[m] < target - nums[i]:
                    l = m + 1
                else:
                    r = m - 1