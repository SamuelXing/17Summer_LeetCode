class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count, curSum = 0, 0 
        hashMap = {}
        hashMap[0] = 1
        for num in nums:
            curSum += num
            if curSum - k in hashMap:
                count += hashMap[curSum-k]
            hashMap[curSum] = hashMap[curSum] + 1 if curSum in hashMap else 1
        return count