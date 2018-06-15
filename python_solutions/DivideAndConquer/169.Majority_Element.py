# using majority algorithm
class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        candidates, count = 0, 0 
        for n in nums:
            if count == 0:
                candidates = n
            if candidates == n:
                count += 1
            if candidates != n:
                count -= 1
        
        s = 0
        for n in nums:
            if n == candidates:
                s += 1
        
        if s > (len(nums))//2:
            return candidates

# python one-line
    def majorityElement(self, nums):
        return collections.Counter(nums).most_common(1)[0][0]
            