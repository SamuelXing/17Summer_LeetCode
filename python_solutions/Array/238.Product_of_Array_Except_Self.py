class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = [1]
        for i in range(1, len(nums)):
            ret.append(ret[i-1] * nums[i-1])
        
        product = 1
        for i in range(len(nums)-1, -1, -1):
            ret[i] *= product
            product *= nums[i]
            
        return ret
        