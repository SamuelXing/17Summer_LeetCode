# python one-line slution: tim-sort
class Solution:
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        return sorted(a*x*x + b*x + c for x in nums)

# two-pointer solution
class Solution:
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        nums = [a*x*x + b*x + c for x in nums]
        print(nums)
        
        l, r = 0, len(nums) - 1
        
        idx = len(nums) - 1 if a >= 0 else 0
        
        ret = [0]*len(nums)
        while l <= r:
            if a >= 0:
                if nums[l] >= nums[r]:
                    ret[idx] = nums[l]
                    l += 1  
                else:
                    ret[idx] = nums[r]
                    r -= 1
                idx -= 1
            else:
                if nums[l] >= nums[r]:
                    ret[idx] = nums[r]
                    r -= 1
                else:
                    ret[idx] = nums[l]
                    l += 1
                idx +=1
        
        return ret
      
        