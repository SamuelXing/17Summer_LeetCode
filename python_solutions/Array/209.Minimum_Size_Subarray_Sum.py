# O(N) solution: two pointers
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        i, j, curMin, curSum = 0, 0, sys.maxsize, 0
        
        while i < len(nums):
            curSum += nums[i]
            i += 1
            
            while curSum >= s:
                curMin = min(curMin, i-j)
                curSum -= nums[j]
                j += 1
        
        return 0 if curMin == sys.maxsize else curMin


# O(NlogN) Solution, One Path, accumulate sum + binary search
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        sums = [0]*(len(nums)+1)
        for i in range(1, len(sums)):
            sums[i] = sums[i-1] + nums[i-1]
        minVal = sys.maxsize
        for i in range(len(sums)):
            end = self.bSearch(i, len(sums)-1, sums[i] + s, sums)
            if end == len(sums): break
            minVal = min(minVal, end - i)
        
        return 0 if minVal == sys.maxsize else minVal
    
    def bSearch(self, lo, hi, key, nums):
        while lo <= hi:
            mid = (lo + hi)//2
            if nums[mid] >= key:
                hi = mid - 1
            else:
                lo = mid + 1
        return lo
        