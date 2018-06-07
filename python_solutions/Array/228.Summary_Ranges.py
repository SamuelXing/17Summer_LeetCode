class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 1:
            return [str(nums[0])]
        
        start, end = 0, 0
        ret = []
        for i in range(1, len(nums)):
            if nums[end] + 1 != nums[i]:
                if start == end:
                    ret.append(str(nums[start]))
                else:
                    ret.append(str(nums[start]) + "->" + str(nums[end]))
                start = end = i
                if i == len(nums) - 1:
                    ret.append(str(nums[start]))
                    
            else:
                end += 1
                if i == len(nums) - 1:
                    ret.append(str(nums[start]) + "->" + str(nums[i]))
  
        return ret