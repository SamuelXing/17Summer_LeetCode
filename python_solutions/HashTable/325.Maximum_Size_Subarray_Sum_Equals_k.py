class Solution:
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        prefixSum, hashMap, maxLen = 0, {}, 0
        # iterate array, update prefixSum, for each iteration, update two states: 
        # 1, check current (prefixSum - k) is contained, if True, update maxLen
        # 2, add current prefixSum to hash map
 
        for i in range(len(nums)):
            prefixSum += nums[i]
            
            if prefixSum == k:
                maxLen = i+1
            elif (prefixSum - k) in hashMap:
                maxLen = max(maxLen, i-hashMap[prefixSum - k])
            if prefixSum not in hashMap:
                hashMap[prefixSum] = i
        return maxLen