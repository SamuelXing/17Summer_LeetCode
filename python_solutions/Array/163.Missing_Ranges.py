# Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

# Example:

# Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
# Output: ["2", "4->49", "51->74", "76->99"]

class Solution:
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        self.ret = []
        if len(nums) == 0:
            self.addRange(lower, upper)
            return self.ret
        
        self.addRange(lower, nums[0]-1)
        
        for i in range(1, len(nums)):
            self.addRange(nums[i-1]+1, nums[i]-1)
        
        self.addRange(nums[-1]+1, upper)
        
        return self.ret
    
    def addRange(self, lo, up):
        if lo > up:
            return
        elif lo == up:
            self.ret.append(str(lo))
        else:
            self.ret.append(str(lo)+'->'+str(up))
        